/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apercebo <apercebo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:35:24 by apercebo          #+#    #+#             */
/*   Updated: 2021/12/07 16:50:28 by apercebo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printfuxp(va_list av, const char *str, int i, int *j)
{
	unsigned int			u;
	unsigned long long int	p;

	if (str[i] == 'u')
	{
		u = (unsigned int)va_arg(av, unsigned int);
		ft_putnbrunsign(u, j);
	}
	else if (str[i] == 'x')
	{
		u = (unsigned int)va_arg(av, unsigned int);
		ft_putnbrhexa(u, j, 1);
	}
	else if (str[i] == 'X')
	{
		u = (unsigned int)va_arg(av, unsigned int);
		ft_putnbrhexa(u, j, 2);
	}
	else if (str[i] == 'p')
	{
		p = (unsigned long long int)va_arg(av, unsigned long long int);
		*j = *j + 2;
		write(1, "0x", 2);
		ft_putaddress(p, j);
	}
}

void	printfcsdi(va_list av, const char *str, int i, int *j)
{
	char			c;
	char			*s;
	int				d;

	if (str[i] == 'c')
	{
		c = (char)va_arg(av, int);
		write(1, &c, 1);
		*j = *j + 1;
	}
	else if (str[i] == 's')
	{
		s = va_arg(av, char *);
		ft_putstr(s, j);
	}
	else if (str[i] == 'd' || str[i] == 'i')
	{
		d = va_arg(av, int);
		ft_putnbr(d, j);
	}
	else
		printfuxp(av, str, i, j);
	*j = *j - 1;
}

int	ft_printf(const char *s, ...)
{
	va_list	av;
	int		i;
	int		j;

	i = -1;
	j = 0;
	va_start(av, s);
	while (s[++i])
	{
		if (s[i] != '%')
			write(1, &s[i], 1);
		else if (s[i] == '%' && s[i + 1] && ft_strchr("csdiuxXp%", s[i + 1]))
		{
			if (s[++i] == '%')
				write(1, "%", 1);
			else if (s[i] == 'c' || s[i] == 's' || s[i] == 'd' || s[i] == 'i'
				|| s[i] == 'u' || s[i] == 'x' || s[i] == 'X' || s[i] == 'p')
				printfcsdi(av, s, i, &j);
			j--;
		}
		else
			j--;
	}
	va_end(av);
	return (i + j);
}
