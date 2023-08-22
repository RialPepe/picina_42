/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocobos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 19:48:10 by jocobos-          #+#    #+#             */
/*   Updated: 2023/08/14 15:12:54 by jocobos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	aux;

	aux = *a;
	*a = *b;
	*b = aux;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	*ptr2;
	int	*ptr3;
	int	i;
	int	j;

	i = 0;
	j = 0;
	ptr2 = tab + 1;
	ptr3 = tab;
	while (i < size - 1)
	{
		tab = ptr3;
		ptr2 = tab + 1;
		j = 0;
		while (j < size - 1)
		{
			if (*tab > *ptr2)
				ft_swap(tab, ptr2);
			j++;
			tab++;
			ptr2++;
		}
		i++;
	}
}
