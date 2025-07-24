/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milferna <milferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 01:42:52 by milferna          #+#    #+#             */
/*   Updated: 2025/07/24 20:59:45 by milferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char    *extract_line(char **stash)
{
    char    *line;
    char    *newline_ptr;
    size_t  line_len;
    size_t  i;

    if(!stash || *stash == (void *)0)
        return (NULL);
    newline_ptr = ft_strchr(*stash, '\n');
    line_len = 0;
    if (newline_ptr)
        line_len = newline_ptr - *stash + 1;
    else
        line_len = ft_strlen(*stash);
    line = ft_calloc(line_len + 1, sizeof(char));
    i = 0;
    while (i < line_len)
    {
        line[i] = (*stash)[i];
        i ++;
    }
    clean_stash(stash, newline_ptr);
    return (line);
}

void    clean_stash(char **stash, char *newline_ptr)
{
    char *new_stash;
    
    if (newline_ptr)
    {
        new_stash = ft_strdup(newline_ptr + 1);
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
    while (!ft_strchr(stash, '\n') && bytes_read != 0)
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read == -1)
            return (NULL);
        buffer[bytes_read] = '\0';
        stash = ft_strjoin(stash, buffer);
    }
    return (stash);
}

char    *get_next_line(int fd)
{
    static char *stash;
    char    *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return(NULL);
    if (!stash)
        stash = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
    stash = read_line(fd, stash);
    line = extract_line(&stash);
    return(line);
}

int main()
{
    int fd;
    fd = open("get_next_line.h", O_RDONLY); //abrimos el archivo en modo lectura
    char    *line = get_next_line(fd);


while (line)
{
    printf("%s\n", line);
    free(line);
    line = get_next_line(fd);
}
//comprobacion de que hace lo mismo que el original
    // while(line = getline(fd) != NULL)
    // {
    //     printf("Linea: %s\n", line);
    //     free(line);
    // }

    close(fd);
    return 0;
}