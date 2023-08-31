/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocobos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 11:39:06 by jocobos-          #+#    #+#             */
/*   Updated: 2023/08/31 18:38:31 by jocobos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdio.h>

int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb <= 1)
		return (0);
	while (i < nb / i)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (ft_is_prime(nb) == 1)
		return (nb);
	if (ft_is_prime(nb) == 0)
		return (ft_find_next_prime(nb + 1));
	return (0);
}

/*int main(void)
{
    int nb;

    nb = 2147483233;
    printf ("%d", ft_find_next_prime(nb));
    return (0);
}*/
