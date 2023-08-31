/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocobos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 11:36:08 by jocobos-          #+#    #+#             */
/*   Updated: 2023/08/31 19:32:07 by jocobos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdio.h>

int	binary_search(long nb, long min, long max)
{
	long	half;

	half = min + (max - min) / 2;
	if (max == min + 1)
	{
		if (min * min == nb)
			return (min);
		if (max * max == nb)
			return (max);
		return (0);
	}
	if (half * half < nb)
		return (binary_search(nb, half, max));
	else
		return (binary_search(nb, min, half));
}

int	ft_sqrt(int nb)
{
	if (nb < 1)
		return (0);
	return (binary_search(nb, 0, nb));
}

/*int main(void)
{
    int nb;

    nb = 49;
    printf ("%d", ft_sqrt(nb));
}*/
