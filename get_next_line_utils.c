/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamiens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 18:03:12 by adamiens          #+#    #+#             */
/*   Updated: 2022/10/23 10:01:41 by adamiens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_strdoublelen(char *ret, char *buffer)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ret)
		while (ret[i])
			i++;
	while (buffer[j])
	{
		j++;
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *ret, char *buffer)
{
	char	*str;
	int		i;
	int		j;

	if (!buffer)
		return (0);
	i = ft_strdoublelen(ret, buffer);
	str = ft_calloc(i + 1, sizeof(char));
	if (!str)
		return (0);
	i = 0;
	j = 0;
	if (ret)
		while (ret[j])
			str[i++] = ret[j++];
	free(ret);
	ft_nlcpy(buffer, str, i);
	return (str);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (i);
	else if (*str == '\0')
		return (i);
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_substr(char *s)
{
	int	i;
	int	j;

	if (!s)
		return ;
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			break ;
		i++;
	}
	if (!s[i])
		return ;
	i++;
	while (s[i])
	{
		s[j] = s[i];
		j++;
		i++;
	}
	s[j] = '\0';
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ret;
	size_t	i;

	i = 0;
	if (!nmemb || !size)
		return (malloc(1));
	if (size * nmemb / nmemb != size)
		return (NULL);
	ret = malloc(nmemb * size);
	if (!ret)
		return (NULL);
	while (i < nmemb)
		ret[i++] = '\0';
	return ((void *)ret);
}
