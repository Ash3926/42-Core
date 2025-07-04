/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolomon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:37:30 by asolomon          #+#    #+#             */
/*   Updated: 2025/07/03 21:49:51 by asolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "get_next_line.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	num;

	i = 0;
	sign = 1;
	num = 0;
	while ((nptr[i] > 8 && nptr[i] < 14) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] > 47 && nptr[i] < 58)
	{
		if (num == 214748364 && nptr[i] == '8' && sign == -1)
			return (-2147483648);
		num = (num * 10) + (nptr[i] - '0');
		i++;
	}
	num *= sign;
	return (num);
}

int	main(int argc, char *argv[])
{
	int		fd;
	char	*out;
	int		i;
	int		len;

	if (argc != 3)
	{
		printf("Incorrect number of arguments. Please run the program with one file name and the expected number of lines");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Invalid file name");
		return (0);
	}
	len = ft_atoi(argv[2]);
	i = 0;
	while (i <= len)
	{
		out = get_next_line(fd);
		printf("Line %d: %s$\n", i + 1, out);
		free(out);
		i++;
	}
	return (0);
}
