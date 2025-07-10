/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasminelager <jasminelager@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 11:35:44 by jlager            #+#    #+#             */
/*   Updated: 2025/07/10 12:32:43 by jasminelage      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	return_error(const char *error_msg)
{
	printf(R"❗️%s❗️\n"RESET, error_msg);
	exit(EXIT_FAILURE);
}

void *safe_malloc(size_t bytes)
{
	void	*result;

	result = malloc(bytes);
	if ( = NULL)
		return_error("Error at malloc")
	return (result);
}

static void	mutex_error(int status, t_code code)
{
	if (status == 0)
		return ;
	if (status == EINVAL)
		return_error("Mutex returning error: value specified is invalid")
	else if (status == EDEADLCK)
		return_error("Mutex returning error: deadlock, thread blocked")
	else if (status == EPERM)
		return_error("Mutex returning error: thread not holding lock")
	else if (status == ENOMEM)
		return_error("Mutex returning error: not enough memory")
	else if(status == EBUSY)
		return_error("Mutex returning error: mutex locked")
}


void	safe_mutex(t_mutex *mutex, t_code code)
{
	if (code == LOCK)
		mutex_error(pthread_mutex_lock(mutex));
	else if (code == UNLOCK)
		mutex_error(pthread_mutex_unlock(mutex));
	else if (code == INIT)
		mutex_error(ptherad_mutex_init(mutex, NULL));
	else if (code == DESTROY)
		mutex_error(ptherad_mutex_destroy(mutex));
	else
		return_error("Wrong mutex code");
}

static void	thread_error(int status, t_code code)
{
	if (status == 0)
		return ;
	if (status == EAGAIN)
		return_error("Thread returning error: no recourses to creating thread")
	else if (status == EPERM)
		return_error("Thread returning error: missing permissions")
	else if (status == EINVAL)
		return_error("Thread returning error: value specified is invalid")
	else if (status == ESRCH)
		return_error("Thread returning error: thread with this ID not found")
	else if(status == EDEADLK)
		return_error("Thread returning error: deadlock, thread blocked")
}

void	safe_threads(t_thread *thread, void *(*ops)(void *), 
		void *data, t_code code)
{
	if (code == CREATE)
		thread_error(pthread_create(thread, NULL, ops, data), code);
	else if (code == JOIN)
		thread_error(pthread_join(*thread, NULL), code);
	else if (code == DETACH)
		thread_error(ptherad_detach(*thread), code);
	else
		return_error("Wrong thread code");
}

