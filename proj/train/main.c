/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:48:55 by cglavieu          #+#    #+#             */
/*   Updated: 2025/01/15 12:19:49 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef		struct	s_data
{
		int		km;
		int		price;
		int		index;

		t_data	*next;
}					t_data;

void	push_data(t_data *data_list, t_data data)
{
	data.next = data_list;
	data_list = &data;
}

t_data	pop_data(t_data *data_list)
{
	t_data	ret;

	ret = *data_list;
	data_list = ret.next;
	return (ret);
}

int		main(int ac, char **av)
{
	t_data *data_list;

	return (0);
}