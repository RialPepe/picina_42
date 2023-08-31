/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocobos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 11:06:19 by jocobos-          #+#    #+#             */
/*   Updated: 2023/08/16 12:11:01 by jocobos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	aux;
	int	*fin;

	fin = tab + size - 1;
	while (tab != fin && tab != fin + 1)
	{
		aux = *tab;
		*tab = *fin;
		*fin = aux;
		tab++;
		fin--;
	}
}
/*
int	main(void)
{
	int	num[] = {1, 2, 3};
	int	size;
	int	*ptr1;

	size = 3;
	ptr1 = &num[0];
	ft_rev_int_tab(ptr1, size);
	printf ("%d", *ptr1);
	printf ("%d", *(ptr1 + 1));
	printf ("%d", *(ptr1 + 2));
	//printf ("%d", *(ptr1 + 3));
	return (0);
}*/
