/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocobos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 13:14:37 by jocobos-          #+#    #+#             */
/*   Updated: 2023/08/17 13:25:21 by jocobos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*#include <stdio.h>
#include <unistd.h>*/

int	ft_str_is_numeric(char *str)
{
	int	result;

	result = 1;
	while (*str != '\0')
	{
		if ((*str >= '0') && (*str <= '9'))
			result = result * 1;
		else
			result = result * 0;
		str++;
	}
	return (result);
}

/*int	main(void)
{
	char	char1[] = "34";
	char	*ptr1;

	ptr1 = &char1[0];
	printf ("%d", ft_str_is_numeric(ptr1));
	return (0);
}*/
