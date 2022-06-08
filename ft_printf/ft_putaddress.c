/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apercebo <apercebo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 10:35:30 by apercebo          #+#    #+#             */
/*   Updated: 2021/12/06 16:07:31 by apercebo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putaddress(unsigned long long int n, int *j)
{
	unsigned long long int	nbr;
	char					*hexa;

	nbr = n;
	hexa = "0123456789abcdef";
	if (nbr > 15)
		ft_putaddress(nbr / 16, j);
	nbr = (nbr % 16);
	*j = *j + 1;
	write(1, &hexa[nbr], 1);
}
