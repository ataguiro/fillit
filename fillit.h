/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 17:31:59 by ataguiro          #+#    #+#             */
/*   Updated: 2016/11/22 09:21:57 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct	s_fillit
{
	int		p;
	int		pos[4][2];
	char	c;
}				t_fillit;

typedef struct	s_info
{
	int		min;
	int		n;
}				t_info;

typedef struct	s_rec
{
	int		j;
	int		i;
	char	c;
	int		count;
}				t_rec;

typedef struct	s_rec2
{
	int		nb;
	int		p;
	int		max;
	int		i;
}				t_rec2;

void			ft_fill_some(t_fillit **linear, int n);
t_fillit		*ft_full_it(char *file, t_info *l);
int				ft_resolve(t_fillit **f, t_info *l, char **map);
int				ft_check(char *file);
char			*ft_filetobuff(char *file);

#endif
