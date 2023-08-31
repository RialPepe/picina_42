/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocobos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 12:46:05 by jocobos-          #+#    #+#             */
/*   Updated: 2023/08/24 01:21:56 by jocobos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

void	ft_putaux(int nb)
{
	char	aux;

	if (nb < 0)
	{
		write (1, "-", 1);
		nb = nb * -1;
	}
	if (nb > 0)
	{
		ft_putaux(nb / 10);
		aux = (char)(nb % 10 + '0');
		write (1, &aux, 1);
	}
}

void	ft_putnbr(int nb)
{
	if (nb == 0)
		write (1, "0", 1);
	else if (nb == -2147483648)
	{
		write (1, "-2147483648", 11);
	}
	else
		ft_putaux(nb);
}

/*int	main(void)
{
	ft_putnbr(42);
	return (0);
}*/
