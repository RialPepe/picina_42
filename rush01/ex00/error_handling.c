/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocobos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 18:27:11 by jocobos-          #+#    #+#             */
/*   Updated: 2023/08/20 19:00:53 by jocobos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_strlen(char arr[])
{
	int	i;

	i = 0;
	while (arr[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	check_digits(char arr[])
{
	int	i;

	i = 0;
	while (i < 31)
	{
		if (i % 2 == 0 && !(arr[i] >= '1' && arr[i] <= '4'))
			return (0);
		if (i % 2 != 0 && !(arr[i] == 32))
			return (0);
		i++;
	}
	return (42);
}

int	is_valid_input(int argc, char input[])
{
	if (argc != 2 || ft_strlen(input) != 31 || check_digits(input) == 0)
		return (0);
	return (42);
}
