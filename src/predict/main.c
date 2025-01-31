/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:04:19 by cglavieu          #+#    #+#             */
/*   Updated: 2025/01/31 16:35:23 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <predict.h>

int	main(int ac, char **av)
{
	int		mileage;
	t_res	datas;

	if (ac == 2)
	{
		if (getdatafromfile(av[1], &datas) == -1)
			return (-1);
		while (1)
		{
			mileage = prompt_for_mileage();
			if (mileage == -1)
				return (-1);
			else if (mileage == 0)
				break ;
			else
				estimate_price(mileage, datas);
		}
	}
	return (0);
}
