/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolomon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 18:53:25 by asolomon          #+#    #+#             */
/*   Updated: 2025/07/03 22:11:06 by asolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_bzero(void *str, size_t n);
char	*ft_cpy(char *buffer, ssize_t start, ssize_t end, ssize_t bytes);
char	*ft_strjoin(char const *s1, char const *s2, ssize_t to_join);

#endif
