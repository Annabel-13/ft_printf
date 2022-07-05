/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboichuk <hboichuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:48:00 by hboichuk          #+#    #+#             */
/*   Updated: 2022/06/28 17:42:01 by hboichuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_printf(const char *string, ...);
void	print_nmb(va_list arg, int *buffer);
void	print_str(va_list arg, int *buffer);
int		ft_atoi(const char *str);
int		ft_putchar(char c);
int		print_char(va_list arg);
void	ft_putnbr(int n, int *buffer);
void	print_nmb_u(va_list arg, int *buffer);
void	ft_putnbr_u(unsigned int n, int *buffer);
void	print_nmb_hexa(va_list arg, char c, int *buffer);
void	ft_putnbr_base_ul(unsigned long n, char *base, int *buffer);
void	ft_putnbr_base_u(unsigned int n, char *base, int *buffer);
void	print_pointer(va_list arg, int *buffer);
void	ft_putstr(char *s, int *buffer);

#endif