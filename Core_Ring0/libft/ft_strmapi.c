/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolomon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 13:45:56 by asolomon          #+#    #+#             */
/*   Updated: 2025/05/14 13:27:45 by asolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	size;
	char			*str;

	size = ft_strlen(s);
	str = (char *)malloc(size + 1);
	if (str == NULL)
		return (str);
	i = 0;
	while (i < size)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = 0;
	return (str);
}
/* TEST CASE
char    upper(unsigned int i, char c)
{
    if (c >= 'a' && c <= 'z')
        return (c - 32);
    return (c);
}

#include <stdio.h>
int main()
{
    char const s[] = "hello";

    printf("%s", ft_strmapi(s, upper));
}
*/
