/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raux.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpanfil- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 19:57:55 by lpanfil-          #+#    #+#             */
/*   Updated: 2023/08/20 20:04:04 by lpanfil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	rotate_matrix(char mat[6][6], char mat_r[6][6]);

void	base_case(char mat[6][6], char *argv[]);

void	add_box(char mat[6][6], int i, int j, int *solved);

int		is_valid(char mat[6][6], int i0, int j0, int val);

void	nomecabe(char mat[6][6], int *arr, int *solved)
{
	if (is_valid(mat, arr[0], arr[1], arr[2] + '0') == 1)
	{
		mat[arr[0]][arr[1]] = arr[2] + '0';
		if (arr[1] == 4)
		{
			arr[0]++;
			arr[1] = 1;
		}
		else
			arr[1]++;
		add_box(mat, arr[0], arr[1], solved);
		if (arr[0] != 5)
			mat[arr[0]][arr[1]] = '\0';
	}
}

void	print_sol(char mat[6][6])
{
	int	i;
	int	j;

	i = 1;
	while (i < 5)
	{
		j = 1;
		while (j < 5)
		{
			write (1, &mat[i][j], 1);
			if (j != 4)
				write (1, " ", 1);
			j++;
		}
		write (1, "\n", 1);
		i++;
	}
}
