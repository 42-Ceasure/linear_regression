/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:04:19 by cglavieu          #+#    #+#             */
/*   Updated: 2025/01/23 15:15:08 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <predict.h>

int main(int ac, char **av)
{
	int mileAge;
	t_data datas;

	if (ac == 2)
	{
		if (getdatafromfile(av[1], &datas) == -1)
			return (-1);
		mileAge = promptForMileage();
		if (mileAge == -1)
			return (-1);
		estimatePrice(mileAge, datas);
	}
	return (0);
}