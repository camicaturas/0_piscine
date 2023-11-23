/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-025.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaresov <lmaresov@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 17:26:05 by lmaresov          #+#    #+#             */
/*   Updated: 2023/06/25 11:02:31 by lmaresov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	fill_dictionary(char ***dictionary, char * dict_file_name)
{
	// int	a;
	char buff[1001];
	int	opened_file;
	int	read_file;
	int b;
	int	z;
	int	row;
	
	b = 0;
	z = 0;	
	opened_file = open(dict_file_name, O_RDONLY);
	if (opened_file == -1)
	{
		write(2,"Dict Error\n", 12);
		return;
	}
	read_file = read(opened_file, buff, 1000);
	buff[read_file] = '\0';		
	row = 0;
	while (buff [b] != '\0')
	{	
		
		z = 0;
		while (buff[b] != ':')
		{
			dictionary[row][0][z] = buff[b];
			z++;
			b++;
		}
		dictionary[row][0][z] = '\0';
		b++;
		z = 0;
		while (buff[b] != '\n')
		{
			dictionary[row][1][z] = buff[b];
			z++;
			b++;
		}
		dictionary[row][1][z] = '\0';
		b++;
		row++;
		
	}

	// a = 0;
	// while (a < row)
	// {
	// 	printf("%s", dictionary[a][0]);
	// 	printf("%s \n", dictionary[a][1]);
	// 	a++;
	// }
	close(opened_file);
}

int length(long nb)
{
	int length;

	length = 0;
	while (nb > 0)
	{
		nb = nb / 10;
		length++;
	}
	return (length);
}

int	ft_atoi(char *str)
{
	int	i;
	int	j;
	int	l;

	j = 1;
	i = 0;
	l = 0;
	while ((str[i] == ' ') || (str[i] == '\t')
		|| (str[i] == '\n') || (str[i] == '\f')
		|| (str[i] == '\r') || (str[i] == '\v'))
		i++;
	while ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i] == '-')
			j *= (-1);
		i++;
	}
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		l = l * 10 + (str[i] - '0');
		i++;
	}	
	l = l * j;
	return (l);
}

int	is_same_nbstr(char *s1, char *s2)
{
	unsigned int c;

	c = 0;
	while (s1[c] == s2[c])
	{
		if (s1[c] == '\0')
		{
			return (1);
		}
		c++;
	}
	return (0);
}

int	find_given_number(char ***dictionary, char *given_number)
{
	int	r;
	r = 0;
	while (r < 40)
	{
		if (is_same_nbstr(given_number, dictionary[r][0]))
		{
				printf("%s \n" , dictionary[r][1]);
				return(1);
		}
		r++;
	}
	return (0);
}

void	print_number_in_words(char ***dictionary, char *given_number)
{
	int	nb;
	int	len;
	
	
	if (!find_given_number(dictionary, given_number))
	{
		nb = ft_atoi(given_number)
		while (nb > 0)
		{
			len = length(nb);
			find_given_number(dictionary, );
			
			
		}
		return;
	}
	else
	{
		return;
	}
}


int	main(int argc, char *argv[])
{
	char *dict_file_name = "numbers.dict";
	int	number_row;
	char *given_number;

	
	if (argc < 2 || argc >3)
	{
		write(1, "Error\n", 7);
		return (0);
	}
	
	number_row = 0;
	char ***dictionary = (char ***)malloc(240);
	while (number_row < 60)
	{
		dictionary[number_row] = (char **)malloc(2);
		dictionary[number_row][0] = (char *)malloc(20);
		dictionary[number_row][1] = (char *)malloc(20);
		number_row++;
	}
	
	if (argc == 2)
	{
		given_number = argv[1];
		// if (!is_numeric(given_number))
		// {
		// 	write(1, "Error\n", 7);
		// 	return (0);
		// }
		fill_dictionary(dictionary, dict_file_name);
		find_given_number(dictionary, given_number);
		return(0);
	}
	
	if (argc == 3)
	{
		given_number = argv[2];
		dict_file_name = argv[1];
		// if (!is_numeric(given_number) || !is_valid(dict_file_name))
		// {
		// 	write(1, "Error\n", 7);
		// 	return (0);
		// }
		// fill_dictionary(dictionary, dict_file_name);
		
		return(0);
	}
	

	free(dictionary);
	return (0);
}

	
