/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linear_regression.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:03:02 by cglavieu          #+#    #+#             */
/*   Updated: 2025/01/23 15:05:47 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINEAR_REGRESSION_H
# define LINEAR_REGRESSION_H

#include <libft.h>
#include <string.h>
#include <fcntl.h>
#include <limits.h>

#define DEBUG 1

typedef struct	s_data
{
	double	min_km;
	double	max_km;
	double	min_price;
	double	max_price;
	double	theta_0;
	double	theta_1;
}				t_data;

#endif