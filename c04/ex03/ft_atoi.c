/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocobos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 03:06:34 by jocobos-          #+#    #+#             */
/*   Updated: 2023/08/28 18:01:54 by jocobos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdio.h>

int	ft_atoi(char *str)
{
	int	aux;
	int	numf;

	numf = 0;
	aux = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
	{
		str++;
	}
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			aux++;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		numf = (numf * 10) + (*str - '0');
		str++;
	}
	if (aux % 2 != 0)
		numf = -numf;
	return (numf);
}

/*int main(void){
	char s[] = "  --+---+1234ab567";
	printf("%d", ft_atoi(s));
	return 0;
}*/
