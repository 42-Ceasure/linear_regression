/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   estimate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:14:37 by cglavieu          #+#    #+#             */
/*   Updated: 2025/01/23 15:15:16 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <predict.h>

void	estimatePrice(int mileAge, t_data datas)
{
	double estimatePrice;

	estimatePrice = datas.theta_0 + (datas.theta_1 * mileAge);
	printf("Estimated Price for mileage %d: %.2f\n", mileAge, estimatePrice);
}

int		promptForMileage(void)
{
	int		mileAge;
	char	*line;

	mileAge = 0;
	while (mileAge <= 0)
	{
		printf("requested mileage.\n");
		if (get_next_line(0, &line) == -1)
			return (-1);
		mileAge = ft_atoi(line);
		printf("mileage=%d\n", mileAge);
		free(line);
	}
	return (mileAge);
}
