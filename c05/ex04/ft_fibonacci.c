/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocobos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 04:19:12 by jocobos-          #+#    #+#             */
/*   Updated: 2023/08/28 18:50:10 by jocobos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdio.h>

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	while (index >= 0)
	{
		if (index == 0)
			return (0);
		if (index == 1)
			return (1);
		index--;
		return (ft_fibonacci(index) + ft_fibonacci(index - 1));
	}
	return (0);
}

int	main(void)
{
	int	index;

	index = 7;
	printf ("%d", ft_fibonacci(index));
}
//"0 1 1 2 3 5 8 13 21"
