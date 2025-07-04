/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasminelager <jasminelager@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:31:04 by jasminelage       #+#    #+#             */
/*   Updated: 2025/07/04 09:28:47 by jasminelage      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main(int argc, char **argv)
{
	t_table	table;

	if (argc != 5 && argc != 6)
	{
		return_error(R"Wrong input... \n"RESET
			G"Correct:"RESET B"number_of_philosophers 
			time_to_die time_to_eat time_to_sleep [meals_to_full]\n" RESET)
	}
	if (argc == 5 || argc == 6)
	{
		//checks 
		parsing(&table, argv); // fill in table struct
		
		start_simulation()
		return (0);
	}
}

// if (argc == 5 || argc == 6)
// {

// }