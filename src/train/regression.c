/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regression.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:07:50 by cglavieu          #+#    #+#             */
/*   Updated: 2025/01/24 13:33:05 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <train.h>

// void	normalize_data(t_car *cars, t_data *datas)
// {
// 	datas->min_km = cars[0].km;
// 	datas->max_km = cars[0].km;
// 	datas->min_price = cars[0].price;
// 	datas->max_price = cars[0].price;
// 	for (size_t i = 0; cars[i].km != -1; i++)
// 	{
// 		if (cars[i].km < datas->min_km)
// 			datas->min_km = cars[i].km;
// 		if (cars[i].km > datas->max_km)
// 			datas->max_km = cars[i].km;
// 		if (cars[i].price < datas->min_price)
// 			datas->min_price = cars[i].price;
// 		if (cars[i].price > datas->max_price)
// 			datas->max_price = cars[i].price;
// 	}
// 	for (size_t i = 0; cars[i].km != -1; i++)
// 	{
// 		if (datas->max_km != datas->min_km)
// 			cars[i].km = (cars[i].km - datas->min_km)
// 				/ (datas->max_km - datas->min_km);
// 	}
// }

// void	calculate_theta(t_car *cars, t_data *datas)
// {
// 	double sum_x = 0.0;
// 	double sum_y = 0.0;
// 	double sum_xy = 0.0;
// 	double sum_xx = 0.0;
// 	size_t car_count = 0;

// 	////////////////////
// 	while (cars[car_count].km != -1)
// 	{
// 		sum_x += cars[car_count].km;
// 		sum_y += cars[car_count].price;
// 		sum_xy += cars[car_count].km * cars[car_count].price;
// 		sum_xx += cars[car_count].km * cars[car_count].km;
// 		car_count++;
// 	}
// 	double mean_x = sum_x / car_count;
// 	double mean_y = sum_y / car_count;
// 	datas->theta_1 = (sum_xy - car_count * mean_x * mean_y) / (sum_xx - car_count * mean_x * mean_x);
// 	datas->theta_0 = mean_y - (datas->theta_1) * mean_x;
// }

size_t normalize_data(t_car *cars, t_data *datas)
{
    size_t car_count = 0;
    datas->min_km = cars[0].km;
    datas->max_km = cars[0].km;
    datas->min_price = cars[0].price;
    datas->max_price = cars[0].price;

    // Trouver les valeurs min et max pour km et price
    while (cars[car_count].km != -1)
    {
        if (cars[car_count].km < datas->min_km)
            datas->min_km = cars[car_count].km;
        if (cars[car_count].km > datas->max_km)
            datas->max_km = cars[car_count].km;
        if (cars[car_count].price < datas->min_price)
            datas->min_price = cars[car_count].price;
        if (cars[car_count].price > datas->max_price)
            datas->max_price = cars[car_count].price;
        car_count++;
    }

    // Appliquer la normalisation uniquement aux kilomètres entre 0 et 1
    for (size_t i = 0; i < car_count; i++)
    {
        if (datas->max_km != datas->min_km)
            cars[i].km = (cars[i].km - datas->min_km) / (datas->max_km - datas->min_km);
    }

    return car_count; // Retourne car_count
}

void calculate_theta(t_car *cars, t_data *datas)
{
    double sum_x = 0.0;
    double sum_y = 0.0;
    double sum_xy = 0.0;
    double sum_xx = 0.0;

    size_t car_count = normalize_data(cars, datas);
    for (size_t i = 0; i < car_count; i++)
    {
        sum_x += cars[i].km;  // Utiliser km normalisé
        sum_y += cars[i].price;  // Utiliser price non modifié
        sum_xy += cars[i].km * cars[i].price;  // Produit entre km normalisé et price non modifié
        sum_xx += cars[i].km * cars[i].km;  // km normalisé
    }
    double mean_x = sum_x / car_count;
    double mean_y = sum_y / car_count;
    datas->theta_1 = (sum_xy - car_count * mean_x * mean_y) / (sum_xx - car_count * mean_x * mean_x);
    datas->theta_0 = mean_y - (datas->theta_1) * mean_x;
}

void	save_theta(t_data datas)
{
	int	fd;

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
