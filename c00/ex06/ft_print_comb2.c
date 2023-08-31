/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocobos- <jocobos-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 21:18:24 by jocobos-          #+#    #+#             */
/*   Updated: 2023/08/12 21:15:56 by jocobos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_comb2(void)
{
	char	array[5];
	int		num1;
	int		num2;

	num1 = 0;
	while (num1 <= 98)
	{
		num2 = num1 + 1;
		while (num2 <= 99)
		{
			array[0] = (char)(num1 / 10 + '0');
			array[1] = (char)(num1 % 10 + '0');
			array[2] = ' ';
			array[3] = (char)(num2 / 10 + '0');
			array[4] = (char)(num2 % 10 + '0');
			write (1, &array, 5);
			if (num1 < 98)
				write (1, ", ", 2);
			num2++;
		}
		num1++;
	}
}
