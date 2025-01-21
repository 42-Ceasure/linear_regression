/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:48:55 by cglavieu          #+#    #+#             */
/*   Updated: 2025/01/21 18:00:57 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <train.h>

typedef struct	s_car
{
	int	km;
	int	price;
}				t_car;

int is_valid_integer(const char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int parse_line(char *line, int *mile_age, int *price)
{
	char *token;

	token = strtok(line, ",\n");
	if (token == NULL || !is_valid_integer(token))
	{
		printf("Invalid mileage value: %s\n", token);
		return (0);
	}
	*mile_age = ft_atoi(token);
	token = strtok(NULL, ",\n");
	if (token == NULL || !is_valid_integer(token))
	{
		printf("Invalid price value: %s\n", token);
		return (0);
	}
	*price = ft_atoi(token);
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
			continue;
		}
		printf("Mileage: %d, Price: %d\n", car.km, car.price);
		free(line);
		cars[i++] = car;
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
	printf("linecount:%i\n", line_count);
	if (line_count == -1)
	{
		printf("Error opening or reading file.\n");
		return (NULL);
	}
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
	if (cars)
		return (cars);
	return (NULL);
}

int		main(int ac, char **av)
{
	t_car	*cars;

	if (ac == 2)
	{
		cars = getdatafromfile(av[1]);
		free(cars);
	}
	return (0);
}
