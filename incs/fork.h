#ifndef FORK_H
# define FORK_H
# include <pthread.h>

typedef struct s_stat
{
	int				stat;
	pthread_mutex_t	m_stat;
}	t_stat;

int		ft_stinit(t_stat *stat);
int		ft_stdel(t_stat *stat);

t_stat	*stats_new(int size);
int		stats_destroy(t_stat *stats, int size);

int		fork_take(t_stat *fork);
int		fork_release(t_stat *fork);
int		ft_stget(t_stat *stat);
int		ft_stset(t_stat *stat, int status);

#endif
