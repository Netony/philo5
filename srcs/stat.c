#include "status.h"

int	ft_stinit(t_stat *stat)
{
	stat->stat = 0;
	pthread_mutex_init(&(stat->m_stat), NULL);
	return (0);
}

int	ft_stdel(t_stat *stat)
{
	pthread_mutex_destroy(&(stat->m_stat));
	return (0);
}

t_stat	*stats_new(int size)
{
	t_stat	*stats;
	int		i;

	i = 0;
	stats = (t_stat *)malloc(sizeof(t_stat) * size);
	if (stats == NULL)
		return (NULL);
	while (i < size)
		stat_init(&stats[i++]);
	return (stats);
}

int	stats_destroy(t_stat *stats, int size)
{
	t_stat	*stats;
	int		i;

	i = 0;
	while (i < size)
		stat_destroy(&stats[i++]);
	free(stats);
	return (0);
}
