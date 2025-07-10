/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasminelager <jasminelager@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:31:04 by jasminelage       #+#    #+#             */
/*   Updated: 2025/07/10 11:01:54 by jasminelage      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// number_of_philosophers time_to_die time_to_eat time_to_sleep [meals_to_full]
int	main(int argc, char **argv)
{
	t_table	table;

	if (argc != 5 && argc != 6)
	{
		return_error(R"Wrong input... \n"RESET G"Correct:" RESET 
			B"number_of_philosophers time_to_die time_to_eat time_to_sleep
				[meals_to_full]\n" RESET)
	}
	if (argc == 5 || argc == 6)
	{
		// other  checks
		parsing(&table, argv); // fill in table struct
		initialize(&table);
		start_simulation(&table);
		cleanup_and_exit(&table); // if philos are full or one philo dies,
									// otherwise endless
		return (0);
	}
}

// if (argc == 5 || argc == 6)
// {

// }