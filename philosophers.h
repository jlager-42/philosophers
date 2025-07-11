/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlager <jlager@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:31:00 by jasminelage       #+#    #+#             */
/*   Updated: 2025/07/11 16:18:52 by jlager           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <limits.h> // INT_MAX, INT_MAX
# include <pthread.h>
// mutex: init destroy lock unlock,threads: create join detach
# include <stdbool.h>  // bool flags
# include <stdio.h>    // printf
# include <stdlib.h>   // malloc, free
# include <string.h>   // memset
# include <sys/time.h> // gettimeofday
# include <unistd.h>   // write, usleep
// no libft authorization here

// ANSI escape codes for colored text :)
# define R "\x1b[31m"
# define G "\x1b[32m"
# define B "\x1b[34m"
# define RESET "\x1b[0m"

// for more readable code; renaming
typedef pthread_mutex_t	t_mutex;
typedef pthread_t		t_thread;

typedef enum e_code
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH,
}						t_code;

// for compiling
typedef struct s_table t_table

	typedef struct s_fork
{
	t_mutex				fork;
	int					fork_id;
}						t_fork;

typedef struct s_philosophers
{
	int					id;
	//	bool		dead;
	//	bool		eating;
	//	bool		sleeping;
	//	bool		thinking;
	//	bool		has_fork;
	long				time_last_eat;
	long				meals_count;
	bool				full;
	t_fork				*left_fork;
	t_fork				*right_fork;
	t_table				*table;
	pthread_t			thread_id;

}						t_philosophers;

// ./philosophers 5 800 200 200 [5]
// number_of_philosophers time_to_die time_to_eat time_to_sleep [meals_to_full]
typedef struct s_table
{
	long				number_of_philosophers;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	long				meals_to_full;
	bool				everyone_ready;
	long				start;
	bool				end;
	t_fork				*fork;
	t_philosophers		*philosopher;
	t_mutex				table_mutex;
}						t_table;

#endif

// utilities.c
void					return_error(const char *error_msg);
void					*safe_malloc(size_t bytes);

// thread_mutex.c
void					safe_thread(t_thread *thread, void *(*ops)(void *),
							void *data, t_code code);
void					safe_mutex(t_mutex *mutex, t_code code);

// parsing.c
void					parsing(t_table *table, char **argv);

// initializing.c
void					initialize(t_table *table);