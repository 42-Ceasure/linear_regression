/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linear_regression.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:03:02 by cglavieu          #+#    #+#             */
/*   Updated: 2025/01/31 16:44:04 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINEAR_REGRESSION_H
# define LINEAR_REGRESSION_H

# include <libft.h>
# include <string.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>

# define DEBUG	1

typedef struct	s_result
{
	double	theta_0;
	double	theta_1;
}				t_res;

#endif