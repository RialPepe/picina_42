/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocobos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:28:36 by jocobos-          #+#    #+#             */
/*   Updated: 2023/08/17 13:29:58 by jocobos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*#include <stdio.h>
#include <unistd.h>*/

int	ft_str_is_uppercase(char *str)
{
	int	result;

	result = 1;
	while (*str != '\0')
	{
		if ((*str >= 'A') && (*str <= 'Z'))
			result = result * 1;
		else
			result = result * 0;
		str++;
	}
	return (result);
}

/*int	main(void)
{
	char	char1[] = "AAA";
	char	*ptr1;

	ptr1 = &char1[0];
	printf ("%d", ft_str_is_uppercase(ptr1));
	return (0);
}*/
