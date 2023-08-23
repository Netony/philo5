/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 18:15:44 by dajeon            #+#    #+#             */
/*   Updated: 2023/08/23 16:55:21 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fork.h"

int	ft_take(t_stat *fork)
{
	pthread_mutex_lock(&(fork->m_stat));
	fork->stat = 1;
	return (0);
}

int	ft_release(t_stat *fork)
{
	pthread_mutex_unlock(&(fork->m_stat));
	fork->stat = 0;
	return (0);
}

