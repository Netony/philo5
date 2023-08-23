/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 18:42:45 by dajeon            #+#    #+#             */
/*   Updated: 2023/08/16 18:42:51 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIME_H
# define TIME_H
# include <sys/time.h>
# include <stdlib.h>

typedef struct timeval	t_time;

int	ft_timeinit(t_time *time);
int	ft_timenow(t_time *from);
int	ft_timediff(t_time *a, t_time *b);

#endif
