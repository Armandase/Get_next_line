/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamiens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 18:03:12 by adamiens          #+#    #+#             */
/*   Updated: 2022/10/10 13:21:21 by adamiens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *ft_strndup(char *s, int len)
{
    int     size;
    char    *str;

    size = 0;
    if (s)
		while (s[size] != '\0' && size < len)
        	size++;
    str = (char *) malloc(sizeof(char) * size + 1);
    if (!str)
        return (NULL);
    size = 0;
    while (s[size] != '\0' && size < len)
    {
        str[size] = s[size];
        size++;
    }
    str[size] = '\0';
    return (str);
}

static int  ft_strdoublelen(char *s1, char *s2)
{
    int     i;
    int     j;

    i = 0;
    j = 0;
    if (s1)
		while (s1[i])
        	i++;
    while (s2[j])
    {
        j++;
        i++;
    }
    return (i);
}

char    *ft_strjoin(char *s1, char *s2)
{
    char    *str;
    int     i;
    int     j;

    if (!s2)
        return (0);
    i = ft_strdoublelen(s1, s2);
    str = malloc (i + 1);
    if (!str)
        return (0);
    i = 0;
    j = 0;
	if (s1)
 	   while (s1[j])
    	    str[i++] = s1[j++];
    j = 0;
    while (s2[j])
	{
        str[i] = s2[j];
		i++;
		j++;
	}
	free(s1);
	str[i] = '\0';
    return (str);
}

size_t	ft_strlen(char	*str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char    *ft_substr(char *s, int lens, int start, int len)
{
    char    *str;
    int  i;

    if (!len || !s)
        return (0);
    if (start >= lens)
        return (0);
    while (len - start > lens)
        len--;
    if (len + start > lens)
        len = lens - start;
    i = 0;
    str = malloc(sizeof(char) * len + 1);
    if (!str)
        return (NULL);
    while (i < len && s[start])
    {
        str[i] = s[start++];
        i++;
    }
    str[i] = '\0';
    return (str);
}
