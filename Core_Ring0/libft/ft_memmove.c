/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolomon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:33:44 by asolomon          #+#    #+#             */
/*   Updated: 2025/05/28 12:25:40 by asolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *str, size_t n)
{
	size_t			curr;
	unsigned char	*hold;
	unsigned char	storage[10000]; // If moulinette KO, gotta do the check version
	unsigned char	*source;

	if ((dest == NULL || (void *)str == NULL) && n > 0)
		return (NULL);
	hold = (unsigned char *)dest;
	source = (unsigned char *)str;
	curr = 0;
	while (curr < n)
	{
		storage[curr] = source[curr];
		curr++;
	}
	curr = 0;
	while (curr < n)
	{
		hold[curr] = storage[curr];
		curr++;
	}
	return (dest);
}
// TEST CASE
#include <stdio.h>
int	main()
{
	void	*final;
	char	str[] = "H3llo World!AYYEYEYFEYFYEFYEYFEHFEYYEFGSYFBEBHBSEBVBHESBVBESIVIOSJIOVJIJISJIJIJIEJIJIJIEJIJIOJIIEIIOEJIOEJIEJIOEJIOEJIOEIJJIEJIOJIEJIJIIJJIJIJIOJIONJNJKDNJKNJSNJKCDNJKDSNJKCDNJDNJDNJCDNJNJSDNJCDBCDBHDSBCDHICDSHOIDIOCDJISDJIODCjiodfvnnjknvselvsferfseihugeou4f0943u092i30fujoejiojeo;vfiohev;hvibhfbvnhsjviwj4iojo34jut8o4u3f0ou34uo3ujvoejvgojglnvlervnfeawpfwofpoi34-0u2q-4iqjpo4jojgfloejfwlmwaofkepir0-4u-ut093jgwpjgawoJFPWEJFMOENVORIENOIJGOEJP93I4R34IT-43UT34U0934U934UT3UT94U03UT093UT093UT09U0UT03UT03UT03UT03UT03UT0UT03UT03TU093UT049UT0UT4U903";

	final = malloc(150);
	ft_memmove(final, (const void *)str, 100);
	printf("%s", (char *)final);
}

