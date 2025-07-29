/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 01:42:52 by milferna          #+#    #+#             */
/*   Updated: 2025/07/29 04:32:52 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char    *extract_line(char **stash)
{
    char    *line;
    char    *newline_ptr;
    size_t  line_len;
    size_t  i;

    line_len = 0;
    if(!stash || *stash == (void *)0)
        return (NULL);
    newline_ptr = ft_strchr(*stash, '\n');
    if (newline_ptr)
        line_len = newline_ptr - *stash;
    else
        line_len = ft_strlen(*stash);
    line = ft_calloc(line_len + 2, sizeof(char));
    i = 0;
    while (i < line_len)
        line[i] = (*stash)[i], i++;
    if ((*stash)[i] == '\n')
        line[i] = (*stash)[i], i++;
    line[i] = '\0';
    clean_stash(stash, newline_ptr);
    return (line);
}

void    clean_stash(char **stash, char *newline_ptr)
{
    char *new_stash;
    
    if (newline_ptr)
    {
        new_stash = ft_strdup(++newline_ptr);
        free(*stash);
        *stash = new_stash;
    }
    else
    {
        free(*stash);
        *stash = NULL;
    }
}

char    *read_line(int fd, char *stash)
{
    ssize_t bytes_read;
    char    *buffer;
    
    
    buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
    bytes_read = 1;
    
    // printf("\033[33mTest: %s\033[0m", test);
    // printf("\033[33mStash: %s\033[0m", stash);
    while (!(ft_strchr(stash, '\n')) && bytes_read > 0)
    {
        //printf("\033[33mHOLA\033[0m");
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read == -1)
        {
            free(stash);
            free(buffer);
            return (NULL);
        }
        buffer[bytes_read] = '\0';
        stash = ft_strjoin(stash, buffer);
        // printf("\033[33mStash: %s, Len: %d\033[0m", stash, ft_strlen(stash));
        // printf("\033[33mTest: %s\033[0m", test);
    }
    free(buffer);
    return (stash);
}

char    *get_next_line(int fd)
{
    static char *stash;
    char    *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return(NULL);
    if (!stash)
        stash = ft_calloc(1, 1); //solo para el \0
    stash = read_line(fd, stash);
    if (!stash)
        return (NULL);
    if (stash[0] == '\0')
    {
        free(stash);
        stash = NULL;
        return (NULL);
    }
    line = extract_line(&stash);
    return(line);
}

// int main()
// {
//     int fd;
//     fd = open("get_next_line.h", O_RDONLY); //abrimos el archivo en modo lectura
//     char    *line = get_next_line(fd);


// /*  printf("%s", line);
//  line = get_next_line(fd);
// printf("%s", line);
// line = get_next_line(fd);
// printf("%s", line); */

// // while (line && line[0] != 0)
// while (line)
// {
//     printf("%s", line);
//     free(line);
//     line = get_next_line(fd);
// }
// //comprobacion de que hace lo mismo que el original
//     // while(line = getline(fd) != NULL)
//     // {
//     //     printf("Linea: %s\n", line);
//     //     free(line);
//     // }

//     close(fd);
//     return 0;
// }

