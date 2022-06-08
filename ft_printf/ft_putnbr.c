/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apercebo <apercebo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:48:39 by apercebo          #+#    #+#             */
/*   Updated: 2021/12/06 16:07:34 by apercebo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int *j)
{
	long int	nbr;

	nbr = n;
	if (nbr < 0)
	{
		nbr = nbr * -1;
		write(1, "-", 1);
		*j = *j + 1;
	}
	if (nbr > 9)
		ft_putnbr(nbr / 10, j);
	nbr = (nbr % 10) + 48;
	*j = *j + 1;
	write(1, &nbr, 1);
}
