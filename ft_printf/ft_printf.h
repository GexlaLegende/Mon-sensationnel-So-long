/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apercebo <apercebo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:41:26 by apercebo          #+#    #+#             */
/*   Updated: 2022/01/12 09:16:58 by apercebo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int		ft_printf(const char *s, ...);
void	ft_putstr(char *s, int *j);
void	ft_putnbr(int n, int *j);
void	ft_putnbrunsign(unsigned int n, int *j);
void	ft_putnbrhexa(unsigned int n, int *j, int x);
void	ft_putaddress(unsigned long long int n, int *j);
char	*ft_strchr(const char *s, int c);

#endif