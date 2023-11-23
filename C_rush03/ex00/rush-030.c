/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-029.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaresov <lmaresov@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 17:26:05 by lmaresov          #+#    #+#             */
/*   Updated: 2023/06/25 18:00:34 by lmaresov         ###   ########.fr       */
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

int	str_len(char *given_number)
{
	int i;
	i = 0;
	while (given_number[i] != '\0')
	{
		i++;
	}
	return(i);
}


int	find_given_number(char ***dictionary, char *given_number)
{
	int	r;
	r = 0;
	while (r < 32)
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
void get_zeros(int len, char ***dictionary)
{
	int	j;
	char temp[20];
						
	j = 0;
						
	temp[j] = 1 + '0';
	j++;
	while (j < len)
	{
		temp[j] = '0';
		j++;
	}
					
	temp[j] = '\0';
	find_given_number(dictionary, temp);
}

void	print_number_in_words(char ***dictionary, char *given_number)
{
	// int	nb;
	int	len;
	int	len1;
	int	i;
	int	j;
	char temp[20];
	char	temp2[2];
	
	i = 0;
	j = 0;
	if (find_given_number(dictionary, given_number))
		return;
	else
	{
		len = str_len(given_number);
		// printf("len1 %d", len);
		while (len > 0 && given_number[i] != '\0')
		{
				j = 0;
				if ((len) % 3 == 1)
				{	
					if (given_number[i] != '0')
					{
						temp2[0] = given_number[i];
						find_given_number(dictionary, temp2);
					}
					if (len >2)
					{
						get_zeros(len, dictionary);	
					}
					len--;
					i++;
						
					// printf("len2 %d", len);
					
				}
				
				
				if ((len) % 3 == 0)
				{
					if (len >1)
					{
						j = 0;
						if (given_number[i] != '0')
						{
							temp2[0] = given_number[i];
							find_given_number(dictionary, temp2);
							if (len > 8 )
								len1 = len-6;
							else if (len > 5)
								len1 = len-3;
							else	
								len1 = len;
							
							temp[j] = 1 + '0';
							j++;
							while (j < len1)
							{
								temp[j] = '0';
								j++;
							}
							temp[j] = '\0';
							find_given_number(dictionary, temp);
							len--;
							i++;
						}
						else
							{
								len--;
								i++;
							}
					}
				}
				
				// printf("len3 %d", len);
				if (len % 3 == 2)
				{
					j = 0;
					if( given_number[i] != '0')
					{
						// printf("lena %d", len);
						if (len > 1)
						{
							if (given_number[i] > '0')
							{
								temp[j] = given_number[i];
								if (given_number[i] == '1')
								{
									temp[1] = given_number[i+1];
									temp[2] = '\0';
									find_given_number(dictionary, temp);
									i++;
									len--;
									i++;
									if (len >2)
									{
										get_zeros(len, dictionary);	
									}
									
									len--;
									
								}
								else
								{
									j++;
									if (len > 7 )
										len1 = len-6;
									else if (len > 4)
										len1 = len-3;
									else	
										len1 = len;
									while (j < len1)
									{
										temp[j] = '0';
										j++;
										i++;
									}
									temp[j] = '\0';
									find_given_number(dictionary, temp);
									len--;
									
								}
							}
							// printf("lenb %d", len);
						}
						
						else 
						{	

							if (given_number[i] > '0')
							{
								temp[j] = given_number[i];
								if (given_number[i] == '1')
								{
									temp[1] = given_number[i+1];
									temp[2] = '\0';
									find_given_number(dictionary, temp);
									i++;
									len--;
									i++;
									if (len >2)
									{
										get_zeros(len, dictionary);	
									}
									len--;
									return;
								}
								else
								{
									j++;
									len1 = len;
									while (j < len1)
									{
										temp[j] = '0';
										j++;
										
									}
									temp[j] = '\0';
									find_given_number(dictionary, temp);
									len--;
									temp[0] = given_number[i+1];
									temp[1] = '\0';
									find_given_number(dictionary, temp);
									len--;
									i++;
									return;
								}
							}
							// else
							// {
							// 	len--;
							// 	i++;
							// }
							
						}
						
					}
					else
						{
							len--;
							i++;
						}
					
					
				}	
				// printf("len4 %d", len);
				
			}
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
		// find_given_number(dictionary, given_number);
		print_number_in_words(dictionary, given_number);
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

	
