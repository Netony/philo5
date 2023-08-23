/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtsinit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 19:02:50 by dajeon            #+#    #+#             */
/*   Updated: 2023/08/18 19:17:39 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "monitor.h"
#include <stdlib.h>

t_monitor	*ft_mtsinit(int size, t_philo *philos, t_info *info)
{
	t_monitor	*mts;
	int			i;
	
	mts = (t_monitor *)malloc(sizeof(t_monitor) * size);
	if (mts == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		mts[i].philos = philos;
		mts[i].info = info;
		mts[i].name = i;
		i++;
	}
	return (mts);
}

int	ft_mtsdel(t_monitor *mts, int size)
{
	int	i;
	
	i = 0;
	while (i < size)
	{
		mts[i].philos = NULL;
		mts[i].info = NULL;
		mts[i].name = 0;
		i++;
	}
	free(mts);
	return (0);
}
