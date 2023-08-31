/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-c <pperez-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:35:04 by pperez-c          #+#    #+#             */
/*   Updated: 2023/08/30 18:39:31 by pperez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char		*get_file_content(char *filename, int i);
void		print_arr(char *str);
void		get_data(char *data, char *str);
int			get_rows(char end, char *filecontent);

// var[2] == vacio var[1] == obstaculo var[0] == lleno
struct		s_input
{
	int		rows;
	int		cols;
	char	data[4];
	char	**map;
	int		i0;
	int		j0;
	int		ifi;
	int		jfi;
	int		set;
};


int	check_chars(struct s_input var, char *filecontent)
{
	int	i;

	i = 0;
	while (filecontent[i] != '\n' || !filecontent[i])
		i++;
	i++;
	while (filecontent[i])
	{
		if (filecontent[i] == var.data[2] || filecontent[i] == var.data[1]
			|| filecontent[i] == '\n')
			i++;
		else
			return (0);
	}
	return (42);
}


int	at_least_one(struct s_input var, char *filecontent)
{
	int	i;

	i = 0;
	while (filecontent[i] != '\n')
		i++;
	i++;
	while (filecontent[i])
	{
		if (filecontent[i] == var.data[2])
			return (42);
		i++;
	}
	return (0);
}


int	samecols(char *filecontent, int i, int aux)
{
	int	cont;

	cont = 0;
	while (filecontent[i] && filecontent[i] != '\n')
		i++;
	i++;
	while (filecontent[i] && filecontent[i++] != '\n')
		aux++;
	while (filecontent[i] != '\0')
	{
		cont = 0;
		while (filecontent[i] && filecontent[i] != '\n')
		{
			cont++;
			i++;
		}
		if (cont != aux)
			return (0);
		i++;
	}
	if (cont == aux)
		return (42);
	return (0);
}


int	checknl(char *filecontent, int rows)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (filecontent[i])
	{
		if (filecontent[i] == '\n')
			count++;
		i++;
	}
	if (count == rows)
		return (42);
	return (0);
}


int	checkfirstline(char *filecontent)
{
	int	i;

	i = 0;
	while (filecontent[i] && filecontent[i] != '\n')
		i++;
	i--;
	if (i < 3)
		return (0);
	i -= 3;
	while (i >= 0)
	{
		if (!(filecontent[i] >= '0' && filecontent[i] <= '9'))
		{
			write(1, &filecontent[i], 1);
			return (0);
		}
		i--;
	}
	return (42);
}



