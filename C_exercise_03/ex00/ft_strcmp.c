/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberneri < cberneri@student.42prague.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:09:57 by cberneri          #+#    #+#             */
/*   Updated: 2023/06/26 14:19:17 by cberneri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	if ((*s1 - *s2) < 0)
		return (-1);
	else if ((*s1 - *s2) > 0)
		return (1);
	else
		return (0);
}

/*
int main()
{
	char *s1;
	char *s2;
	s1 = "b"; //b is 98
	s2 = "g"; //g is 103
	printf("Result is: %d", ft_strcmp(s1, s2));
}
*/