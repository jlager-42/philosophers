/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasminelager <jasminelager@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 15:39:53 by jasminelage       #+#    #+#             */
/*   Updated: 2025/07/14 15:54:19 by jasminelage      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philosophers.h"

static void	eating(t_philosophers *philosopher)
{
	safe_mutex(&philosopher->left_fork->fork, LOCK);
	print_status(TAKE_LEFT_FORK, philosopher, DEBUG_MODE);
	safe_mutex(&philosopher->right_fork->fork, LOCK);
	print_status(TAKE_RIGHT_FORK, philosopher, DEBUG_MODE);
	
	paste_long()
}



