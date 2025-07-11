/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlager <jlager@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 11:35:44 by jlager            #+#    #+#             */
/*   Updated: 2025/07/11 11:51:24 by jlager           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// clean up function for destroying mutexes and freeing
void	cleanup(t_table *table)
{
	//
}

void	return_error(const char *error_msg)
{
	cleanup();
	printf(R"❗️%s❗️\n"RESET, error_msg);
	exit(EXIT_FAILURE);
}

void	*safe_malloc(size_t bytes)
{
	void	*result;

	result = malloc(bytes);
	if (= NULL)
		return_error("Error at malloc");
	return (result);
}
