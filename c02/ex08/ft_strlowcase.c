/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocobos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 17:28:37 by jocobos-          #+#    #+#             */
/*   Updated: 2023/08/17 14:53:02 by jocobos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*#include <stdio.h>
#include <unistd.h>*/

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
	{
		if ((*(str + i) >= 'A') && (*(str + i) <= 'Z'))
			*(str + i) = *(str + i) + 32;
		i++;
	}
	return (str);
}

/*int	main(void)
{
	char	char1[] = "aaAAaa00aaAA--AAaa";
	char	*ptr1;

	ptr1 = &char1[0];
	printf ("%s", ft_strlowcase(ptr1));
	return (0);
}*/
