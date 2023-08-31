/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocobos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:37:07 by jocobos-          #+#    #+#             */
/*   Updated: 2023/08/21 20:31:22 by jocobos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*#include<stdio.h>*/

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (*(s1 + i) || *(s2 + i))
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
	char	s1[] = "patiw";
	char	s2[] = "patitets";

	printf ("%d", ft_strcmp(s1, s2));
	return (0);
}*/
