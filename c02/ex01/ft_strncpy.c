/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocobos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 01:24:48 by jocobos-          #+#    #+#             */
/*   Updated: 2023/08/21 23:29:15 by jocobos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*#include <stdio.h>*/

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && *src != '\0')
	{
		*(dest + i) = *src;
		src++;
		i++;
	}
	while (i < n)
	{
		*(dest + i) = '\0';
		i++;
	}
	return (dest);
}

/*int	main(void)
{
	char	char1[4] = {"abduskha"};
	char	char2[] = {"ho"};
	char*	ptr1;
	char*	ptr2;

	ptr1 = &char1[0];
	ptr2 = &char2[0];
	printf ("%s", ft_strncpy(ptr1, ptr2, 4));
	return (0);
}*/
