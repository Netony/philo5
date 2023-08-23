#ifndef MONITOR_H
# define MONITOR_H

# include "philo.h"

typedef struct s_monitor
{
	pthread_t	thread;
	int			name;
	t_philo		*philos;
	t_info		*info;
}	t_monitor;

int			ft_monitor(t_philo *philos, t_info *info);
t_monitor	*ft_mtsinit(int size, t_philo *philos, t_info *info);
int			ft_mtsdel(t_monitor *mts, int size);
#endif
