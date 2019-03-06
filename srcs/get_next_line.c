/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkozlov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 15:00:42 by kkozlov           #+#    #+#             */
/*   Updated: 2019/03/06 12:41:57 by kkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		del_content(void *content, size_t content_size)
{
	if (content_size)
		free(content);
}

static size_t	get_len(t_queue *qu)
{
	size_t	len;
	t_list	*itr;

	len = 0;
	if (!qu || !qu->head)
		return (len);
	itr = qu->head;
	while (itr && itr->content_size
			&& ft_strncmp(itr->content, "\n", 1))
	{
		len += itr->content_size;
		itr = itr->next;
	}
	return (len);
}

static int		fill_line(t_queue *qu, char **line)
{
	char	*itr;
	size_t	total;
	t_list	*chunk;

	total = get_len(qu);
	*line = malloc((total + 1) * sizeof(char));
	if (!*line)
		return (-1);
	*(*line + total) = '\0';
	itr = *line;
	while (ft_queuepeek(qu) && ft_strncmp(ft_queuepeek(qu)->content, "\n", 1))
	{
		chunk = ft_dequeue(qu);
		if (chunk->content_size)
			ft_strncpy(itr, chunk->content, chunk->content_size);
		itr += chunk->content_size;
		ft_lstdelone(&chunk, &del_content);
	}
	if (ft_queuepeek(qu) && !ft_strncmp(ft_queuepeek(qu)->content, "\n", 1))
	{
		chunk = ft_dequeue(qu);
		ft_lstdelone(&chunk, &del_content);
	}
	return (1);
}

static int		fill_queue(t_queue *queue, char *buf, int ret)
{
	char	*itr;

	buf[ret] = '\0';
	ret = 0;
	while (buf && *buf)
	{
		itr = ft_strchr(buf, '\n');
		if (itr)
		{
			if (itr - buf)
				ft_enqueue(queue, buf, (itr - buf));
			ft_enqueue(queue, itr, sizeof(char));
			ret = 1;
			buf = itr + 1;
		}
		else
		{
			ft_enqueue(queue, buf, ft_strlen(buf));
			return (ret);
		}
	}
	return (ret);
}

int				get_next_line(const int fd, char **line)
{
	static t_queue	*qus[MAX_FDS];
	char			buf[BUFF_SIZE + 1];
	int				ret;

	if (!line || fd < 0 || fd >= MAX_FDS)
		return (-1);
	if (!qus[fd])
	{
		qus[fd] = ft_queuenew(NULL, 0);
		if (!qus[fd])
			return (-1);
	}
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
		if (fill_queue(qus[fd], buf, ret))
			break ;
	if (ret == -1 || (ret == 0 && ft_queuepeek(qus[fd]) == 0))
	{
		ft_queuedel(&qus[fd], &del_content);
		return (ret);
	}
	if ((ret = fill_line(qus[fd], line)) == -1)
		ft_queuedel(&qus[fd], &del_content);
	return (ret);
}
