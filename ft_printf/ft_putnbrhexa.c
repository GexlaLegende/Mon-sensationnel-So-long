/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrhexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apercebo <apercebo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:10:20 by apercebo          #+#    #+#             */
/*   Updated: 2021/12/06 16:07:36 by apercebo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbrhexa(unsigned int n, int *j, int x)
{
	unsigned int	nbr;
	char			*hexa;

	nbr = n;
	if (x == 1)
		hexa = "0123456789abcdef";
	else
		hexa = "0123456789ABCDEF";
	if (nbr > 15 && x == 1)
		ft_putnbrhexa(nbr / 16, j, 1);
	else if (nbr > 15)
		ft_putnbrhexa(nbr / 16, j, 2);
	nbr = (nbr % 16);
	*j = *j + 1;
	write(1, &hexa[nbr], 1);
}
