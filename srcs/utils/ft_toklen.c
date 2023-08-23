/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toklen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 20:21:34 by dajeon            #+#    #+#             */
/*   Updated: 2023/08/16 17:58:16 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	ft_toklen(const char *s, const char *set)
{
	int	len;

	len = 0;
	while (*s)
	{
		if (ft_isin(*s, set) == 0)
		{
			s++;
			len++;
		}
		else
			break ;
	}
	return (len);
}

int	ft_duplen(const char *s, const char *set)
{
	int	len;

	len = 0;
	while (*s)
	{
		if (ft_isin(*s, set))
		{
			s++;
			len++;
		}
		else
			break ;
	}
	return (len);
}

int	ft_nextlen(const char *s, const char *set)
{
	int	len;

	len = ft_duplen(s, set);
	len += ft_toklen(s + len, set);
	return (len);
}

int	ft_nextptr(const char *s, const char *set)
{
	int	len;

	len = ft_toklen(s, set);
	len += ft_duplen(s + len, set);
	return (len);
}

int	ft_isin(int a, char const *b)
{
	int	i;

	i = 0;
	while (b[i])
	{
		if (a == b[i])
			return (1);
		i++;
	}
	return (0);
}
