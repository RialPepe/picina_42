/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-c <pperez-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:35:04 by pperez-c          #+#    #+#             */
/*   Updated: 2023/08/30 18:35:42 by pperez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	check_chars(struct s_input var, char *filecontent);
int	at_least_one(struct s_input var, char *filecontent);
int	samecols(char *filecontent, int i, int aux);
int	checknl(char *filecontent, int rows);
int	checkfirstline(char *filecontent);
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

int	error2(char *filecontent)
{
	struct s_input	errors;

	if (checkfirstline(filecontent) != 42)
		return (0);
	get_data(errors.data, filecontent);
	if (samecols(filecontent, 0, 0) != 42
		|| at_least_one(errors, filecontent) != 42)
		return (0);
	errors.rows = get_rows(errors.data[2], filecontent);
	if (checknl(filecontent, errors.rows) == 42 || check_chars(errors,
			filecontent) != 42 || chars_1strow(errors) != 42)
		return (0);
	return (42);
}

int	chars_1strow(struct s_input errors)
{
	int	i;

	i = 0;
	if (errors.data[0] == errors.data[1] || errors.data[0] == errors.data[2]
		|| errors.data[1] == errors.data[2])
		return (0);
	while (i <= 2)
	{
		if (errors.data[i] < 32 || errors.data[i] > 126)
			return (0);
		i++;
	}
	return (42);
}

int	error(char *filename)
{
	char			*filecontent;
	struct s_input	errors;

	filecontent = get_file_content(filename);
	if (*filecontent == 'e')
		return (0);
	if (checkfirstline(filecontent) != 42)
		return (0);
	get_data(errors.data, filecontent);
	if (samecols(filecontent, 0, 0) != 42 || at_least_one(errors,
			filecontent) != 42)
		return (0);
	errors.rows = get_rows(errors.data[2], filecontent);
	if (checknl(filecontent, errors.rows) == 42 || check_chars(errors,
			filecontent) != 42 || chars_1strow(errors) != 42)
		return (0);
	return (42);
}

char	*malloc_churr(char *fcont)
{
	char	*sol;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (fcont[i])
		i++;
	sol = (char *)malloc(i * sizeof(char));
	while (j <= i)
	{
		sol[j] = fcont[j];
		j++;
	}
	return (sol);
}