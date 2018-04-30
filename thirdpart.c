/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thirdpart.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 17:54:17 by ataguiro          #+#    #+#             */
/*   Updated: 2016/11/22 09:18:13 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_fill_some(t_fillit **linear, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		(*linear)[i].p = -1;
		i++;
	}
}

static void	ft_min_map(t_info *l)
{
	int		t;

	t = 0;
	while (t * t < l->n * 4)
		t++;
	l->min = t;
}

static char	*ft_generate_map(int size)
{
	int		i;
	char	*map;

	i = 1;
	map = (char *)malloc(sizeof(char) * (size * size) + size);
	while (i < (size * size) + size)
	{
		if (i % (size + 1) == 0 && i != 0)
			map[i - 1] = '\n';
		else
			map[i - 1] = '.';
		i++;
	}
	map[i - 1] = '\n';
	map[i] = 0;
	return (map);
}

int			main(int argc, char **argv)
{
	t_fillit	*linear;
	t_info		l;
	char		*map;

	if (argc != 2)
	{
		write(1, "usage: ./fillit file\n", 21);
		return (0);
	}
	if (!ft_check(argv[1]) || open(argv[1], O_RDONLY) == -1)
	{
		write(1, "error\n", 6);
		return (0);
	}
	linear = ft_full_it(argv[1], &l);
	ft_min_map(&l);
	map = ft_generate_map(l.min);
	while (ft_resolve(&linear, &l, &map) != 1)
	{
		l.min++;
		ft_strdel(&map);
		map = ft_generate_map((&l)->min);
	}
	return (0);
}
