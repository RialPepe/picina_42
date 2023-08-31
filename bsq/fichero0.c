/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fichero0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-c <pperez-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:35:04 by pperez-c          #+#    #+#             */
/*   Updated: 2023/08/30 18:38:17 by pperez-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_atoi(char *str)
{
	int	aux;
	int	numf;

	numf = 0;
	aux = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
	{
		str++;
	}
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			aux++;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		numf = (numf * 10) + (*str - '0');
		str++;
	}
	if (aux % 2 != 0)
		numf = -numf;
	return (numf);
}

int	error2(char *filecontent);


char	*get_file_content(char *filename, int i, int	character_count)
{
	int		fd;
	char	character;
	int		character_count;
	char	*character_array;
	char	*aux;

	character_count = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		if (error2(filename) == 42)
			return (filename);
		return ("e");
	}
	while (read(fd, &character, 1) > 0)
		character_count++;
	close(fd);
	fd = open(filename, O_RDONLY);
	character_array = (char *)malloc(character_count * sizeof(char));
	while (read(fd, &character, 1) > 0)
	{
		character_array[i] = character;
		i++;
	}
	close(fd);
	aux = character_array;
	free(character_array);
	return (aux);
}

void	print_arr(char *str)
{
	printf("%s", str);
}

void	get_data(char *data, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\n')
	{
		i++;
	}
	i--;
	while (j < 3)
	{
		data[j] = str[i - j];
		j++;
	}
}

int	get_rows(char end, char *filecontent)
{
	int		i;
	int		j;
	char	*num;

	i = 0;
	j = 0;
	while (filecontent[i] != end)
	{
		i++;
	}
	num = (char *)malloc(i * sizeof(char));
	while (j < i)
	{
		num[j] = filecontent[j];
		j++;
	}

	return (ft_atoi(num));
}
