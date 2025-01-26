/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   train.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 08:51:18 by cglavieu          #+#    #+#             */
/*   Updated: 2025/01/24 12:22:29 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRAIN_H
# define TRAIN_H

#include <linear_regression.h>

typedef struct	s_car
{
	double	km;
	double	price;
}				t_car;

int		parse_line(char *line, double *mile_age, double *price);
t_car	*parse_file(int fd, t_car *cars);
t_car	*allocate_cars(size_t line_count);
t_car	*getdatafromfile(char *av);

// void	normalize_data(t_car *cars, t_data *datas);
void	calculate_theta(t_car *cars, t_data *datas);
void	save_theta(t_data datas);

#endif