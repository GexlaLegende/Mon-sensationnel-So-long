/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soutils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apercebo <apercebo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:16:17 by apercebo          #+#    #+#             */
/*   Updated: 2022/03/26 19:51:46 by apercebo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	keyni(t_data *data, int i, int j)
{
	if (data->map[j][i + 1] == 'E')
	{
		if (data->collec == 0)
			destroy(data, 0);
		else
			return (1);
	}
	if (data->map[j][i + 1] == 'C')
		data->collec -= 1;
	if (data->map[j][i + 1] != '1')
	{
		data->map[j][i + 1] = 'P';
		data->map[j][i] = '0';
		data->mouvement += 1;
		ft_printf("%d\n", data->mouvement);
	}
	return (0);
}

void	destroy(t_data *data, int ernbr)
{
	int	j;

	j = 0;
	while (j < (data->height - 1) && ernbr != 2)
	{
		free(data->map[j]);
		j++;
	}
	if (ernbr != 2)
		free(data->map);
	if (ernbr == 1)
	{
		ft_printf("%s\n%s\n", "Error", "The map is not conform");
		exit(0);
	}
	if (ernbr != 2)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit(0);
}

int	wallclose(t_data *data)
{
	int	i;

	i = 0;
	while (i < (data->width))
		if (data->map[0][i++] != '1')
			return (1);
	i = 0;
	while (i < (data->height))
		if (data->map[i++][0] != '1')
			return (1);
	i = 0;
	while (i < (data->width))
		if (data->map[data->height - 1][i++] != '1')
			return (1);
	i = 0;
	while (i < (data->height))
		if (data->map[i++][data->width - 1] != '1')
			return (1);
	return (0);
}

void	mapping(t_data *data, char *maplink)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(maplink, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("%s\n%s\n", "Error", "The map does not exist");
		exit(0);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		i++;
		free(line);
	}
	free(line);
	mappingtwo(data, fd, i, maplink);
}

void	mappingtwo(t_data *data, int fd, int i, char *maplink)
{
	data->height = i;
	data->map = malloc(sizeof(char *) * (i + 1));
	if (!data->map)
	{
		ft_printf("%s\n%s\n", "Error", "Malloc error");
		exit(0);
	}
	close(fd);
	fd = open(maplink, O_RDONLY);
	i = 0;
	while (1)
	{
		data->map[i] = get_next_line(fd);
		if (data->map[i] == NULL)
			break ;
		i++;
	}
	data->width = (ft_strlen(data->map[0]) - 1);
	checklimits(data);
	if (wallclose(data) == 1)
		destroy(data, 1);
}
