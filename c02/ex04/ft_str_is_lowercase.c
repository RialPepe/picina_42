/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocobos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 13:28:29 by jocobos-          #+#    #+#             */
/*   Updated: 2023/08/17 13:27:32 by jocobos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*#include <stdio.h>
#include <unistd.h>*/

int	ft_str_is_lowercase(char *str)
{
	int	result;

	result = 1;
	while (*str != '\0')
	{
		if ((*str >= 'a') && (*str <= 'z'))
			result = result * 1;
		else
			result = result * 0;
		str++;
	}
	return (result);
}

/*int	main(void)
{
	char	char1[] = "aaa";
	char	*ptr1;

	ptr1 = &char1[0];
	printf ("%d", ft_str_is_lowercase(ptr1));
	return (0);
}*/
