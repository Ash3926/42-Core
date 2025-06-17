/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolomon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 18:53:25 by asolomon          #+#    #+#             */
/*   Updated: 2025/06/17 19:44:02 by asolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define BUFFER_SIZE 42

char	*get_next_line(int fd);
void	ft_bzero(void *str, size_t n);
char	*ft_cpy(char *buffer, ssize_t start, ssize_t end);
char	*ft_strjoin(char const *s1, char const *s2, ssize_t to_join);

#endif
