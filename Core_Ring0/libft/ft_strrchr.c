/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolomon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:32:01 by asolomon          #+#    #+#             */
/*   Updated: 2025/05/08 16:50:24 by asolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*holder_c;
	int		i;

	i = 0;
	c = c % 256
	holder_c = NULL;
	while (str[i])
	{
		if (str[i] == c)
			holder_c = (char *)&str[i];
		i++;
	}
	if (c == 0)
		holder_c = (char *)&str[i];
	return (holder_c);
}

/* TEST CASE
#include <stdio.h>
int     main()
{
        char    *str = "Hello World!\0";
        char    *hold;

        hold = ft_strrchr((const char *)str, 'e');
        printf("%c", *hold);
}
*/
