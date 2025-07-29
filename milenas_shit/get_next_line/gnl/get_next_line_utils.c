/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milferna <milferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 01:39:59 by milferna          #+#    #+#             */
/*   Updated: 2025/07/28 23:17:45 by milferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i ++;
	return (i);
}

char	*ft_strchr(char *string, int c)
{
	size_t	i;
	char	letter;

	i = 0;
	letter = (char)c;
	while (string[i] != '\0')
	{
		if (string[i] == letter)
			return ((char *)&string[i]);
		i ++;
	}
	if (letter == '\0')
		return ((char *)&string[i]);
	return (NULL);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*hola;
	char	*p;
	size_t num;

	hola = malloc (nmemb * size);
	if (!hola)
		return (NULL);
	//lo siguiente es el ft_bzero
	p = hola;
	num = nmemb * size;
	while (num--)
		*p++ = '\0';
	return (hola);
}

char	*ft_strdup(char *s)
{
	size_t		i;
	char		*hello;

	i = 0;
	hello = malloc(ft_strlen(s) + 1);
	if (!hello)
		return (NULL);
	while (s[i] != '\0')
	{
		hello[i] = s[i];
		i ++;
	}
	hello[i] = '\0';
	return (hello);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*strjoin;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	strjoin = ft_calloc (sizeof(char), ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!strjoin)
		return (NULL);
	while (s1[i] != '\0')
	{
		strjoin[i] = s1[i];
		i ++;
	}
	while (s2[j] != '\0')
	{
		strjoin[i + j] = s2[j];
		j ++;
	}
	strjoin[i + j] = '\0';
	free(s1);
	return (strjoin);
}
