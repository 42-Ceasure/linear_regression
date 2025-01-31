/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   estimate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:14:37 by cglavieu          #+#    #+#             */
/*   Updated: 2025/01/31 16:44:01 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <predict.h>

void	estimate_price(int mile_age, t_res datas)
{
	double	estimate_price;

	estimate_price = datas.theta_0 + (datas.theta_1 * mile_age);
	printf("Estimated Price for mileage %d: %.2f\n", mile_age, estimate_price);
	if (estimate_price < 0)
		printf("(maybe if you sell it to a museum ?)\n");
}

int		prompt_for_mileage(void)
{
	int		mile_age;
	char	*line;

	mile_age = 0;
	while (mile_age <= 0)
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
		mile_age = ft_atoi(line);
		free(line);
	}
	return (mile_age);
}
