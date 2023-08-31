/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocobos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:28:33 by jocobos-          #+#    #+#             */
/*   Updated: 2023/08/24 02:18:03 by jocobos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

int	ft_is_valid(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		if (str[i] == '-' || str[i] == '+')
			return (0);
		i++;
	}
	return (42);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_aux(long nbr, char *base)
{
	int	aux;
	int	len;

	len = ft_strlen(base);
	if (len > 1 && ft_is_valid(base) == 42)
	{
		if (nbr < 0)
		{
			nbr = -nbr;
			write (1, "-", 1);
		}
		if (nbr > 0)
		{
			ft_aux(nbr / len, base);
			aux = nbr % len;
			write (1, &base[aux], 1);
		}
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	if (nbr == 0)
		write (1, &base[0], 1);
	else
		ft_aux(nbr, base);
}

/*int	main(void)
{
	int		nbr = -2147483648;
	char	str[] = "0123456789ABCDEF";
	ft_putnbr_base(nbr, str);
	return (0);
}*/
