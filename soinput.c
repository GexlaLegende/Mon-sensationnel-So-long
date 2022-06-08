/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soinput.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apercebo <apercebo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 14:42:20 by apercebo          #+#    #+#             */
/*   Updated: 2022/03/18 17:19:53 by apercebo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	keyjuusan(t_data *data, int i, int j)
{
	if (data->map[j - 1][i] == 'E')
	{
		if (data->collec == 0)
			destroy(data, 0);
		else
			return (1);
	}
	if (data->map[j - 1][i] == 'C')
		data->collec -= 1;
	if (data->map[j - 1][i] != '1')
	{
		data->map[j - 1][i] = 'P';
		data->map[j][i] = '0';
		data->mouvement += 1;
		ft_printf("%d\n", data->mouvement);
	}
	return (0);
}

int	keyzero(t_data *data, int i, int j)
{
	if (data->map[j][i - 1] == 'E')
	{
		if (data->collec == 0)
			destroy(data, 0);
		else
			return (1);
	}
	if (data->map[j][i - 1] == 'C')
		data->collec -= 1;
	if (data->map[j][i - 1] != '1')
	{
		data->map[j][i - 1] = 'P';
		data->map[j][i] = '0';
		data->mouvement += 1;
		ft_printf("%d\n", data->mouvement);
	}
	return (0);
}

int	keyichi(t_data *data, int i, int j)
{
	if (data->map[j + 1][i] == 'E')
	{
		if (data->collec == 0)
			destroy(data, 0);
		else
			return (1);
	}
	if (data->map[j + 1][i] == 'C')
		data->collec -= 1;
	if (data->map[j + 1][i] != '1')
	{
		data->map[j + 1][i] = 'P';
		data->map[j][i] = '0';
		data->mouvement += 1;
		ft_printf("%d\n", data->mouvement);
	}
	return (0);
}

int	keyall(t_data *data, int key, int i, int j)
{
	if (key == 13)
		if (keyjuusan(data, i, j) == 1)
			return (1);
	if (key == 0)
		if (keyzero(data, i, j) == 1)
			return (1);
	if (key == 1)
		if (keyichi(data, i, j) == 1)
			return (1);
	if (key == 2)
		if (keyni(data, i, j) == 1)
			return (1);
	if (key == 53)
		destroy(data, 0);
	return (1);
}

int	input(int key, t_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i])
		{
			if (data->map[j][i] == 'P')
				break ;
			i++;
		}
		if (data->map[j][i] == 'P')
			break ;
		j++;
	}
	keyall(data, key, i, j);
	display(data);
	return (1);
}
