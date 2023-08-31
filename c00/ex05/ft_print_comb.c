/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocobos- <jocobos-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 16:21:39 by jocobos-          #+#    #+#             */
/*   Updated: 2023/08/16 11:34:17 by jocobos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

void	ft_print_comb(void)
{
	char	num1;	
	char	num2;
	char	num3;

	num1 = '0';
	while (num1 <= '7')
	{
		num2 = num1 + 1;
		while (num2 <= '8')
		{
			num3 = num2 +1;
			while (num3 <= '9')
			{
				write (1, &num1, 1);
				write (1, &num2, 1);
				write (1, &num3, 1);
				if (num1 != '7')
					write (1, ", ", 2);
				num3++;
			}
			num2++;
		}
		num1++;
	}
}
