/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocobos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:56:09 by jocobos-          #+#    #+#             */
/*   Updated: 2023/08/24 04:44:12 by jocobos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
#include <string.h>

char	*ft_strstr(char *str, char *to_find)
{
	char	*found;
	int		i;
	int		j;

	i = 0;
	if (*to_find == '\0')
		return (str);
	while (str[i])
	{
		j = 0;
		if (str[i] == to_find[j])
		{
			found = str + i;
			while (to_find[j])
			{
				if (str[j + i] != to_find[j])
					break ;
				if ((to_find[j] == str[i + j]) && to_find[j + 1] == '\0')
					return (found);
				j++;
			}
		}
		i++;
	}
	return (0);
}

/*int	main(void)
{
	char	s1[] = "mepitopiti";
	char	s2[] = "piti";

	printf ("%s\n", ft_strstr(s1, s2));
	printf ("%s\n", strstr(s1, s2));
	return (0);
}*/
