/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   predict.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 08:52:08 by cglavieu          #+#    #+#             */
/*   Updated: 2025/01/23 15:16:39 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PREDICT_H
# define PREDICT_H

#include <linear_regression.h>

int		parse_theta_line(char *line, t_data *datas);
int		parse_theta_file(int fd, t_data *datas);
int		getdatafromfile(char *av, t_data *datas);

void	estimatePrice(int mileAge, t_data datas);
int		promptForMileage(void);

#endif