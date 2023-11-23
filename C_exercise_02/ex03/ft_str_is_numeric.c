/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberneri < cberneri@student.42prague.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:14:37 by cberneri          #+#    #+#             */
/*   Updated: 2023/06/22 11:21:28 by cberneri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>
//#include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9') || (str[i] == '\0'))
			return (0);
		i++;
	}
	return (1);
}
/*
int main(void)
{
	char array[] = {'1',',','3' ,'6' ,'\0'};
	printf("the result is %d\n", (ft_str_is_numeric(array)));
	char array2[] = {'1','1','3' ,'6' ,'\0'};
	printf("the result is %d", (ft_str_is_numeric(array2)));
}
*/
