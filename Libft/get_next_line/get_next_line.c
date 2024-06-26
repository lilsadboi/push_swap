/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorelli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 09:32:40 by gmorelli          #+#    #+#             */
/*   Updated: 2022/10/26 16:53:51 by gmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	*get_line(char *temp, char *buf)
{
	char	*newbuf;

	newbuf = ft_strjoin(temp, buf);
	free(temp);
	return (newbuf);
}

static char	*get_first_line(int fd, char *temp)
{
	int		i;
	char	*buf;

	if (temp == 0)
		temp = ft_calloc(1, 1);
	buf = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	i = 1;
	while (i > 0)
	{
		if (ft_strchr(temp, '\n'))
			break ;
		i = read(fd, buf, BUFFER_SIZE);
		if (i < 0)
		{
			free(buf);
			return (0);
		}
		buf[i] = '\0';
		temp = get_line(temp, buf);
	}
	free(buf);
	return (temp);
}

static char	*get_return(char *temp)
{
	int		i;
	char	*str;

	i = 0;
	if (!temp[i])
		return (0);
	while (temp[i] != '\n' && temp[i] != '\0')
		i++;
	if (temp[i] == '\n')
		i++;
	str = ft_calloc(i + 1, sizeof(char));
	i = 0;
	while (temp[i] != '\n' && temp[i] != '\0')
	{
		str[i] = temp[i];
		i++;
	}
	if (temp[i] == '\n')
		str[i] = '\n';
	return (str);
}

static char	*ft_leftover(char *temp)
{
	int		i;
	int		y;
	char	*str;

	i = 0;
	y = 0;
	while (temp[i] != '\n' && temp[i] != '\0')
		i++;
	if (temp[i] == '\n')
		i++;
	if (!temp[i])
	{
		free(temp);
		return (0);
	}
	str = ft_calloc((ft_strlen(temp) - i + 1), sizeof(char));
	i++;
	while (temp[i] != '\0')
	{
		str[y] = temp[i];
		y++;
		i++;
	}
	free(temp);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*temp[4096];
	char		*ret;
	int			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (fd == -42)
	{
		while (i < 4096)
		{
			if (!temp[i][0])
				free(temp[i]);
			i++;
		}
	}
	temp[fd] = get_first_line(fd, temp[fd]);
	ret = get_return(temp[fd]);
	temp[fd] = ft_leftover(temp[fd]);
	return (ret);
}
