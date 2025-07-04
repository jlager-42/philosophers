/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasminelager <jasminelager@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:31:00 by jasminelage       #+#    #+#             */
/*   Updated: 2025/07/04 09:28:25 by jasminelage      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H

#include <string.h>		// memset
#include <stdio.h>		// printf
#include <stdlib.h> 	// malloc, free
#include <unistd.h>		// write, usleep
#include <sys/time.h>	// gettimeofday
#include <pthread.h>	// mutex: init destroy lock unlock
						// threads: create join detach
#include <stdbool.h>	// bool flags
#include <limits.h>		// INT_MAX, INT_MAX
// no libft authorization here

#define R   "\x1b[31m"
#define G   "\x1b[32m"
#define B   "\x1b[34m"
#define RESET "\x1b[0m"

// int main() {
//     printf(R   "This is red text\n"   RESET);
//     printf(G   "This is green text\n" RESET);
//     printf(B   "This is blue text\n"   RESET);
//     return 0;
// }

// for more readable code; renaming
typedef pthread_mutex_t t_mtx;

// for compiling
typedef struct	s_table t_table

typedef struct s_fork
{
	t_mtx	fork;
	int		fork_id;
	
}			t_fork;

typedef struct	s_philosopher
{
	int			id;
//	bool		dead;
//	bool		eating;
//	bool		sleeping;
//	bool		thinking;
//	bool		has_fork;
	long		time_from_eat;
	long		meals_count;
	bool		full;
	t_fork		*left_fork;
	t_fork		*right_fork;
	t_table		*table;
	pthread_t	thread_id;

}				t_philosopher;

// ./philosophers 5 800 200 200 [5]
// number_of_philosophers time_to_die time_to_eat time_to_sleep [meals_to_full]
typedef struct	s_table
{
	long			number_of_philosophers;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			meals_to_full;
	long			start;
	bool			end;
	t_fork			*forks;
	t_philosopher	*philosophers;
}					t_table;

#endif
