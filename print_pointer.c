/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboichuk <hboichuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 10:17:20 by hboichuk          #+#    #+#             */
/*   Updated: 2022/06/28 17:50:52 by hboichuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_pointer(va_list arg, int *buffer)
{
	unsigned long	ptr;
	char			*ptr_null;

	ptr_null = "0x0";
	ptr = va_arg(arg, unsigned long);
	if ((void *)ptr == NULL)
		ft_putstr(ptr_null, buffer);
	else
	{
		ft_putstr("0x", buffer);
		ft_putnbr_base_ul(ptr, "0123456789abcdef", buffer);
	}
}
