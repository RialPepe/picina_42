/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocobos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 17:31:52 by jocobos-          #+#    #+#             */
/*   Updated: 2023/08/17 14:54:26 by jocobos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*#include <stdio.h>
#include <unistd.h>*/

void	ft_strlowcase(char *str)
{
	while (*str != '\0')
	{
		if ((*str >= 'A') && (*str <= 'Z'))
			*str = *str + 32;
		str++;
	}
}

void	ft_transform(char *str)
{
	if ((*str >= 'a') && (*str <= 'z'))
		*str = *str - 32;
}

char	*ft_strcapitalize(char *str)
{
	char	*first;

	ft_strlowcase(str);
	first = str;
	while (*str)
	{
		if ((first == str) && (*first >= 'a') && (*first <= 'z'))
			*str = *str - 32;
		if ((*(str - 1) >= 0) && (*(str - 1) <= 47) && (first != str))
			ft_transform(str);
		if ((*(str - 1) >= 58) && (*(str - 1) <= 64) && (first != str))
			ft_transform(str);
		if ((*(str - 1) >= 91) && (*(str - 1) <= 96) && (first != str))
			ft_transform(str);
		if ((*(str - 1) >= 123) && (*(str - 1) <= 127) && (first != str))
			ft_transform(str);
		str++;
	}
	str = first;
	return (str);
}

/*int	main(void)
{
	char	char1[] = "sALuTu:aA aA[aAa]a|pol3la 3u3u3  [2k2] polla";
	char	*ptr1;

	ptr1 = &char1[0];
	printf ("%s", ft_strcapitalize(ptr1));
	return (0);
}*/
