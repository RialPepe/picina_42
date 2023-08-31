/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getMatrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-c <pperez-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:35:04 by pperez-c          #+#    #+#             */
/*   Updated: 2023/08/30 18:39:41 by pperez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct			s_input
{
	int			rows;
	int			cols;
	char		data[4];
	char		**map;
	int			i0;
	int			j0;
	int			ifi;
	int			jfi;
	int			set;
};
int				ft_atoi(char *str);
char			*get_file_content(char *filename, int i, int character_count);
void			print_arr(char *str);
void			get_data(char *data, char *str);
int				get_rows(char end, char *filecontent);

int				count_cols(char *fcont);
char			**map_dim(int rows, int cols);
char			**gen_map_arr(char *fcont, int rows, int cols, int k);
struct s_input	initialize_coords(struct s_input var);
struct s_input	use_input(char *filename);

int				samecols(char *filename, char *filecontent, int i, int aux);
int				error(char *filename);

struct s_input	set_vals(struct s_input var, int i, int j, int a)
{
	if ((var.ifi - var.i0 == 0 && var.set == 0
			&& var.map[i][j] != var.data[1]) || (a) > (var.ifi - var.i0))
	{
		var.set = 1;
		var.i0 = i;
		var.ifi = i + a;
		var.j0 = j;
		var.jfi = j + a;
	}
	return (var);
}

struct s_input	try_squares(struct s_input var, int i, int j, int a)
{
	int	k;
	int	l;

	l = i;
	if (var.map[i][j] == var.data[1])
		return (var);
	while (l <= i + a)
	{
		k = j;
		while (k <= j + a)
		{
			if (l >= var.rows || k >= var.cols || var.map[l][k] == var.data[1])
				return (var);
			k++;
		}
		l++;
	}
	var = set_vals(var, i, j, a);
	var = try_squares(var, i, j, a + 1);
	return (var);
}

void	print_sol(struct s_input var, int i)
{
	int	j0aux;
	int	j;

	j0aux = var.j0;
	while (var.i0 <= var.ifi)
	{
		var.j0 = j0aux;
		while (var.j0 <= var.jfi)
			var.map[var.i0][var.j0++] = var.data[0];
		var.i0++;
	}
	while (i < var.rows)
	{
		j = 0;
		while (j < var.cols)
		{
			write(1, &var.map[i][j++], 1);
			write(1, " ", 1);
		}
		write(1, "\n", 1);
		i++;
	}
}

void	get_solution(struct s_input var)
{
	int	i;
	int	j;

	i = 0;
	var = initialize_coords(var);
	while (i < var.rows)
	{
		j = 0;
		while (j < var.cols)
		{
			var = try_squares(var, i, j, 0);
			j++;
		}
		i++;
	}
	print_sol(var, 0);
}

int	main(int ac, char **av)
{
	struct s_input	var;
	int				i;

	i = 1;
	while (i < ac)
	{
		if (error(av[i]) != 42)
		{
			write(1, "map error", 9);
			i++;
			continue ;
		}
		var = use_input(av[i]);
		get_solution(var);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
