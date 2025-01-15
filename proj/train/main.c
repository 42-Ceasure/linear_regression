/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:48:55 by cglavieu          #+#    #+#             */
/*   Updated: 2025/01/15 17:24:55 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>

/*

index	| km		| price
0		| 240000	| 3650


*/

typedef struct	s_key
{
	int kms;
	int eur;
}				t_key;

void	linearRegression(t_key *keys)
{
	//body
}

t_key	*keysFromFile(int fd)
{
	t_key	*keys = NULL;

	//body
	return (keys);
}

int		openFile(char *path)
{
	return (open(path, O_RDONLY));
}

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		int		fd;
		t_key	*keys;

		fd = openFile(av[1]);
		if (fd != -1)
			return (-1);
		keys = keyFromFile(fd);
		if (keys == NULL)
			return (-1);
		linearRegression(keys);
	}
	return (0);
}