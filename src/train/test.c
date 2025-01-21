#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int is_valid_integer(const char *str)
{
	while (*str)
	{
		if (!isdigit(*str))
		{
			return (0);
		}
		str++;
	}
	return (1);
}

int parse_line(char *line, int *mile_age, int *price)
{
	char *token;

	token = strtok(line, ",\n");
	if (token == NULL || !is_valid_integer(token))
	{
		printf("Invalid mileage value: %s\n", token);
		return (0);
	}
	*mile_age = atoi(token);
	token = strtok(NULL, ",\n");
	if (token == NULL || !is_valid_integer(token))
	{
		printf("Invalid price value: %s\n", token);
		return (0);
	}
	*price = atoi(token);
	return (1);
}

int main(int ac, char **av)
{
	int		file;
	char	*line;
	int		mile_age;
	int		price;

	if (ac != 2)
		return (-1);
	file = open(av[1], "r");
	if (file == NULL)
	{
		printf("Error opening file.\n");
		return (-1);
	}
	while (get_next_line(file, &line))
	{
		if (line[0] == '\n' || !parse_line(line, &mile_age, &price))
			continue;
		printf("Mileage: %d, Price: %d\n", mile_age, price);
		free(line);
	}
	close(file);
	return (0);
}
