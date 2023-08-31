/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fichero1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-c <pperez-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:35:04 by pperez-c          #+#    #+#             */
/*   Updated: 2023/08/30 18:39:43 by pperez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int				ft_atoi(char *str);
char			*get_file_content(char *filename, int i, int character_count);
void			print_arr(char *str);
void			get_data(char *data, char *str);
int				get_rows(char end, char *filecontent);

int				count_cols(char *fcont);
char			**map_dim(int rows, int cols);
char			**gen_map_arr(char *fcont, int rows, int cols, int k);
int				samecols(char *filename, char *filecontent, int i, int aux);

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

int	count_cols(char *fcont)
{
	int	i;
	int	cont;

	i = 0;
	cont = 0;
	while (fcont[i] != '\n')
		i++;
	i++;
	while (fcont[i] != '\n')
	{
		cont++;
		i++;
	}
	return (cont);
}

char	**map_dim(int rows, int cols)
{
	char	**map;
	int		i;

	i = 0;
	map = (char **)malloc(rows * sizeof(char *));
	while (i < rows)
	{
		map[i] = (char *)malloc(cols * sizeof(char));
		i++;
	}
	return (map);
}

char	**gen_map_arr(char *fcont, int rows, int cols, int k)
{
	int		i;
	int		j;
	int		cont;
	char	**map;

	j = 0;
	map = map_dim(rows, cols);
	i = 0;
	cont = 0;
	while (fcont[i] != '\n')
		i++;
	i++;
	while (j < rows)
	{
		k = 0;
		while (k < cols)
		{
			map[j][k] = fcont[i++];
			k++;
		}
		i++;
		j++;
	}
	return (map);
}

struct s_input	use_input(char *filename)
{
	char			*filecontent;
	struct s_input	var;

	filecontent = get_file_content(filename, 0);
	get_data(var.data, filecontent);
	var.rows = get_rows(var.data[2], filecontent);
	var.cols = count_cols(filecontent);
	var.map = gen_map_arr(filecontent, var.rows, count_cols(filecontent), 0);
	return (var);
}

struct s_input	initialize_coords(struct s_input var)
{
	var.i0 = 0;
	var.ifi = 0;
	var.j0 = 0;
	var.jfi = 0;
	var.set = 0;
	return (var);
}