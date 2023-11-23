/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaresov <lmaresov@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 10:11:31 by lmaresov          #+#    #+#             */
/*   Updated: 2023/06/24 18:27:43 by lmaresov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "lib1.h"
#include "numbers.dict"
// int	main(int argc, char *argv[])
int	main(void)
{
	
	// char	*given_number;
	// char	*dict_file_name;
	
	
	int	rows_in_dict;
	
	
	// if (argc > 3 || argc < 2)
	// {
	// 	write(2, "Error\n", 7); 
	// 	return (0);
	// }
	// make_empty_dict(); char ***make_empty_dict(void){return (dictionary)}
	// function creating empty array 
	// with 40 bytes in first 32 are 2 bytes and in both are 12 bytes)
	rows_in_dict = 0;
	char ***dictionary = (char ***)malloc(40);
	while (rows_in_dict < 33)
	{
		dictionary[rows_in_dict] = (char **)malloc(2);
		dictionary[rows_in_dict][0] = (char *)malloc(12);
		dictionary[rows_in_dict][1] = (char *)malloc(12);
		rows_in_dict++;
	}
	// 
	get_dictionary("numbers.dict", dictionary);  
	// function is filling empty array with informations from "numbers.dict"
	// 32 are rows, 2 are (key, value) 12- key, 12 - value)

printf("%s", dictionary[0][0]);
return(0);
}



	
// 	if (argc == 2)
// 	{
// 		given_number = argv[1];
// 		if (!(is_numeric(given_number)) || 0 > argv[1]> 4294967295)
// 		{
// 			write(2, "Error\n", 7); 
// 			return (0);
// 		}

		
// 		// void n(char ***dictionary, char *given_number)
// 		 int nr;
// 		 nr = 0;
// 		 while (nr < 33)
// 		 {
// 			if (is_same_string(given_number, dictionary[nr][0]))
// 			{
// 				printf("%s", dictionary[nr][1]);
// 			}
// 			nr++;
// 		 }
// 		// 
		
// 	}

// 	if (argc == 3)
// 	{
// 		dict_file_name = argv[1];
// 		given_number = argv[2];
// 		if (!(is_numeric(given_number)) || (!dict_name_is_valid(dict_file_name)))
// 		{
// 			write(2, "Error\n", 7); 
// 			return (0);
// 		}
// 	}
		
		
			
// }
