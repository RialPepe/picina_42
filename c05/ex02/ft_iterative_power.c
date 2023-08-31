/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocobos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 21:50:09 by jocobos-          #+#    #+#             */
/*   Updated: 2023/08/31 18:21:24 by jocobos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	sol;

	sol = 1;
	if (nb >= 0 && power >= 0)
	{
		while (power > 0)
		{
			sol = sol * nb;
			power--;
		}
		return (sol);
	}
	return (0);
}

/*int	main(void)
{
	int	nb;
	int	power;

	nb = 4;
	power = 0;
	printf ("%d", ft_iterative_power(nb, power));
	return (0);
}*/
