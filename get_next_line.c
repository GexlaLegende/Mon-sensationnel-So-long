/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apercebo <apercebo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:34:08 by apercebo          #+#    #+#             */
/*   Updated: 2022/03/14 16:11:57 by apercebo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

char	*ft_readandstock(char *stock, int fd)
{
	char	*buff;
	int		i;

	i = 1;
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	while (!ft_strchrg(stock, '\n') && i != 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i < 0)
		{
			free(buff);
			return (NULL);
		}
		buff[i] = '\0';
		stock = ft_strmjoin(stock, buff);
	}
	free(buff);
	return (stock);
}

char	*ft_getline(char *stock)
{
	char	*line;
	int		i;

	i = 0;
	if (!stock[i])
		return (NULL);
	while (stock[i] && stock[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (stock[i] && stock[i] != '\n')
	{
		line[i] = stock[i];
		i++;
	}
	if (stock[i] == '\n')
	{
		line[i] = stock[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_delstock(char *stock)
{
	char	*s;
	int		i;
	int		j;

	i = 0;
	while (stock[i] && stock[i] != '\n')
		i++;
	if (!stock[i])
	{
		free(stock);
		return (NULL);
	}
	s = (char *)malloc(sizeof(char) * (ft_strlen(stock) - i + 1));
	if (!s)
	{
		free(stock);
		return (NULL);
	}
	i++;
	j = 0;
	while (stock[i])
		s[j++] = stock[i++];
	s[j] = '\0';
	free(stock);
	return (s);
}

char	*get_next_line(int fd)
{
	static char		*stock;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	stock = ft_readandstock(stock, fd);
	if (!stock)
		return (NULL);
	line = ft_getline(stock);
	stock = ft_delstock(stock);
	return (line);
}
