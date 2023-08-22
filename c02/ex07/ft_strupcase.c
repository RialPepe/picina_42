/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocobos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 22:22:38 by jocobos-          #+#    #+#             */
/*   Updated: 2023/08/17 13:51:53 by jocobos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*#include <stdio.h>
#include <unistd.h>*/

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
	{
		if ((*(str + i) >= 'a') && (*(str + i) <= 'z'))
			*(str + i) = *(str + i) - 32;
		i++;
	}
	return (str);
}

/*int	main(void)
{
	char	char1[] = "aaAAaa00aaAAa12aaAA--aA";

	printf ("%s", ft_strupcase(char1));
	return (0);
}*/
