/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 13:09:58 by dajeon            #+#    #+#             */
/*   Updated: 2023/08/16 18:41:04 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include <stdlib.h>
# include <unistd.h>

int		ft_isin(int a, char const *b);
int		ft_toklen(const char *s, const char *set);
int		ft_duplen(const char *s, const char *set);
void	ft_free(void *ptr);
ssize_t	ft_putendl_fd(char *s, int fd);
size_t	ft_strlen(const char *s);
int		ft_isspace(int c);
int		ft_atoi(const char *nptr);

#endif
