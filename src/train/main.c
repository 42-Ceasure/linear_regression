/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:48:55 by cglavieu          #+#    #+#             */
/*   Updated: 2025/01/24 13:59:38 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <train.h>

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
			for (size_t i = 0; cars[i].km != -1; i++)
				printf("Car %zu -> Normalized Mileage: %f, Normalized Price: %f\n", i, cars[i].km, cars[i].price);
			calculate_theta(cars, &datas);
			save_theta(datas);
		}
		free(cars);
	}
	return (0);
}
