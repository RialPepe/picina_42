/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocobos- <jocobos-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 11:38:24 by jocobos-          #+#    #+#             */
/*   Updated: 2023/08/12 21:14:51 by jocobos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h> 

void	ft_print_alphabet(void)
{
	char	letra;

	letra = 'a';
	while (letra <= 'z')
	{
		write (1, &letra, 1);
		letra++;
	}
}
