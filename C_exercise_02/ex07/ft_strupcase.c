/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberneri < cberneri@student.42prague.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:14:37 by cberneri          #+#    #+#             */
/*   Updated: 2023/06/22 11:58:23 by cberneri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>
//#include <stdio.h>

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 'a' && str[i] <= 'z'))
		{
			str[i] = str[i] - 32;
		}		
		i++;
	}
	return (str);
}
/*
int main(void)
{
	//char array[] = {'n','a','i' ,'l' ,'\0'};
	char array[] = "Hello world this is 42 PRaGuE!";
	printf("the result is %s]\n", (ft_strupcase(array)));
	char array2[] = "xx33xx x0xx xx is 42 PRaGuE!";
	printf("the result is %s", (ft_strupcase(array2)));
}
*/