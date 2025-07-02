/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolomon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 18:52:33 by asolomon          #+#    #+#             */
/*   Updated: 2025/07/02 19:44:54 by asolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char    *get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2, ssize_t start, ssize_t end);
void    ft_bzero(char *str, ssize_t n);

typedef struct	s_box
{
	char	space[BUFFER_SIZE];
	struct s_box	*next;
	ssize_t	start;
	ssize_t	end;
}		t_box;

#endif
