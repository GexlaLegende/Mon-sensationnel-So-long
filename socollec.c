/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   socollec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apercebo <apercebo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 19:09:17 by apercebo          #+#    #+#             */
/*   Updated: 2022/03/27 17:53:07 by apercebo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	closed(int keycode, t_data *data)
{
	keycode = 1;
	destroy(data, 2);
	return (1);
}

void	nbrcollec(t_data *data, int i, int j)
{
	j = 0;
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i + 1])
		{
			if (data->map[j][i] == 'C')
				data->collec += 1;
			if (data->map[j][i] == 'E')
				data->pexit += 1;
			if (data->map[j][i] == 'P')
			{
				data->player += 1;
				if (data->player > 1)
					data->map[j][i] = '0';
			}
			if (data->map[j][i] != 'C' && data->map[j][i] != 'P'
					&& data->map[j][i] != 'E' && data->map[j][i] != '1'
					&& data->map[j][i] != '0' && data->map[j][i])
				destroy(data, 1);
			i++;
		}
		j++;
	}
	nbrother(data);
}

void	nbrother(t_data *data)
{
	if (data->collec < 1 || data->pexit < 1 || data->player < 1)
		destroy(data, 1);
}

void	checklimits(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		if (data->map[i][data->width] && data->map[i][data->width] != '\n')
			destroy(data, 1);
		i++;
	}
}
