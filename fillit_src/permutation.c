/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaesar <lcaesar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 14:06:19 by lcaesar           #+#    #+#             */
/*   Updated: 2019/10/09 15:56:11 by lcaesar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			swap_strings_wow(void *set, int j, int k)
{
	char *thing;

	thing = (((char **)set)[j]);
	(((char **)set)[j]) = (((char **)set)[k]);
	(((char **)set)[k]) = thing;
}

int				get_int_array_new(int **array, int size)
{
	int k;

	*array = malloc(sizeof(int) * size);
	k = 0;
	if (*array)
	{
		while (k < size)
		{
			(*array)[k] = 0;
			k = k + 1;
		}
		return (1);
	}
	return (0);
}

static int		useless_function(void *set, int *stack_state, int *j, int type)
{
	if (type == 1)
	{
		swap_strings_wow(set, 0, *j);
		stack_state[*j] = stack_state[*j] + 1;
		*j = 0;
		return (1);
	}
	else
	{
		swap_strings_wow(set, stack_state[*j], *j);
		stack_state[*j] = stack_state[*j] + 1;
		*j = 0;
		return (1);
	}
}

static int		absolutely_useless_function(int *stack_state,
		int *j, int return_value)
{
	stack_state = NULL;
	*j = 0;
	return (return_value);
}

int				permute_new(void *set, int size,
		void (*swap)(void *, int, int), int reset)
{
	static int *stack_state;
	static int j;

	swap = swap;
	if (reset == 1)
	{
		return (absolutely_useless_function(stack_state, &j, -1));
	}
	if (!stack_state)
		return (get_int_array_new(&stack_state, size));
	while (j < size)
	{
		if (stack_state[j] < j)
		{
			if (j % 2 == 0)
				return (useless_function(set, stack_state, &j, 1));
			else
				return (useless_function(set, stack_state, &j, 2));
		}
		stack_state[j] = 0;
		j = j + 1;
	}
	return (absolutely_useless_function(stack_state, &j, 0));
}
