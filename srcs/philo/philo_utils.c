/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:06:08 by dajeon            #+#    #+#             */
/*   Updated: 2023/08/18 19:22:12 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "philo.h"

int	ft_msleep(int ms)
{
	int		us;
	t_time	start;

	ft_timeinit(&start);
	us = ms * 1000;
	while (ft_timenow(&start) < ms)
	{
		if (us * 1 / 5 >= 50)
			us = us / 5;
		else
			us = 50;
		usleep(us);
	}
	return (0);
}

int	ft_timestamp(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&(philo->info->m_end));
	if (philo->info->block == 0)
		printf("%d %d %s\n",
			   	ft_timenow(&(philo->info->start)), philo->name, msg);
	pthread_mutex_unlock(&(philo->info->m_end));
	return (0);
}

int	ft_timestamp_dead(t_philo *philo)
{
	printf("%d %d died\n", ft_timenow(&(philo->info->start)), philo->name);
	return (0);
}

int	ft_isend(t_info *info)
{
	int	ret;

	ret = 0;
	pthread_mutex_lock(&(info->m_end));
	ret += info->end;
	pthread_mutex_unlock(&(info->m_end));
	return (ret);
}

int	ft_setend(t_philo *philo, t_info *info)
{
	pthread_mutex_lock(&(info->m_end));
	if (info->end == 1)
	{
		pthread_mutex_unlock(&(info->m_end));
		return (0);
	}
	info->end = 1;
	if (philo->dish < info->number_of_times)
	{
		ft_timestamp_dead(philo);
		info->block = 1;
	}
	pthread_mutex_unlock(&(info->m_end));
	return (0);
}
