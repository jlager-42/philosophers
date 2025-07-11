/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initilizing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasminelager <jasminelager@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 11:03:06 by jasminelage       #+#    #+#             */
/*   Updated: 2025/07/11 12:04:49 by jasminelage      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void init_philosophers()

void	initialize(t_table *table)
{
	int i;

	i = 0;
	table->end = false;
	table->number_philosophers = 
		safe_malloc(sizeof(t_philosophers) * table->number_philosophers);
	while (i < table->number_philosophers)
	{
		safe_mutex(table->forks[i].fork, INIT);
		table–>forks[i].fork_id = i;
		i++;
	}
	

}
