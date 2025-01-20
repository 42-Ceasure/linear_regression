/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:04:19 by cglavieu          #+#    #+#             */
/*   Updated: 2025/01/20 10:18:16 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <predict.h>

void	hint_ft(int i, const char *func)
{
	if (DEBUG)
	{
		if (i)
			printf("entering in function ");
		else
			printf("leaving function ");
		printf("%s\n", func);
	}
}

void	estimatePrice(int mileAge)
{
	static	int thetaZer = 0;
	static	int thetaOne = 0;
	int			estimatePrice = 0;

	estimatePrice = thetaZer + (thetaOne * mileAge);
	printf("\testimatePrice = %d\n", estimatePrice);
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

int		main(int ac, char **av)
{
	int	mileAge;

	if (ac == 1)
	{
		(void)av;
		mileAge = promptForMileage();
		if (mileAge == -1)
			return (-1);
		estimatePrice(mileAge);
	}
	return (0);
}
