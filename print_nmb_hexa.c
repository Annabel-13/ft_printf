/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nmb_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboichuk <hboichuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 21:12:14 by hboichuk          #+#    #+#             */
/*   Updated: 2022/07/04 20:00:10 by hboichuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base_ul(unsigned long n, char *base, int *buffer)
{
	unsigned long	i;

	i = 0;
	while (base[i])
		i++;
	if (n > i - 1)
	{
		ft_putnbr_base_ul(n / i, base, buffer);
		n %= i;
	}
	*buffer += ft_putchar(base[n]);
}

void	ft_putnbr_base_u(unsigned int n, char *base, int *buffer)
{
	unsigned int	i;

	i = 0;
	while (base[i])
		i++;
	if (n > i - 1)
	{
		ft_putnbr_base_ul(n / i, base, buffer);
		n %= i;
	}
	*buffer += ft_putchar(base[n]);
}

void	print_nmb_hexa(va_list arg, char c, int *buffer)
{
	unsigned long	num;

	num = va_arg(arg, unsigned long);
	if (c == 'X')
		ft_putnbr_base_u(num, "0123456789ABCDEF", buffer);
	else
		ft_putnbr_base_u(num, "0123456789abcdef", buffer);
}
