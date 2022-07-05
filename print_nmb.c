/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nmb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboichuk <hboichuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 21:53:32 by hboichuk          #+#    #+#             */
/*   Updated: 2022/06/28 17:44:09 by hboichuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int *buffer)
{
	unsigned int	number;

	if (n < 0)
	{
		*buffer += ft_putchar('-');
		number = -n;
	}
	else
		number = n;
	if (number > 9)
	{
		ft_putnbr(number / 10, buffer);
		number %= 10;
	}
	*buffer += ft_putchar(number + '0');
}

void	print_nmb(va_list arg, int *buffer)
{
	int		num;

	num = va_arg(arg, int);
	ft_putnbr(num, buffer);
}
