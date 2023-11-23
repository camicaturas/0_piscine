/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaresov <lmaresov@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 17:26:05 by lmaresov          #+#    #+#             */
/*   Updated: 2023/06/24 20:31:29 by lmaresov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int	main(void)
{
	int	rows_in_dict;
	char buff[352];
	int	opened_file;
    char *dict_file_name = "numbers.dict";
	int	read_file;
	int b;
	int	row;
	int	z;
	// char **test = (char **)malloc(2);
	// test[0] = (char *)malloc(12);
	// test[1] = (char *)malloc(12);
    	
	rows_in_dict = 0;
	b = 0;
	row = 0;
	char ***dictionary = (char ***)malloc(40);
	while (rows_in_dict < 32)
	{
		dictionary[rows_in_dict] = (char **)malloc(2);
		dictionary[rows_in_dict][0] = (char *)malloc(12);
		dictionary[rows_in_dict][1] = (char *)malloc(12);
		rows_in_dict++;
	}

	opened_file = open(dict_file_name, O_RDONLY);
	if (opened_file == -1)
	{
		write(2,"Dict Error\n", 12);
		return(0);
	}
	read_file = read(opened_file, buff, 351);
	buff[read_file] = '\0';

	while (buff[b] != '\0' && row < 31)
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
		while (buff[b] != '\n' && buff[b] != '\0')
		{
			dictionary[row][1][z] = buff[b];
			z++;
			b++;
		}
		dictionary[row][1][z] = '\0';
		b++;
		row++;
	}
		close(opened_file);
	
	// while (buff [b] != '\0')
	// {
	// 	row = 0;
	// 	while (buff[b] != ':')
	// 	{
	// 		test[0][row] = buff[b];
	// 		row++;
	// 		b++;
	// 	}
	// 	test[0][row] = '\0';
	// 	b++;
	// 	row = 0;
	// 	while (buff[b] != '\n')
	// 	{
	// 		test[1][row] = buff[b];
	// 		row++;
	// 		b++;
	// 	}
	// 	printf("%s ", test[0]);
	// 	printf("%s \n", test[1]);
	// 	b++;
		
	// }
	

	
	return (0);
}

	