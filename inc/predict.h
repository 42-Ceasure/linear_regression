/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   predict.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 08:52:08 by cglavieu          #+#    #+#             */
/*   Updated: 2025/01/31 16:45:53 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PREDICT_H
# define PREDICT_H

# include <linear_regression.h>

int		parse_theta_line(char *line, t_res *datas);
int		parse_theta_file(int fd, t_res *datas);
int		getdatafromfile(char *av, t_res *datas);

void	estimate_price(int mileAge, t_res datas);
int		prompt_for_mileage(void);

#endif