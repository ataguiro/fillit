/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 17:28:13 by ataguiro          #+#    #+#             */
/*   Updated: 2016/11/22 09:32:45 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_check_diezline(char *buff, char a)
{
	int	count;
	int	j;

	count = 0;
	j = 0;
	while (buff[j])
	{
		while (buff[j])
		{
			if (buff[j] == a)
				count++;
			if (buff[j] == '\n' && buff[j + 1] == '\n')
				break ;
			j++;
		}
		if (count != 4)
			return (0);
		count = 0;
		j += 2;
	}
	return (1);
}

static int	ft_append(char *line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] == '#')
		{
			count++;
			if (line[i + 1] == '#' && line[i + 3] == '#' && line[i + 8] == '#')
				return (0);
			if (count != 4 && line[i + 1] != '#' && line[i + 5] != '#'
				&& line[i - 1] != '#')
				return (0);
			if (count == 2 && line[i + 1] != '#' && line[i + 2] != '#'
					&& line[i + 3] != '#' && line[i + 4] != '#'
					&& line[i + 5] != '#')
				return (0);
			if (count == 4 && line[i - 1] != '#' && line[i - 5] != '#')
				return (0);
		}
		i++;
	}
	return (1);
}

static int	ft_check_disp(char *buff)
{
	int		i;
	int		j;
	char	*tmp;

	tmp = (char *)malloc(sizeof(char) * 1000);
	i = 0;
	j = 0;
	while (buff[i])
	{
		if ((buff[i] == '\n' && buff[i + 1] == '\n')
			|| (buff[i] == '\n' && buff[i + 1] == '\0'))
		{
			if (!ft_append(tmp))
				return (0);
			j = 0;
		}
		tmp[j] = buff[i];
		i++;
		j++;
	}
	return (1);
}

static int	ft_check_column(char *buff)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (buff[i])
	{
		if (buff[i] == '.' || buff[i] == '#')
			count++;
		else if (buff[i] == '\n' && buff[i - 1] != '\n' && count != 4)
			return (0);
		if (buff[i] == '\n')
			count = 0;
		i++;
	}
	return (1);
}

int			ft_check(char *file)
{
	char	*buff;
	int		i;

	i = 0;
	buff = ft_filetobuff(file);
	while (buff[i])
		i++;
	if (!ft_check_diezline(buff, '\n') || !ft_check_diezline(buff, '#')
		|| !ft_check_column(buff) || !ft_check_disp(buff) || !buff[0] ||
		(buff[i - 1] == '\n' && buff[i - 2] == '\n'))
		return (0);
	return (1);
}
