/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboichuk <hboichuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 22:52:20 by hboichuk          #+#    #+#             */
/*   Updated: 2022/06/28 17:51:34 by hboichuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s, int *buffer)
{
	int	i;

	i = 0;
	while (s[i])
	{
		*buffer += ft_putchar(s[i]);
		i++;
	}
}

void	print_str(va_list arg, int *buffer)
{
	char	*str;

	str = va_arg(arg, void *);
	if (str == NULL)
		ft_putstr("(null)", buffer);
	else
		ft_putstr(str, buffer);
}
