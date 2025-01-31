/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:48:55 by cglavieu          #+#    #+#             */
/*   Updated: 2025/01/31 14:08:31 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <train.h>

void	print_datas(t_data datas, t_car *car)
{
	size_t	i;

	i = 0;
	printf("car_count:\t%zu\n", datas.car_count);
	printf("min_km: \t%f\nmax_km: \t%f\nmin_price:\t%f\nmax_price:\t%f\n",
		datas.min_km,
		datas.max_km,
		datas.min_price,
		datas.max_price);
	while (i < datas.car_count)
	{
		printf("car_%zu\t:\tkm: %f\tprice: %f\n", i, car[i].km, car[i].price);
		i++;
	}
}

void	init_rules(t_rul *rules)
{
	rules->learning_rate = LEARNING_RATE;
	rules->iterations = ITERATIONS;
}

void	init_result(t_res *result)
{
	result->theta_0 = 0;
	result->theta_1 = 0;
}

void	init_datas(t_data *datas)
{
	datas->car_count = 0;
	datas->max_km = 0;
	datas->max_price = 0;
	datas->min_km = INT_MAX;
	datas->min_price = INT_MAX;
}

int		main(int ac, char **av)
{
	t_rul	rules;
	t_data	datas;
	t_car	*cars;
	t_res	result;

	init_datas(&datas);
	init_rules(&rules);
	init_result(&result);
	if (ac == 2)
	{
		cars = getdatafromfile(av[1], &datas);
		// print_datas(datas, cars);
		if (cars != NULL)
		{
			train_model(rules, datas, cars, &result);
			save_theta(result);
		}
		free(cars);
	}
	return (0);
}
