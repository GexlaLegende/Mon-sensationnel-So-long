/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apercebo <apercebo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 14:24:41 by apercebo          #+#    #+#             */
/*   Updated: 2022/03/27 17:28:49 by apercebo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	display2(t_data *data, int i, int j)
{
	if (data->map[j][i] == 'E')
		mlx_put_image_to_window (data->mlx_ptr, data->win_ptr,
			data->img_ptr[3], (i * 63), (j * 63));
	if (data->map[j][i] == 'P')
		mlx_put_image_to_window (data->mlx_ptr, data->win_ptr,
			data->img_ptr[4], (i * 63), (j * 63));
}

void	display(t_data *data)
{
	int		i;
	int		j;

	j = 0;
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i] != '\0')
		{
			if (data->map[j][i] == '1')
				mlx_put_image_to_window (data->mlx_ptr, data->win_ptr,
					data->img_ptr[0], (i * 63), (j * 63));
			if (data->map[j][i] == '0')
				mlx_put_image_to_window (data->mlx_ptr, data->win_ptr,
					data->img_ptr[1], (i * 63), (j * 63));
			if (data->map[j][i] == 'C')
				mlx_put_image_to_window (data->mlx_ptr, data->win_ptr,
					data->img_ptr[2], (i * 63), (j * 63));
			if (data->map[j][i] == 'E' || data->map[j][i] == 'P')
				display2(data, i, j);
			i++;
		}
		j++;
	}
}

void	getimage(t_data *data)
{
	data->img_ptr = (void **)malloc(sizeof(void **) * 6);
	if (!data->img_ptr)
	{
		ft_printf("%s\n%s\n", "Error", "Malloc error");
		exit(0);
	}
	data->img_ptr[0] = mlx_xpm_file_to_image (data->mlx_ptr,
			"xpm/bloc64.xpm", &data->imwidth, &data->imheight);
	data->img_ptr[1] = mlx_xpm_file_to_image (data->mlx_ptr,
			"xpm/ground64.xpm", &data->imwidth, &data->imheight);
	data->img_ptr[2] = mlx_xpm_file_to_image (data->mlx_ptr,
			"xpm/github64.xpm", &data->imwidth, &data->imheight);
	data->img_ptr[3] = mlx_xpm_file_to_image (data->mlx_ptr,
			"xpm/success64.xpm", &data->imwidth, &data->imheight);
	data->img_ptr[4] = mlx_xpm_file_to_image (data->mlx_ptr,
			"xpm/cynthia64.xpm", &data->imwidth, &data->imheight);
}

void	errorber(char *maplink)
{
	int	i;

	i = ft_strlen(maplink);
	if (maplink[i - 1] != 'r' || maplink[i - 2] != 'e' || maplink[i - 3]
		!= 'b' || maplink[i - 4] != '.')
	{
		ft_printf("%s\n%s\n", "Error", "The map is not a .ber");
		exit(0);
	}			
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (0);
	errorber(argv[1]);
	data.end = 0;
	data.player = 0;
	data.pexit = 0;
	data.mouvement = 0;
	data.collec = 0;
	mapping(&data, argv[1]);
	nbrcollec(&data, data.a, data.b);
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, (data.width * 63),
			(data.height * 63), "mlx_42");
	getimage(&data);
	display(&data);
	mlx_key_hook(data.win_ptr, input, &data);
	mlx_hook(data.win_ptr, 17, 1L << 0, closed, &data);
	mlx_loop(data.mlx_ptr);
}

//a faire taille map dans data;
//-fsanitize=address -g3
