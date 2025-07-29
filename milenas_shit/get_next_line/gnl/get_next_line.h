/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milferna <milferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 02:02:54 by milferna          #+#    #+#             */
/*   Updated: 2025/07/28 23:39:08 by milferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEX_LINE_H
# define GET_NEX_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
// #include <iostream.h>
#include <stdlib.h>

int     ft_strlen(char *str);
char	*ft_strchr(char *string, int c);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2);
char    *extract_line(char **stash);
void    clean_stash(char **stash, char *newline_ptr);
char    *get_next_line(int fd);


#endif


