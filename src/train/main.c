/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:48:55 by cglavieu          #+#    #+#             */
/*   Updated: 2025/01/23 02:02:35 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <train.h>

typedef struct	s_car
{
	double	km;
	double	price;
}				t_car;

typedef struct	s_data
{
	double	min_km;
    double	max_km;
    double	min_price;
    double	max_price;
    double	theta_0;
    double	theta_1;
}				t_data;

int is_valid_integer(const char *str)
{
	if (*str == '\0')
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int parse_line(char *line, double *mile_age, double *price)
{
	char *token;

	token = strtok(line, ",\n");
	if (!is_valid_integer(token))
	{
		printf("Invalid mileage value: %s\n", token ? token : "NULL");
		return (0);
	}
	*mile_age = (int)ft_atoi(token);
	token = strtok(NULL, ",\n");
	if (!is_valid_integer(token))
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

void normalize_data(t_car *cars, t_data *datas)
{
	datas->min_km = cars[0].km;
	datas->max_km = cars[0].km;
	datas->min_price = cars[0].price;
	datas->max_price = cars[0].price;

	for (size_t i = 0; cars[i].km != -1; i++)
	{
		if (cars[i].km < datas->min_km)
			datas->min_km = cars[i].km;
		if (cars[i].km > datas->max_km)
			datas->max_km = cars[i].km;
		if (cars[i].price < datas->min_price)
			datas->min_price = cars[i].price;
		if (cars[i].price > datas->max_price)
			datas->max_price = cars[i].price;
	}
	for (size_t i = 0; cars[i].km != -1; i++)
	{
		if (datas->max_km != datas->min_km)
			cars[i].km = (cars[i].km - datas->min_km) * 100.0 / (datas->max_km - datas->min_km);
		if (datas->max_price != datas->min_price)
			cars[i].price = (cars[i].price - datas->min_price) * 100.0 / (datas->max_price - datas->min_price);
	}
}

// void calculate_theta(t_car *cars, t_data *datas)
// {
//     double sum_x;
//     double sum_y;
//     double sum_xy;
//     double sum_xx;
//     size_t car_count;
//     double mean_x;
//     double mean_y;

//     sum_x = 0.0f;
//     sum_y = 0.0f;
//     sum_xy = 0.0f;
//     sum_xx = 0.0f;
//     car_count = 0;

//     while (cars[car_count].km != -1)
//     {
//         sum_x += cars[car_count].km;
//         sum_y += cars[car_count].price;
//         sum_xy += cars[car_count].km * cars[car_count].price;
//         sum_xx += cars[car_count].km * cars[car_count].km;
//         car_count++;
//     }

//     mean_x = sum_x / car_count;
//     mean_y = sum_y / car_count;

// 	printf("Sum_X: %f, Sum_Y: %f, Sum_XY: %f, Sum_XX: %f\n", sum_x, sum_y, sum_xy, sum_xx);
// 	printf("Mean_X: %f, Mean_Y: %f\n", mean_x, mean_y);


//     datas->theta_1 = (sum_xy - car_count * mean_x * mean_y) / (sum_xx - car_count * mean_x * mean_x);
//     datas->theta_0 = mean_y - datas->theta_1 * mean_x;

// 	printf("Max Price: %f, Min Price: %f\n", datas->max_price, datas->min_price);
// 	printf("Max KM: %f, Min KM: %f\n", datas->max_km, datas->min_km);
//     printf("Car count: %zu\n", car_count);
// 	printf("Before denormalization: Theta_0 = %f, Theta_1 = %f\n", datas->theta_0, datas->theta_1);
// 	// Dé-normalisation des coefficients
//     // Aplliquons les bonnes transformations pour revenir à des coefficients réels
//     datas->theta_1 = datas->theta_1 * (datas->max_price - datas->min_price) / (datas->max_km - datas->min_km);
// 	datas->theta_0 = datas->theta_0 * (datas->max_price - datas->min_price) / 100 + datas->min_price - datas->theta_1 * (datas->min_km + datas->max_km) / 2;
//     printf("Denormalized Theta_0 = %f, Denormalized Theta_1 = %f\n", datas->theta_0, datas->theta_1);
// }

void calculate_theta(t_car *cars, t_data *datas)
{
	double sum_x = 0.0;
	double sum_y = 0.0;
	double sum_xy = 0.0;
	double sum_xx = 0.0;
	size_t car_count = 0;

	while (cars[car_count].km != -1)
    {
        sum_x += cars[car_count].km;
        sum_y += cars[car_count].price;
        sum_xy += cars[car_count].km * cars[car_count].price;
        sum_xx += cars[car_count].km * cars[car_count].km;
        car_count++;
    }
	// for (i = 0; i < car_count; i++) {
	// 	sum_x += cars[i].km;
	// 	sum_y += cars[i].price;
	// 	sum_xy += cars[i].km * cars[i].price;
	// 	sum_xx += cars[i].km * cars[i].km;
	// }
	double mean_x = sum_x / car_count;
	double mean_y = sum_y / car_count;
	datas->theta_1 = (sum_xy - car_count * mean_x * mean_y) / (sum_xx - car_count * mean_x * mean_x);
	datas->theta_0 = mean_y - (datas->theta_1) * mean_x;
}

void save_theta(t_data datas)
{
	int fd;

	fd = ft_fileopenrwc("/home/cglavieu/Code/linear_regression/theta_val");
	if (fd == -1)
		perror("Error opening or creating file");
	else
	{
		if (dprintf(fd, "%f,%f,%f,%f,%f,%f\n",
			datas.theta_0,
			datas.theta_1,
			datas.min_km,
			datas.max_km,
			datas.min_price,
			datas.max_price) < 0)
			perror("Error writing to file");
		else
			printf("Theta values and normalization data saved: Theta_0 = %f, Theta_1 = %f\n", datas.theta_0, datas.theta_1);
		close(fd);
	}
}

int		main(int ac, char **av)
{
	t_car	*cars;
	t_data	datas;

	datas.theta_0 = 0.0f;
	datas.theta_1 = 0.0f;
	if (ac == 2)
	{
		cars = getdatafromfile(av[1]);
		if (cars != NULL)
		{
			// normalize_data(cars, &datas);
			for (size_t i = 0; cars[i].km != -1; i++)
				printf("Car %zu -> Normalized Mileage: %f, Normalized Price: %f\n", i, cars[i].km, cars[i].price);
			calculate_theta(cars, &datas);
			save_theta(datas);
		}
		free(cars);
	}
	return (0);
}
