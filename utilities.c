/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlager <jlager@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 11:35:44 by jlager            #+#    #+#             */
/*   Updated: 2025/07/11 15:19:05 by jlager           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	return_error(const char *error_msg)
{
	printf("❗️%s❗️\n", error_msg);
	exit(EXIT_FAILURE);
}

void	*safe_malloc(size_t bytes)
{
	void	*result;

	result = malloc(bytes);
	if (bytes == NULL)
		return_error("Error at malloc");
	return (result);
}

cleanup_and_exit(&table)
{
	
}
