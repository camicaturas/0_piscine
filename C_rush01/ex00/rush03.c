/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberneri < cberneri@student.42prague.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 11:54:03 by cberneri          #+#    #+#             */
/*   Updated: 2023/06/11 18:21:57 by cberneri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	content(int x, int y, int column, int row)
{
	while (column < x)
	{
		if (row == 0 || row == (y - 1))
		{
			if (column == 0)
				ft_putchar('A');
			else if (column > 0 && column < (x - 1))
				ft_putchar('B');
			else
				ft_putchar('C');
			column++;
		}
		else
		{
			if (column == 0)
				ft_putchar('B');
			else if (column > 0 && column < (x - 1))
				ft_putchar(' ');
			else
				ft_putchar('B');
			column++;
		}
	}	
}

void	rush(int x, int y)
{
	int	column;
	int	row;

	column = 0;
	row = 0;
	if (x <= 0 || y <= 0)
	{
		write (1, "X or Y cannot be negative or zero", 33);
		return ;
	}
	if (x > 100 || y > 100)
	{
		write (1, "The value of X or Y cannot exceed 100", 37);
		return ;
	}
	while (row < y)
	{
		content(x, y, column, row);
		ft_putchar('\n');
		row++;
	}
}
