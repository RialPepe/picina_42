/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocobos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:41:33 by jocobos-          #+#    #+#             */
/*   Updated: 2023/08/22 00:54:48 by jocobos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*#include<stdio.h>*/

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (nb > 0)
	{
		if (src[j] == '\0')
		{
			dest[i] = '\0';
			break ;
		}
		dest[i] = src[j];
		i++;
		j++;
		nb--;
	}
	dest[i] = '\0';
	return (dest);
}

/*int	main(void)
{
	char	s1[] = "hola";
	char	s2[] = "pepe";

	printf ("%s", ft_strncat(s1, s2, 2));
	return (0);
}*/
