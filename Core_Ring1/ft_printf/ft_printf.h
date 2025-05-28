/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolomon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 21:11:14 by asolomon          #+#    #+#             */
/*   Updated: 2025/05/28 17:42:40 by asolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

int		ft_printf(const char *str, ...);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *c);
char	*hexa_v(void *addr);
char	*hexa_ui(unsigned int c, char flag);
void	ft_toupper(char *c);
char	*ft_unsigneditoa(unsigned int c);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);

#endif
