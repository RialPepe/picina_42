/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocobos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 03:25:07 by jocobos-          #+#    #+#             */
/*   Updated: 2023/08/24 14:46:23 by jocobos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdio.h>

int	ft_recursive_power(int nb, int power)
{
	if (power == 0)
		return (1);
	return (nb * ft_recursive_power(nb, power - 1));
}

/*int	main(void)
{
	int	nb;
	int	power;

	nb = 2;
	power = 3;
	printf ("%d", ft_recursive_power(nb, power));
	return (0);
}*/
