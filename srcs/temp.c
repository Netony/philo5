void	*loop_even(void *test)
{
	t_philo	*philos;
	t_info	*info;
	int		size;
	int		i;

	philos = test;
	info = philos[0].info;
	size = ft_phsize(info);
	i = 1;
	ft_wait(info->number_of_philos);
	while (i < size)
	{
		/*
		pthread_mutex_lock(&(philos[(size - 1) - i].m_last));
		if (ft_timenow(philos[(size - 1) - i].last) > info->time_to_die)
		{
			ft_setend(&(philos[(size - 1) - i]), info);
			pthread_mutex_unlock(&(philos[(size - 1) - i].m_last));
			break ;
		}
		pthread_mutex_unlock(&(philos[(size - 1) - i].m_last));
		*/
		pthread_mutex_lock(&(philos[i].m_last));
		if (ft_timenow(philos[i].last) > info->time_to_die)
		{
			ft_setend(&(philos[i]), info);
			pthread_mutex_unlock(&(philos[i].m_last));
			break ;
		}
		pthread_mutex_unlock(&(philos[i].m_last));
		i += 2;
		if (i >= size)
			i = 1;
	}
	return (NULL);
}

