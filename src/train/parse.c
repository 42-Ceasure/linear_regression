/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:07:29 by cglavieu          #+#    #+#             */
/*   Updated: 2025/01/23 15:19:54 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <train.h>

int parse_line(char *line, double *mile_age, double *price)
{
	char *token;

	token = strtok(line, ",\n");
	if (!ft_isvalidint(token))
	{
		printf("Invalid mileage value: %s\n", token ? token : "NULL");
		return (0);
	}
	*mile_age = (int)ft_atoi(token);
	token = strtok(NULL, ",\n");
	if (!ft_isvalidint(token))
	{
		printf("Invalid price value: %s\n", token ? token : "NULL");
		return (0);
	}
	*price = (int)ft_atoi(token);
	return (1);
}

t_car	*parse_file(int fd, t_car *cars)
{
	t_car	car;
	char	*line;
	size_t	i;

	i = 0;
	while (get_next_line(fd, &line))
	{
		if (line[0] == '\n' || !parse_line(line, &car.km, &car.price))
		{
			free(line);
			continue ;
		}
		printf("Mileage: %f, Price: %f\n", car.km, car.price);
		free(line);
		cars[i++] = car;
	}
	if (i > 0)
	{
		cars[i].km = -1;
		cars[i].price = -1;
	}
	close(fd);
	return (cars);
}

t_car	*allocate_cars(size_t line_count)
{
	t_car	*cars;

	cars = (t_car *)malloc(sizeof(t_car) * (line_count + 1));
	if (cars == NULL)
	{
		printf("Error on memory allocation.\n");
		return (NULL);
	}
	return (cars);
}

t_car	*getdatafromfile(char *av)
{
	int		fd;
	int		line_count;
	t_car	*cars;

	line_count = ft_filelinecount(av);
	if (line_count <= 0)
		return (NULL);
	cars = allocate_cars(line_count);
	if (cars == NULL)
		return (NULL);
	fd = ft_fileopenr(av);
	if (fd == -1)
	{
		free(cars);
		return (NULL);
	}
	cars = parse_file(fd, cars);
	if (!cars)
	{
		printf("No valid data in fd.\n");
		free(cars);
		return (NULL);
	}	
	return (cars);
}
