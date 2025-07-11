/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlager <jlager@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:04:00 by jlager            #+#    #+#             */
/*   Updated: 2025/07/11 16:24:25 by jlager           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// ./philosophers 5 800 200 200 [5]
// number_of_philosophers time_to_die time_to_eat time_to_sleep [meals_to_full]
void	dining(void *data)
{
	t_philosophers	*philosopher;

	philosopher = (t_philosophers *)data;
	wait_for_everyone(philolosopher->table);
}

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
				&table->philolosopher[i], CREATE);
			i++;
		}
	}
}
