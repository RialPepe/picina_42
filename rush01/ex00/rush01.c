/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocobos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 18:26:43 by jocobos-          #+#    #+#             */
/*   Updated: 2023/08/20 19:00:51 by jocobos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	nomecabe(char mat[6][6], int *arr, int *solved);
int		is_valid_input(int argc, char input[]);
void	print_sol(char mat[6][6]);

void	rotate_matrix(char mat[6][6], char mat_r[6][6])
{
	int	i;
	int	j;

	i = 0;
	while (i < 6)
	{
		j = 0;
		while (j < 6)
		{
			mat_r[j][5 - i] = mat[i][j];
			j++;
		}
		i++;
	}
}

int	is_valid(char mat[6][6], int i0, int j0, int val)
{
	int	i;

	i = 1;
	while (i < 5)
	{
		if ((mat[i0][i] == val && i != j0) || (mat[i][j0] == val && i != i0))
			return (0);
		i++;
	}
	return (1);
}

void	base_case(char mat[6][6], char *argv[])
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < 5)
	{
		mat[0][i] = argv[1][j];
		mat[5][i] = argv[1][8 + j];
		mat[i][0] = argv[1][16 + j];
		mat[i][5] = argv[1][j + 24];
		i++;
		j = j + 2;
	}
}

int	is_sol(char mat[6][6], int i, int j, int sumi)
{
	int		sumd;
	char	maxd;
	char	maxi;

	while (++i < 5)
	{
		j = 0;
		sumi = 1;
		sumd = 1;
		maxd = mat[i][4];
		maxi = mat[i][1];
		while (++j < 4)
		{
			if (mat[i][j] < mat[i][j + 1] && mat[i][j + 1] > maxi && ++sumi < 9)
				maxi = mat[i][j + 1];
			if (mat[i][5 - j] < mat[i][4 - j] && mat[i][4 - j] > maxd)
			{
				sumd++;
				maxd = mat[i][4 - j];
			}
		}
		if (sumi != mat[i][0] - '0' || sumd != mat[i][5] - '0')
			return (0);
	}
	return (42);
}

void	add_box(char mat[6][6], int i, int j, int *solved)
{
	int		arr[3];
	char	matriz_rotada[6][6];

	arr[2] = 1;
	if (i == 5)
	{
		rotate_matrix(mat, matriz_rotada);
		if (is_sol(mat, 0, 1, 1) == 42 && is_sol(matriz_rotada, 0, 1, 1) == 42)
		{
			*solved = 42;
			print_sol(mat);
		}
	}
	else
	{
		while (arr[2] <= 4)
		{
			arr[0] = i;
			arr[1] = j;
			nomecabe(mat, arr, solved);
			arr[2]++;
		}
	}
}
