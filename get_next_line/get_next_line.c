/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoral-p <dmoral-p@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 10:18:40 by dmoral-p          #+#    #+#             */
/*   Updated: 2024/03/29 09:17:03 by dmoral-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "get_next_line.h"

static char	*ft_return(char *buffer)
{
	free(buffer);
	return (NULL);
}

static char	*ft_record(char *buffer, char *line)
{
	int		len;
	int		i;
	int		j;
	char	*remind;

	i = 0;
	j = 0;
	if (!line)
		return (ft_return(buffer));
	while (line[i])
		++i;
	len = ft_strlen(&buffer[i]) + 1;
	remind = (char *)malloc(sizeof(char) * len);
	if (!remind)
		return (ft_return(buffer));
	while (buffer[i])
		remind[j++] = buffer[i++];
	remind[j] = '\0';
	free(buffer);
	return (remind);
}

static char	*ft_line(char *buffer)
{
	char	*line;
	char	*end;
	int		len;
	int		i;

	i = 0;
	end = ft_strchr(buffer, '\n');
	if (!end)
		return (ft_strdup(buffer));
	len = (end - buffer) + 2;
	line = (char *)malloc(sizeof(char) * len);
	if (!line)
		return (NULL);
	while (&buffer[i] != end + 1)
	{
		line[i] = buffer[i];
		++i;
	}
	line[i] = '\0';
	if (ft_strlen(line) == 0)
		return (NULL);
	return (line);
}

static char	*ft_read_file(char *buffer, int fd)
{
	char	*read_buf;
	int		bytes_read;

	read_buf = (char *)malloc((sizeof(char) * BUFFER_SIZE) + 1);
	if (!read_buf)
		return (ft_return(buffer));
	ft_bzero(read_buf, BUFFER_SIZE + 1);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, read_buf, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(read_buf);
			free(buffer);
			return (NULL);
		}
		buffer = ft_strjoin(buffer, read_buf);
		if (ft_strchr(buffer, '\n') || buffer == NULL)
			break ;
	}
	free(read_buf);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE == 0)
		return (NULL);
	if (!buffer)
	{
		buffer = (char *)malloc(sizeof(char) * 1);
		if (!buffer)
			return (NULL);
		buffer[0] = '\0';
	}
	buffer = ft_read_file(buffer, fd);
	if (!buffer)
		return (NULL);
	if (ft_strlen(buffer) == 0)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	line = ft_line(buffer);
	buffer = ft_record(buffer, line);
	return (line);
}
/*
int main(void)
{
	int	fd;
	char	*line;

	fd = open("multiple_nl.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close (fd);
	return (0);
}*/
