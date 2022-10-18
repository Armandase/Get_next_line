/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamiens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:25:54 by adamiens          #+#    #+#             */
/*   Updated: 2022/10/18 11:39:05 by adamiens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

char *get_next_line(int fd);
char    *ft_strjoin(char *s1, char *s2);
char    *ft_strndup(char *s, int len);
void	ft_substr(char *s);
size_t  ft_strlen(char  *str);
void    *ft_calloc(size_t nmemb, size_t size);

#endif
