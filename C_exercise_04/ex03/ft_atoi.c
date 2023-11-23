/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberneri < cberneri@student.42prague.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:14:37 by cberneri          #+#    #+#             */
/*   Updated: 2023/06/27 12:04:18 by cberneri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	sign;
	int	i;
	int	number;

	sign = 1;
	i = 0;
	number = 0;
	while (((str[i] >= 9 && str[i] <= 13) || str[i] == 32) && str[i])
		i++;
	while ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i] == '-')
			sign *= (-1);
		i++;
	}
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		number = number * 10 + (str[i] - '0');
		i++;
	}	
	number = number * sign;
	return (number);
}
/*
int		main(void)
{
	printf("%d\n", ft_atoi("---1234ab567"));
	printf("%d\n", ft_atoi("12s3334ab567"));
	printf("%d\n", ft_atoi(" ---+--+1234ab567"));
	return (0);
}
*/