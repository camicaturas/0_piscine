/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberneri < cberneri@student.42prague.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:14:37 by cberneri          #+#    #+#             */
/*   Updated: 2023/06/13 14:15:52 by cberneri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
#include <unistd.h>
#include <stdio.h> 

 */
void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div;

	if (*b != 0)
	{
		div = *a / *b;
		*b = *a % *b;
		*a = div;
	}
}

/*
int	main(void)
{
	int div;
	int	a;
	int	b;

	a = 13;
	b = 2;
	div = 123213;
	ft_ultimate_div_mod(&a, &b);

	//	printf("result de division de A x B en *A: %d\n", div);
//		printf("result de dividend de A x B en *B: %d\n", *b);

}
	*/