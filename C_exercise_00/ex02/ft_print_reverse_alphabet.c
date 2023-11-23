/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberneri < cberneri@student.42prague.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:32:35 by cberneri          #+#    #+#             */
/*   Updated: 2023/06/08 10:32:02 by cberneri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char	rev_alphabet;

	rev_alphabet = 'z';
	while (rev_alphabet >= 'a')
	{
		write(1, &rev_alphabet, 1);
		rev_alphabet--;
	}
}
