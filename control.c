/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltunda <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 16:40:34 by maltunda          #+#    #+#             */
/*   Updated: 2022/09/10 18:38:29 by maltunda         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_arg(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (1);
		i++;
	}
	ft_errors(0);
	return (0);
}

int	control_data(char **av)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	size = 0;
	while (av[++i])
	{
		check_arg(av[i]);
		j = 0;
		while (av[i][j])
		{
			j += ft_atoi(&av[i][j]);
			if (av[i][j] || ft_isnum(av[i][0]) || ft_isnum(av[i][j - 1]))
				size++;
		}
	}
	return (size);
}

void	is_equal(t_push *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->size)
	{
		j = i + 1;
		while (j < data->size)
		{
			if (data->temp_list[i] == data->temp_list[j])
			{
				free(data->temp_list);
				ft_errors(1);
			}
			j++;
		}
	}
}

int	is_sorted(int *stack, int start, int size)
{
	while (start < size - 1)
	{
		if (stack[start] > stack[start + 1])
			return (0);
		start++;
	}
	return (1);
}
