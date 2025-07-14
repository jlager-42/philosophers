/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initilizing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasminelager <jasminelager@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 11:03:06 by jasminelage       #+#    #+#             */
/*   Updated: 2025/07/14 14:21:08 by jasminelage      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// checking philolosopher id to see if its odd or even
// based on that he tries to take fork (either it has been taken on not yet)
static void	assing_fork(t_philosophers *philosopher, t_fork *fork, int chair)
{
	int	number_of_philosophers;

	number_of_philosophers = philosopher->table->number_of_philosophers;
	if (philosopher->id % 2 == 1)
	{
		philosopher->left_fork = &fork[(chair + 1) % number_of_philosophers];
		philosopher->right_fork = &fork[chair];
	}
	else if (philosopher->id % 2 == 0)
	{
		philosopher->left_fork = &fork[chair];
		philosopher->right_fork = &fork[(chair + 1) % number_of_philosophers];
	}
}

static void	init_philosophers(t_table *table)
{
	int				i;
	t_philosophers	*philosopher;

	while (i < table->number_of_philosophers)
	{
		philosopher = table->philosopher + i;
		philosopher->id = i + 1;
		philosopher->full = false;
		philosopher->meals_count = 0;
		philosopher->table = table;
		assing_fork(philosopher, table->fork, i);
	}
}

void	initialize(t_table *table)
{
	int	i;

	i = 0;
	table->everyone_ready = false;
	table->end = false;
	table->number_of_philosophers = safe_malloc(sizeof(t_philosophers)
			* table->number_of_philosophers);
	safe_mutex(table->table_mutex, INIT);
	safe_mutex(table->printing_lock_mutex, INIT);
	table->forks = safe_malloc(sizeof(t_forks) * table->number_of_philosophers);
	while (i < table->number_of_philosophers)
	{
		safe_mutex(table->forks[i].fork, INIT);
		table–> forks[i].fork_id = i;
		i++;
	}
	init_philosophers(table);
}
