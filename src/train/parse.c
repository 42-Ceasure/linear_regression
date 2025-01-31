/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:07:29 by cglavieu          #+#    #+#             */
/*   Updated: 2025/01/31 14:03:15 by cglavieu         ###   ########.fr       */
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
	*price = ft_atoi(token);
	return (1);
}

void	update_datas(t_car car, t_data *datas)
{
	if (datas->min_km > car.km)
		datas->min_km = car.km;
	if (datas->min_price > car.price)
		datas->min_price = car.price;
	if (datas->max_km < car.km)
		datas->max_km = car.km;
	if (datas->max_price < car.price)
		datas->max_price = car.price;
}

t_car	*parse_file(int fd, t_car *cars, t_data *datas)
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
		update_datas(car, datas);
		free(line);
		cars[i++] = car;
	}
	if (i > 0)
	{
		datas->car_count = i;
		cars[i].km = -1;
		cars[i].price = -1;
	}
	close(fd);
	return (cars);
}
