/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   train.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 08:51:18 by cglavieu          #+#    #+#             */
/*   Updated: 2025/01/31 16:45:17 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRAIN_H
# define TRAIN_H

# include <linear_regression.h>

# define LEARNING_RATE	0.1
# define ITERATIONS		1000

typedef struct	s_car
{
	double	km;
	double	price;
}				t_car;

typedef struct	s_normalise
{
	double	moy_km;
	double	std_km;
	double	moy_eur;
	double	std_eur;
}				t_norm;

typedef struct	s_calculate
{
	long double	prediction;
	long double	error;
	long double	s_err_a;
	long double	s_err_b;
}				t_calc;

typedef struct	s_training_rules
{
	double	learning_rate;
	size_t	iterations;
}				t_rul;

typedef struct	s_data
{
	size_t	car_count;
	double	min_km;
	double	max_km;
	double	min_price;
	double	max_price;
}				t_data;

t_car	*parse_file(int fd, t_car *cars, t_data *datas);

t_car	*getdatafromfile(char *av, t_data *datas);

void	train_model(t_rul rules, t_data datas, t_car *cars, t_res *result);

void	save_theta(t_res result);

void	print_datas(t_data datas, t_car *car);

void	calculate_stats(t_car *cars, size_t m, t_norm *norm);
void	normalise_datas(t_car *cars, size_t m, t_norm norm);
void	denormalise_result(t_res *result, t_norm norm);

#endif