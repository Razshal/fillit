/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:59:29 by abouvero          #+#    #+#             */
/*   Updated: 2017/11/10 17:43:01 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	int			i;
	int			j;
	const char	*ptr;

	i = 0;
	j = 0;
	if (needle[0] == '\0')
		return ((char*)haystack);
	while (haystack[i])
	{
		if (haystack[i] == needle[0])
		{
			while (needle[j] && haystack[i + j] == needle[j])
			{
				j++;
				if (needle[j] == '\0')
				{
					ptr = &(haystack[i]);
					return ((char*)ptr);
				}
			}
		}
		i++;
	}
	return (0);
}
