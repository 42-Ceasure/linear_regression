/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   estimate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:14:37 by cglavieu          #+#    #+#             */
/*   Updated: 2025/01/31 15:00:15 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <predict.h>

void	estimatePrice(int mileAge, t_data datas)
{
	double estimatePrice;

	estimatePrice = datas.theta_0 + (datas.theta_1 * mileAge);
	printf("Estimated Price for mileage %d: %.2f\n", mileAge, estimatePrice);
	if (estimatePrice < 0)
		printf("(maybe if you sell it to a museum ?)\n");
}

int		promptForMileage(void)
{
	int		mileAge;
	char	*line;

	mileAge = 0;
	while (mileAge <= 0)
	{
		printf("requested mileage. (exit for leave)\n");
		if (get_next_line(0, &line) == -1)
			return (-1);
		if (!ft_strcmp(line, "exit\n"))
		{
			free(line);
			return (0);
		}
		if (ft_isvalidint(line) != 1)
			printf("mileage should be a valid positive integer\n");
		mileAge = ft_atoi(line);
		free(line);
	}
	return (mileAge);
}
