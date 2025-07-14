/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasminelager <jasminelager@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:04:00 by jlager            #+#    #+#             */
/*   Updated: 2025/07/14 15:38:35 by jasminelage      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// similarly like waiting for a signal back in minitalk
// "spinlock"
// loops until flag is changed
void	wait_for_everyone(t_table *table)
{
	while(copy_bool(&table->table_mutex, &table->everyone_ready))
		;
}

void	*dining(void *data)
{
	t_philosophers	*philosopher;

	philosopher = (t_philosophers *)data;
	wait_for_everyone(philolosopher->table);
	
	while (!finished_simulation())
	{
		if (philolosopher->full)
			break ;
		eating()
		
		sleeping()

		thinking()
	}

	return(NULL);
}

// ./philosophers 5 800 200 200 [5]
// number_of_philosophers time_to_die time_to_eat time_to_sleep [meals_to_full]
void	start_simulation(t_table table)
{
	int	i;

	i = 0;
	if (table->number_of_philosophers == 0)
		return ;
	else if (table->number_of_philosophers == 1)
	{
		;
	}
	else if (table->number_of_philosophers > 1)
	{
		while (i < table->number_of_philosophers)
		{
			safe_thread(&table->philosopher[i].thread_id, dining, 
				&table->philosopher[i], CREATE);
			i++;
		}
	}
	table->start = get_time(MICROSECONDS);
	paste_bool(&table->table_mutex, table->everyone_ready, true);
	i = 0;
	while(i < table->number_of_philosophers)
	{
		safe_thread(table>philosopher[i].thread_id, NULL, NULL, JOIN);
		i++;
	}
}
