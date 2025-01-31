/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:36:28 by cglavieu          #+#    #+#             */
/*   Updated: 2025/01/31 16:26:00 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <train.h>

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

t_car	*getdatafromfile(char *av, t_data *datas)
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
	cars = parse_file(fd, cars, datas);
	if (!cars)
	{
		printf("No valid data in fd.\n");
		free(cars);
		return (NULL);
	}
	return (cars);
}

void	save_theta(t_res result)
{
	int	fd;

	fd = ft_fileopenrwc("./theta_val");
	if (fd == -1)
		perror("Error opening or creating file");
	else
	{
		if (dprintf(fd, "%f,%f\n",
				result.theta_0,
				result.theta_1) < 0)
			perror("Error writing to file");
		else
		{
			printf("Theta values and normalization data saved:\n");
			printf("Theta_0: %f, Theta_1: %f\n",
				result.theta_0,
				result.theta_1);
		}
		close(fd);
	}
}
