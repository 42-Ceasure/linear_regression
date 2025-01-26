/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:08:59 by cglavieu          #+#    #+#             */
/*   Updated: 2025/01/23 15:19:05 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <predict.h>

int		parse_theta_line(char *line, t_data *datas)
{
	char	*token;

	token = strtok(line, ",\n");
	if (token == NULL || !ft_isvaliddbl(token))
	{
		printf("Error: Invalid theta_0 value: %s\n", token ? token : "NULL");
		return (0);
	}
	datas->theta_0 = ft_atof(token);
	token = strtok(NULL, ",\n");
	if (token == NULL || !ft_isvaliddbl(token))
	{
		printf("Error: Invalid theta_1 value: %s\n", token ? token : "NULL");
		return (0);
	}
	datas->theta_1 = ft_atof(token);
	return (1);
}

int		parse_theta_file(int fd, t_data *datas)
{
	char	*line;
	int		ret;

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

int		getdatafromfile(char *av, t_data *datas)
{
	int		fd;

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
