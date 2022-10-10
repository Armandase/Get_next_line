/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamiens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 10:13:37 by adamiens          #+#    #+#             */
/*   Updated: 2022/10/10 13:28:07 by adamiens         ###   ########.fr       */
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

static int	ft_strpimplen(char	*str)
{
	int	i;

	i = 0;
	while(str[i] != '\n' && str[i] != '\0')
		i++;
	return (i + 1);
}

char *get_next_line(int fd)
{
	int	i;
	char	buffer[BUFFER_SIZE + 1];
	static	char	*save;
	char	*ret;

	i = read(fd, buffer, BUFFER_SIZE);
	if (i == -1)
		return (NULL);
	buffer[i] = '\0';
	save = ft_strjoin(save, buffer);
	while(!ft_checkline(save))
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1 || i == 0)
			return (NULL);
		buffer[i] = '\0';
		save = ft_strjoin(save, buffer);
	}
	ret = ft_strndup(save, ft_strpimplen(save));
	i = ft_strlen(save); 
	save = ft_substr(save, i, ft_strpimplen(save), i - ft_strpimplen(save));
	return (ret);
}/*
#include <stdio.h>
int main ()
{
    int fd;
    fd = open("42", O_RDONLY);
    if (fd == -1)
    {
        printf("open error");
        return (1);
    }
    int i = 0; 
	char *str;
    while (i < 7)
    {
        printf("Call %d:\n", i + 1);
		str = get_next_line(fd);
        printf("%s", str);
		free(str);
		printf("---------\n");
        i++;
    }
	free(str);
    if (close(fd) == -1)
    {
        printf("close error");
        return (1);
    }
    return (0);
}*/	
