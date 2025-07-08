/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlager <jlager@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 11:35:44 by jlager            #+#    #+#             */
/*   Updated: 2025/07/04 11:43:57 by jlager           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	return_error(const char *error_msg)
{
	printf(R"❗️%s❗️\n"RESET, error_msg);
	exit(EXIT_FAILURE);
}