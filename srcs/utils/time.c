/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 13:14:44 by dajeon            #+#    #+#             */
/*   Updated: 2023/08/11 13:14:45 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "time.h"
#include <stdio.h>

int	ft_timeinit(t_time *time)
{
	return (gettimeofday(time, NULL));
}

int	ft_timenow(t_time *from)
{
	t_time	now;

	ft_timeinit(&now);
	return (ft_timediff(from, &now));
}

int	ft_timediff(t_time *a, t_time *b)
{
	unsigned long	a_us;
	unsigned long	b_us;
	int				diff_usec;

	a_us = a->tv_sec * 1000000 + a->tv_usec;
	b_us = b->tv_sec * 1000000 + b->tv_usec;
	diff_usec = b_us - a_us;
	return (diff_usec / 1000);
}
