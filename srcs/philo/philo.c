/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 13:15:03 by dajeon            #+#    #+#             */
/*   Updated: 2023/08/23 16:07:34 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_odd(void *param)
{
	t_philo	*philo;

	philo = (t_philo *)param;
	ft_timeinit(philo->last);
	while (!ft_isend(philo->info) && philo->dish < philo->info->number_of_times)
	{
		ft_wait(philo->info->number_of_philos);
		ft_take(philo->left);
		ft_timestamp(philo, "has taken a fork");
		ft_take(philo->right);
		ft_timestamp(philo, "has taken a fork");
		pthread_mutex_lock(&(philo->m_last));
		ft_timeinit(philo->last);
		(philo->dish)++;
		pthread_mutex_unlock(&(philo->m_last));
		ft_timestamp(philo, "is eating");
		ft_msleep(philo->info->time_to_eat);
		ft_release(philo->left);
		ft_release(philo->right);
		ft_timestamp(philo, "is sleeping");
		ft_msleep(philo->info->time_to_sleep);
		ft_timestamp(philo, "is thinking");
	}
	return (NULL);
}

void	*ft_even(void *param)
{
	t_philo	*philo;

	philo = (t_philo *)param;
	ft_timeinit(philo->last);
	while (!ft_isend(philo->info) && philo->dish < philo->info->number_of_times)
	{
		ft_take(philo->right);
		ft_timestamp(philo, "has taken a fork");
		ft_take(philo->left);
		ft_timestamp(philo, "has taken a fork");
		pthread_mutex_lock(&(philo->m_last));
		ft_timeinit(philo->last);
		(philo->dish)++;
		pthread_mutex_unlock(&(philo->m_last));
		ft_timestamp(philo, "is eating");
		ft_msleep(philo->info->time_to_eat);
		ft_release(philo->right);
		ft_release(philo->left);
		ft_timestamp(philo, "is sleeping");
		ft_msleep(philo->info->time_to_sleep);
		ft_timestamp(philo, "is thinking");
	}
	return (NULL);
}

void	*ft_solo(void *param)
{
	t_philo	*philo;

	philo = (t_philo *)param;
	ft_timeinit(philo->last);
	usleep(100);
	ft_take(philo->right);
	ft_timestamp(philo, "has taken a fork");
	return (NULL);
}
