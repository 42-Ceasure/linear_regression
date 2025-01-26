
// int parse_token(char **line, void *result, void *(*convert_func)(const char *), const char *delimiters)
// {
// 	char *token;
// 	void *converted_value;

// 	if (!line || !*line || !result || !convert_func || !delimiters)
// 		return (0);
// 	token = strtok(*line, delimiters);
// 	if (!token)
// 		return (0);
// 	converted_value = convert_func(token);
// 	if (!converted_value)
// 		return (0);
// 	*(void **)result = converted_value;
// 	return (1);
// }

int parse_token(char **line, double *value, const char *value_name)
{
	char *token;

	token = strtok(*line, ",\n");
	if (!token || !ft_isvaliddbl(token))
	{
		printf("Error: Invalid %s value: %s\n", value_name, token ? token : "NULL");
		return (0);
	}
	*value = ft_atof(token);
	return (1);
}

int parse_line_as_double(char *line, double *value1, double *value2)
{
	if (!parse_token(&line, value1, "first"))
		return (0);
	if (!parse_token(&line, value2, "second"))
		return (0);
	return (1);
}

int parse_theta_line(char *line, t_data *datas)
{
	double theta_0, theta_1;

	if (!parse_line_as_double(line, &theta_0, &theta_1))
		return (0);
	datas->theta_0 = theta_0;
	datas->theta_1 = theta_1;
	return (1);
}

int parse_car_line(char *line, t_car *car)
{
	double km, price;

	if (!parse_line_as_double(line, &km, &price))
		return (0);
	car->km = (int)km;
	car->price = (int)price;
	return (1);
}

int parse_theta_file(int fd, t_data *datas)
{
	char *line;
	int ret;

	ret = get_next_line(fd, &line);
	if (ret <= 0)
	{
		printf("Error: File is %s.\n", ret == 0 ? "empty" : "unreadable");
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
