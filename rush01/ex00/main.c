/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpanfil- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 14:00:01 by lpanfil-          #+#    #+#             */
/*   Updated: 2023/08/20 19:32:51 by lpanfil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	base_case(char mat[6][6], char *argv[]);

void	add_box(char mat[6][6], int i, int j, int *solved);

int		is_valid_input(int argc, char input[]);

int	main(int argc, char *argv[])
{
	int		*solved;
	int		aux;
	char	mat[6][6];

	aux = 0;
	solved = &aux;
	if (is_valid_input(argc, argv[1]) != 42)
		write (1, "Error\n", 6);
	else
	{
		mat[0][0] = 'A';
		mat[0][5] = 'A';
		mat[5][0] = 'A';
		mat[5][5] = 'A';
		base_case(mat, argv);
		add_box(mat, 1, 1, solved);
		if (*solved != 42)
			write(1, "Error\n", 6);
	}
	return (0);
}
