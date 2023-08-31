/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocobos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:53:19 by jocobos-          #+#    #+#             */
/*   Updated: 2023/08/21 20:53:59 by jocobos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*#include<stdio.h>*/

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((*(s1 + i) || *(s2 + i)) && i < n)
	{
		if (*(s1 + i) > *(s2 + i))
			return (1);
		if (*(s1 + i) < *(s2 + i))
			return (-1);
		i++;
	}
	return (0);
}

/*int	main(void)
{
	char	s1[] = "peta";
	char	s2[] = "pota";

	printf ("%d", ft_strncmp(s1, s2, 2));
	return (0);
}*/
