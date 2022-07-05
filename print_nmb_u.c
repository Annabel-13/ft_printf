/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nmb_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboichuk <hboichuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 20:51:26 by hboichuk          #+#    #+#             */
/*   Updated: 2022/06/28 17:49:25 by hboichuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_u(unsigned int n, int *buffer)
{
	if (n > 9)
	{
		ft_putnbr_u(n / 10, buffer);
		n %= 10;
	}
	*buffer += ft_putchar(n + '0');
}

void	print_nmb_u(va_list arg, int *buffer)
{
	int		num;

	num = va_arg(arg, int);
	ft_putnbr_u(num, buffer);
}
