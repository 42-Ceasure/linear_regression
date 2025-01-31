/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalisation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:57:44 by cglavieu          #+#    #+#             */
/*   Updated: 2025/01/31 16:30:04 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <train.h>

void	calculate_stats(t_car *cars, size_t m, t_norm *n)
{
	double	sum_km;
	double	sum_price;
	double	sum_km_sq;
	double	sum_price_sq;
	size_t	i;

	sum_km = 0.0;
	sum_price = 0.0;
	sum_km_sq = 0.0;
	sum_price_sq = 0.0;
	i = 0;
	while (i < m)
	{
		sum_km += cars[i].km;
		sum_price += cars[i].price;
		sum_km_sq += cars[i].km * cars[i].km;
		sum_price_sq += cars[i].price * cars[i].price;
		i++;
	}
	n->moy_km = sum_km / m;
	n->moy_eur = sum_price / m;
	n->std_km = sqrt((sum_km_sq / m) - (n->moy_km * n->moy_km));
	n->std_eur = sqrt((sum_price_sq / m) - (n->moy_eur * n->moy_eur));
}

void	normalise_datas(t_car *cars, size_t m, t_norm norm)
{
	size_t	i;

	i = 0;
	while (i < m)
	{
		cars[i].km = (cars[i].km - norm.moy_km) / norm.std_km;
		cars[i].price = (cars[i].price - norm.moy_eur) / norm.std_eur;
		i++;
	}
}

void	denormalise_result(t_res *r, t_norm n)
{
	double	tmp;

	r->theta_1 = (r->theta_1 * n.std_eur) / n.std_km;
	tmp = (r->theta_0 * n.std_eur) + n.moy_eur - (r->theta_1 * n.moy_km);
	r->theta_0 = tmp;
}
