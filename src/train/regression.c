/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regression.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:07:50 by cglavieu          #+#    #+#             */
/*   Updated: 2025/01/31 14:53:59 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <train.h>

double modele(double a, double x, double b)
{
	return (a * x + b);
}

double cout(t_res *result, t_car *cars, size_t m)
{
	double cout = 0.0;
	double prediction;
	double error;
	size_t i;
	
	i = 0;
	while (i < m)
	{
		prediction = modele(result->theta_1, cars[i].km, result->theta_0);
		error = prediction - cars[i].price;
		cout += error * error;
		i++;
	}
	return (cout / (2 * m));
}

void minimisation(t_res *result, t_car *cars, t_data datas, t_rul rules)
{
	size_t	i;
	size_t	iter;
	t_calc	c;

	iter = 0;
	while (iter < rules.iterations)
	{
		c.s_err_a = 0.0;
		c.s_err_b = 0.0;
		i = 0;
		while (i < datas.car_count)
		{
			c.prediction = modele(result->theta_1, cars[i].km, result->theta_0);
			c.error = c.prediction - cars[i].price;
			c.s_err_a += c.error * cars[i++].km;
			c.s_err_b += c.error;
		}
		result->theta_1 -= rules.learning_rate * c.s_err_a / datas.car_count;
		result->theta_0 -= rules.learning_rate * c.s_err_b / datas.car_count;
		if (iter % 100 == 0)
			printf("Iteration %zu: a = %.10e, b = %.10e, cost = %.10e\n",
				iter, result->theta_1, result->theta_0,
					cout(result, cars, datas.car_count));
		iter++;
	}
}

void train_model(t_rul rules, t_data datas, t_car *cars, t_res *result)
{
	t_norm	norm;

	calculate_stats(cars, datas.car_count, &norm);
	normalise_datas(cars, datas.car_count, norm);
	minimisation(result, cars, datas, rules);
	denormalise_result(result, norm);
	printf("Training over :\n");
	printf("a = %f, b = %f\n", result->theta_1, result->theta_0);
	printf("Final cost : %f\n", cout(result, cars, datas.car_count));
}
