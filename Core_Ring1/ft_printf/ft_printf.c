/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolomon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 21:15:19 by asolomon          #+#    #+#             */
/*   Updated: 2025/05/28 18:29:28 by asolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	parse_input(char c, va_list args)
{
	void	*val;
	size_t	size;

	val = NULL;
	if (c == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1), 1);
	else if (c == 's')
		val = va_arg(args, char *);
	else if (c == 'p')
		val = hexa_v(va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		val = ft_itoa(va_arg(args, int));
	else if (c == 'u')
		val = ft_unsigneditoa(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		val = hexa_ui(va_arg(args, unsigned int), c);
	else if (c == '%')
		val = &("%");
	if (!val)
		val = "(null)";
	ft_putstr_fd(val, 1);
	size = ft_strlen((const char *)val);
	if (c != 'c' && c != 's' && c != '%')
		free(val);
	return (size);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		outputlen;

	outputlen = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str != '%')
		{
			ft_putchar_fd(*str, 1);
			outputlen++;
		}
		else
		{
			str++;
			outputlen += parse_input(*str, args);
		}
		str++;
	}
	va_end(args);
	return (outputlen);
}
/* TEST
#include <stdio.h>
int main()
{
	char *hey = "my name is Jack";
	int a = ft_printf("Hello %s, I scored %i%% in school.\n Address: %p\n", 
	hey, -2309240, (void *)hey);
	int b = printf("Hello %s, I scored %i%% in school.\n Address: %p\n", 
	hey, -2309240, (void *)hey);

	printf("Printed characters: %d, %d\n", a, b);
}
*/

/* TEST 2
#include <stdio.h>
int main()
{
	//char	*hey = NULL;
	//int a = ft_printf("%s \n %p %p \n %x \n", hey, (void *)0, (void *)0, 0);
	//int b = printf("%s \n %p %p \n %x \n", hey, (void *)0, (void *)0, 0);
	printf("Printed characters: %d, %d\n", a, b);
}
*/
