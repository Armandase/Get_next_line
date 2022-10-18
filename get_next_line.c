/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamiens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 10:13:37 by adamiens          #+#    #+#             */
/*   Updated: 2022/10/18 16:52:38 by adamiens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_checkline(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static int	i;
	static char	buffer[BUFFER_SIZE + 1];
	char		*ret;

	ret = NULL;
	if (!*buffer)
	{	
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1 || i == 0)
			return (NULL);
		buffer[i] = '\0';
	}
	ret = ft_strjoin(ret, buffer);
	while (!ft_checkline(ret))
	{
		if (i == 0 && buffer[0])
		{
			free(ret);
			return (NULL);
		}
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1 || i == 0)
			break ;
		buffer[i] = '\0';
		ret = ft_strjoin(ret, buffer);
	}
	ft_substr(buffer);
	return (ret);
}
