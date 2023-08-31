/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocobos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 23:10:08 by jocobos-          #+#    #+#             */
/*   Updated: 2023/08/17 13:16:42 by jocobos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*#include <stdio.h>*/

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (*(src + i) != '\0')
	{
		*(dest + i) = *(src + i);
		i++;
	}
	*(dest + i) = '\0';
	return (dest);
}

/*int	main(void)
{
	char	char1[2] = "ho";
	char	char2[] = "pepe";
	char*	ptr1;
	char*	ptr2;

	ptr1 = &char1[0];
	ptr2 = &char2[0];
	printf ("%s", ft_strcpy(char1, char2));
	return (0);
}*/
