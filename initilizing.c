/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initilizing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlager <jlager@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 11:03:06 by jasminelage       #+#    #+#             */
/*   Updated: 2025/07/11 11:51:23 by jlager           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	initialize(t_table *table)
{
	table->end = false;
	table->number_philosophers = safe_malloc(sizeof(table->number_philosophers))
}
