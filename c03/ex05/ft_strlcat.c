/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocobos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 21:33:32 by jocobos-          #+#    #+#             */
/*   Updated: 2023/08/22 01:09:52 by jocobos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*#include<stdio.h>*/

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	lendest;
	unsigned int	lensrc;
	unsigned int	i;

	i = 0;
	lendest = ft_strlen(dest);
	lensrc = ft_strlen(src);
	if (lendest >= size)
		return (lensrc + size);
	while ((src[i] != '\0') && (i < size - lendest - 1))
	{
		dest[lendest + i] = src[i];
		i++;
	}
	dest[lendest + i] = '\0';
	return (lendest + lensrc);
}

/*int	main()
{
	char	dest[20] = "helllo, ";
	char 	src[] = "world!";
	unsigned int	size = 20;
	printf ("%d", ft_strlcat(dest, src, size));
}*/
