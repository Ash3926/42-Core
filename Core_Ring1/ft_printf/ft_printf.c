/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolomon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 21:15:19 by asolomon          #+#    #+#             */
/*   Updated: 2025/05/26 22:56:13 by asolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static	parse_input(char *str, char c, va_list args)
{
	void	*val;

	if (c == 'c')
		val = &(va_arg(args, char));
	else if (c == 's')
		val = va_arg(args, char *);
	else if (c == 'p')
		val = hexa_converter(va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		val = &ft_itoa(va_arg(args, int));
	else if (c == 'u')
		val = ft_unsigneditoa(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		val = hexa_converter(va_arg(args, unsigned int));
	else if (c == '%')
		val = &('%');
	ft_putstr_fd(val, 1);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;

	va_start(args, str);
	while (*str)
	{
		if (*str != %)
			ft_putchar_fd(*str, 1);
		else
		{
			str++;
			parse_input(str, *str, args);
		}
		str++;
	}

