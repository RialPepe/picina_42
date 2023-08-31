/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocobos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 19:08:59 by jocobos-          #+#    #+#             */
/*   Updated: 2023/08/31 18:17:50 by jocobos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	sol;

	sol = 1;
	if (nb >= 0)
	{
		while (nb > 0)
		{
			sol = sol * nb;
			nb--;
		}
		return (sol);
	}
	return (0);
}

int	main(void)
{
	int	nb;

	nb = 0;
	printf ("%d", ft_iterative_factorial(nb));
	return (0);
}
