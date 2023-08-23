/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 13:10:43 by dajeon            #+#    #+#             */
/*   Updated: 2023/08/11 14:12:28 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "lib.h"
#define INT_MAX 2147483647

int	ft_check_ispos(char *nptr);
int	**info_list_new(t_info *info, int size);
int	info_list_set(int **info_list, int argc, char **argv);

int	parser(t_info *info, int argc, char **argv)
{
	int	**info_list;

	if (argc != 5 && argc != 6)
	{
		ft_putendl_fd("philo: invalid argument number", 2);
		return (-1);
	}
	info_list = info_list_new(info, 5);
	if (info_list_set(info_list, argc, argv) < 0)
		return (-1);
	free(info_list);
	return (0);
}

int	info_list_set(int **info_list, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < 6)
	{
		if (i == argc)
			*(info_list[i - 1]) = INT_MAX;
		else
		{
			if (ft_check_ispos(argv[i]) == 0)
			{
				free(info_list);
				ft_putendl_fd("philo: invalid argument type", 2);
				return (-1);
			}
			*(info_list[i - 1]) = ft_atoi(argv[i]);
		}
		i++;
	}
	return (0);
}

int	**info_list_new(t_info *info, int size)
{
	int	**list;
	int	i;

	list = (int **)malloc(sizeof(int *) * size);
	if (list == NULL)
		return (NULL);
	i = 0;
	list[i++] = &(info->number_of_philos);
	list[i++] = &(info->time_to_die);
	list[i++] = &(info->time_to_eat);
	list[i++] = &(info->time_to_sleep);
	list[i] = &(info->number_of_times);
	return (list);
}

int	ft_check_ispos(char *nptr)
{
	if (ft_isspace(*nptr))
		nptr += ft_duplen(nptr, " ");
	if (*nptr == '+')
		nptr++;
	if (*nptr == '-')
		return (0);
	if (ft_isin(*nptr, "0123456789"))
	{
		nptr += ft_duplen(nptr, "0123456789");
		if (*nptr)
			return (0);
	}
	else
		return (0);
	return (1);
}
