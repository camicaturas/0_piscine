/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaresov <lmaresov@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 17:26:05 by lmaresov          #+#    #+#             */
/*   Updated: 2023/06/24 18:23:42 by lmaresov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "numbers.dict"

void	get_dictionary(char *dictionary_name, char ***dictionary)
{
	char buff[352];
	int b;
	int	row;
	int	z;
    int	file_numbers_dict;
    int	read_file;
	
	b = 0;
	row = 0;
	file_numbers_dict = open(dictionary_name, O_RDONLY);
	if (file_numbers_dict == -1)
	{
		write(2,"Dict Error\n", 12);
		return;
	}
	read_file = read(file_numbers_dict, buff, 351);
	buff[read_file] = '\0';
	while (b < read_file && row < 33)
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
		while (buff[b] != '\n' && b < read_file)
		{
			dictionary[row][1][z] = buff[b];
			z++;
			b++;
		}
		dictionary[row][1][z] = '\0';
		b++;
		row++;
	}
	if (close(file_numbers_dict) == -1)
	{
		free(dictionary_name);
		return;
	}
	free(dictionary_name);
	return;
}
    
