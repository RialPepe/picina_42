/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocobos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 01:26:11 by jocobos-          #+#    #+#             */
/*   Updated: 2023/08/17 13:20:32 by jocobos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*#include <stdio.h>*/

int	ft_str_is_alpha(char *str)
{
	while (*str != '\0')
	{
		if (!(*str >= 'a') && (*str <= 'z'))
			if (!(*str >= 'A') && (*str <= 'Z'))
				return (0);
		str++;
	}
	return (1);
}

/*int	main(void)
{
	char	char1[] = "po1A";
	char	*ptr1;

	ptr1 = &char1[0];
	printf ("%d", ft_str_is_alpha(ptr1));
	return (0);
}*/
