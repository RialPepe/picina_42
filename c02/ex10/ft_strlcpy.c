/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocobos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 14:08:25 by jocobos-          #+#    #+#             */
/*   Updated: 2023/08/17 16:07:42 by jocobos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*#include<stdio.h>*/

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	sol;

	sol = 0;
	while (size > 1 && *src != '\0')
	{
		*dest = *src;
		src++;
		sol++;
		dest++;
		size--;
	}
	while (*src != '\0')
	{
		sol++;
		src++;
	}
	*dest = '\0';
	return (sol);
}

/*int	main(void)
{
	char	dest[] = "hola";
	char	src[] =   "peeeeee";
	char	*ptr1;
	char	*ptr2;
	int		sol;
	ptr1 = &dest[0];
	ptr2 = &src[0];
	sol = ft_strlcpy(ptr1, ptr2, 4);
	printf ("%s", dest);
	printf ("%d", sol);
	return (0);
}*/
