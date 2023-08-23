/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 13:14:49 by dajeon            #+#    #+#             */
/*   Updated: 2023/08/16 18:45:20 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include "philo.h"

void	ft_free(void *ptr)
{
	if (ptr == NULL)
		return ;
	free(ptr);
	ptr = NULL;
}

int	ft_phsize(t_info *info)
{
	return (info->number_of_philos);
}

int	ft_wait(int number)
{
	int	wait;

	if (number < 90)
		wait = 100 + 10 * number;
	else
		wait = 1000;
	return (usleep(wait));
}
