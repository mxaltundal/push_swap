/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   before_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltunda <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 16:35:34 by maltunda          #+#    #+#             */
/*   Updated: 2022/09/10 16:35:36 by maltunda         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_push *data, char c)
{
	if (c == 'a')
	{
		push_op(data->stack_a, --data->size_a, data->stack_b[data->size_b++]);
		write(1, "pa\n", 3);
	}
	else
	{
		push_op(data->stack_b, --data->size_b, data->stack_a[data->size_a++]);
		write(1, "pb\n", 3);
	}
}

void	ft_swap(t_push *data, char c)
{
	if (c == 'a')
	{
		swap_op(data->stack_a, data->size_a);
		write(1, "sa\n", 3);
	}
	else if (c == 'b')
	{
		swap_op(data->stack_b, data->size_a);
		write(1, "sb\n", 3);
	}
	else if (c == 'x')
	{
		swap_op(data->stack_a, data->size_a);
		swap_op(data->stack_b, data->size_a);
		write(1, "ss\n", 3);
	}
}

void	ft_rotate(t_push *data, char c)
{
	if (c == 'a')
	{
		rotate_op(data->stack_a, data->size_a, data->size);
		write(1, "ra\n", 3);
	}
	else if (c == 'b')
	{
		rotate_op(data->stack_b, data->size_b, data->size - 3);
		write(1, "rb\n", 3);
	}
	else if (c == 'x')
	{
		rotate_op(data->stack_a, data->size_a, data->size);
		rotate_op(data->stack_b, data->size_b, data->size - 3);
		write(1, "rr\n", 3);
	}
}

void	ft_revrotate(t_push *data, char c)
{
	if (c == 'a')
	{
		reverse_op(data->stack_a, data->size_a, data->size);
		write(1, "rra\n", 4);
	}
	else if (c == 'b')
	{
		reverse_op(data->stack_b, data->size_b, data->size - 3);
		write(1, "rrb\n", 4);
	}
	else if (c == 'x')
	{
		reverse_op(data->stack_a, data->size_a, data->size);
		reverse_op(data->stack_b, data->size_b, data->size - 3);
		write(1, "rrr\n", 4);
	}
}
