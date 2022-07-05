/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboichuk <hboichuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 17:40:51 by hboichuk          #+#    #+#             */
/*   Updated: 2022/06/28 17:40:03 by hboichuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

static void	check_format(const char *str, va_list arg, int index, int *buffer)
{
	char			c;

	if (str[index] == 'c')
	{
		c = va_arg(arg, int);
		*buffer += ft_putchar(c);
	}
	if (str[index] == '%')
		*buffer += ft_putchar('%');
	if (str[index] == 's')
		print_str(arg, buffer);
	if (str[index] == 'p')
		print_pointer(arg, buffer);
	if (str[index] == 'd' || str[index] == 'i')
		print_nmb(arg, buffer);
	if (str[index] == 'u')
		print_nmb_u(arg, buffer);
	if (str[index] == 'X' || str[index] == 'x')
		print_nmb_hexa(arg, str[index], buffer);
}

int	ft_printf(const char *string, ...)
{
	int				i;
	va_list			args;
	int				result;
	int				*buffer;

	va_start(args, string);
	i = 0;
	result = 0;
	buffer = 0;
	buffer = &result;
	while (string[i])
	{
		if (string[i] == '%')
		{
			i++;
			check_format(string, args, i, buffer);
		}
		else
			result += ft_putchar(string[i]);
		i++;
	}
	va_end(args);
	return (result);
}
