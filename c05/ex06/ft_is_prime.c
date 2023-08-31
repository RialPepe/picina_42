/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocobos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 11:38:08 by jocobos-          #+#    #+#             */
/*   Updated: 2023/08/31 18:37:56 by jocobos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdio.h>

int	ft_is_prime(int nb)
{
	int	i;
	int	aux;

	i = nb - 1;
	aux = 1;
	while (i > 1 && i < nb)
	{
		if (nb % i != 0)
			aux = aux * 1;
		if (nb % i == 0)
			aux = aux * 0;
		i--;
	}
	return (aux);
}

/*int main(void)
{
    int nb;

    nb = 247483648;
    printf ("%d", ft_is_prime(nb));
    return (0);
}*/
