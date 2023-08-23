/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:02:46 by dajeon            #+#    #+#             */
/*   Updated: 2023/08/18 18:20:14 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	philos_init_name(t_philo *philos, t_info *info);
static int	philos_init_last(t_philo *philos, t_info *info);
static int	philos_init_fork(t_philo *philos, t_info *info);

t_philo	*philos_init(t_info *info)
{
	t_philo	*philos;
	int		size;

	size = ft_phsize(info);
	philos = (t_philo *)malloc(sizeof(t_philo) * size);
	if (philos == NULL)
		return (NULL);
	philos_init_name(philos, info);
	if (philos_init_last(philos, info) < 0)
	{
		ft_free(philos);
		return (NULL);
	}
	if (philos_init_fork(philos, info) < 0)
	{
		ft_free(philos);
		return (NULL);
	}
	return (philos);
}

static int	philos_init_name(t_philo *philos, t_info *info)
{
	int		i;
	int		size;

	size = ft_phsize(info);
	i = 0;
	while (i < size)
	{
		philos[i].name = i + 1;
		philos[i].dish = 0;
		philos[i].info = info;
		i++;
	}
	return (0);
}

static int	philos_init_last(t_philo *philos, t_info *info)
{
	t_time	*times;
	int		i;
	int		size;

	size = ft_phsize(info);
	times = (t_time *)malloc(sizeof(t_time) * size);
	if (times == NULL)
		return (-1);
	i = 0;
	while (i < size)
	{
		philos[i].last = &times[i];
		pthread_mutex_init(&(philos[i].m_last), NULL);
		i++;
	}
	info->times = times;
	return (0);
}

static int	philos_init_fork(t_philo *philos, t_info *info)
{
	t_fork	*forks;
	int		i;
	int		size;

	size = ft_phsize(info);
	forks = (t_fork *)malloc(sizeof(t_fork) * size);
	if (forks == NULL)
		return (-1);
	i = 0;
	while (i < size)
		fork_init(&forks[i++]);
	i = 0;
	while (i < size)
	{
		philos[i].left = &forks[i];
		if (i + 1 == size)
			philos[i].right = &forks[0];
		else
			philos[i].right = &forks[i + 1];
		i++;
	}
	info->forks = forks;
	return (0);
}

int	philos_destroy(t_philo *philos, t_info *info)
{
	int	i;
	int	size;

	size = ft_phsize(info);
	i = 0;
	while (i < size)
	{
		philos[i].left = NULL;
		philos[i].right = NULL;
		philos[i].last = NULL;
		philos[i].info = NULL;
		pthread_mutex_destroy(&philos[i].m_last);
		i++;
	}
	free(philos);
	return (0);
}
