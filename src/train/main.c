/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:48:55 by cglavieu          #+#    #+#             */
/*   Updated: 2025/01/20 12:18:54 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <train.h>

/*

index	| km		| price
0		| 240000	| 3650


*/

// char	**getdatafromfile(char **av)
// {
// 	size_t	line_count;
// 	int		fd;

// 	line_count = ft_filelinecount(av[1]);
// 	fd = ft_fileopenr(av[1]);
// 	if (fd == -1)
// 		return (-1);
// 	printf("linecount:%zu\n", line_count);
// }

int		main(int ac, char **av)
{
	char	**data;

	if (ac == 2)
	{
		data = getdatafromfile(av);
	}
	return (0);
}