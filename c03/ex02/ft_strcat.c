/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocobos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:09:27 by jocobos-          #+#    #+#             */
/*   Updated: 2023/08/21 20:34:05 by jocobos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*#include<stdio.h>*/

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

/*int	main(void)
{
	char	s1[] = "hola";
	char	s2[] = "peeeeeeeeeeeeeeeeeeeeee";

	printf ("%s", ft_strcat(s1, s2));
	return (0);
}*/
