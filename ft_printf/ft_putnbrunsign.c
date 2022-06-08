/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrunsign.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apercebo <apercebo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:58:56 by apercebo          #+#    #+#             */
/*   Updated: 2021/12/06 16:07:38 by apercebo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbrunsign(unsigned int n, int *j)
{
	unsigned int	nbr;

	nbr = n;
	if (nbr > 9)
		ft_putnbrunsign(nbr / 10, j);
	nbr = (nbr % 10) + 48;
	*j = *j + 1;
	write(1, &nbr, 1);
}
