/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apercebo <apercebo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:11:28 by apercebo          #+#    #+#             */
/*   Updated: 2022/03/27 17:31:45 by apercebo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H
# define BUFFER_SIZE 42

# include "minilibx/mlx.h"
# include "ft_printf/ft_printf.h"
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
	void	**img_ptr;
	int		width;
	int		height;
	int		imwidth;
	int		imheight;
	int		end;
	int		mouvement;
	int		collec;
	int		player;
	int		pexit;
	int		a;
	int		b;
}		t_data;

char	*ft_strmjoin(char *s1, char *s2);
char	*ft_strchrg(char *str, int c);
size_t	ft_strlen(char *str);
char	*get_next_line(int fd);
void	display(t_data *data);
int		input(int key, t_data *data);
void	destroy(t_data *data, int ernbr);
int		keyni(t_data *data, int i, int j);
int		wallclose(t_data *data);
void	mapping(t_data *data, char *maplink);
void	mappingtwo(t_data *data, int fd, int i, char *maplink);
void	nbrcollec(t_data *data, int i, int j);
int		closed(int keycode, t_data *data);
void	nbrother(t_data *data);
void	checklimits(t_data *data);

#endif