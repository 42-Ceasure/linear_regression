/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:04:19 by cglavieu          #+#    #+#             */
/*   Updated: 2025/01/23 02:05:15 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <predict.h>

typedef struct	s_data
{
	int		min_km;
	int		max_km;
	int		min_price;
	int		max_price;
	double	theta_0;
	double	theta_1;
}				t_data;

int ft_isinteger(const char *str)
{
	if (*str == '-' || *str == '+')  // Autorise un signe au début
		str++;
	if (!*str)  // Si c'est juste un signe sans chiffre, ce n'est pas valide
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))  // Si un caractère n'est pas un chiffre, ce n'est pas un entier valide
			return (0);
		str++;
	}
	return (1);  // Si tous les caractères sont des chiffres, c'est un entier valide
}

void estimatePrice(int mileAge, t_data datas)
{
    double estimatePrice;

    // Calcul du prix estimé avec le kilométrage réel
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

int	ft_isfloat(const char *str)
{
	int	point_seen;

	point_seen = 0;
	if (*str == '-' || *str == '+')
		str++;
	if (!*str)
		return (0);
	while (*str)
	{
		if (*str == '.')
		{
			if (point_seen)
				return (0);
			point_seen = 1;
		}
		else if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

int parse_theta_line(char *line, t_data *datas)
{
	char    *token;

	token = strtok(line, ",\n");
	if (token == NULL || !ft_isfloat(token))
	{
		printf("Error: Invalid theta_0 value: %s\n", token ? token : "NULL");
		return (0);
	}
	datas->theta_0 = ft_atof(token);
	token = strtok(NULL, ",\n");
	if (token == NULL || !ft_isfloat(token))
	{
		printf("Error: Invalid theta_1 value: %s\n", token ? token : "NULL");
		return (0);
	}
	datas->theta_1 = ft_atof(token);
	// if (strtok(NULL, ",\n") != NULL)
	// {
	// 	printf("Error: Extra data found in line. Expected only six values.\n");
	// 	return (0);
	// }
	return (1);
}

int parse_theta_file(int fd, t_data *datas)
{
	char    *line;
	int     ret;

	ret = get_next_line(fd, &line);
	if (ret == -1) {
		printf("Error: Could not read from file.\n");
		return (0);
	}
	if (ret == 0) {
		printf("Error: File is empty.\n");
		return (0);
	}
	if (!parse_theta_line(line, datas))
	{
		free(line);
		return (0);
	}
	free(line);
	return (1);
}

int getdatafromfile(char *av, t_data *datas)
{
	int fd;

	fd = ft_fileopenr(av);
	if (fd == -1)
	{
		printf("Error: Could not open theta file.\n");
		return (-1);
	}
	if (!parse_theta_file(fd, datas))
	{
		close(fd);
		return (-1);
	}
	close(fd);
	return (0);
}

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