











#include "get_next_line.h"

char *read_and_stash(int fd, char *stash)
{
    char *buffer;
    ssize_t count;

    count = BUFFER_SIZE;
    buffer = malloc(sizeof(char) * (BUFFER_SIZE+ 1));
    if (!buffer)
        return (NULL);
    while (count)
    {
        count = read(fd, buffer, BUFFER_SIZE);
		printf("%zd", count);
        if (count == -1)
		{
			free(buffer);
			return (NULL);
		}
        buffer[count] = '\0';
        stash = ft_strjoin(stash, buffer);
    }
    free(buffer);
    return (stash);
}

char *extract_line(char *line_in)
{
    int i;
    int len;
    char *line_out;

    len = 0;
	if (!line_in[len])
		return (NULL);
    while (line_in[len] && line_in[len] != '\n')
        len++;
    if (line_in[len] == '\n')
		len++;
    line_out = malloc(sizeof(char) * (len + 1));
    if (!line_out)
		return (NULL);
    i = 0;
    while (i < len)
    {
        line_out[i] = line_in[i];
        i++;
    }
    line_out[i] = '\0';
    return(line_out);
}

char	*clean_up(char *line_in)
{
	char	*cleaned_line;
	int		len;
	int		i;

	if (!line_in)
		return (NULL);
	len = 0;
	while (line_in[len] && line_in[len] != '\n')
		len++;
	if (line_in[len] == '\n')
	{
		len++;
		cleaned_line = malloc(sizeof(char) * (ft_strlen(line_in + len) + 1));
		if (cleaned_line)
		{
			i = 0;
			while (line_in[len])
				cleaned_line[i++] = line_in[len++];
			cleaned_line[i] = '\0';
		}
		free(line_in);
		return (cleaned_line);
	}
	free(line_in);
	return (NULL);
}

char *get_next_line(int fd)
{
    static char *stash;
    char        *return_line;

	if (read(fd, NULL, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
    stash = read_and_stash(fd, stash);
	return_line = extract_line(stash);
    stash = clean_up(stash);
    return (return_line);
}

int main()
{
	int		fd;
	char	*line;

	fd = open("two_lines_with_nl", O_RDONLY);
	// while (1)
	// {
		line = get_next_line(fd);
		printf("%s", line);
		// if (line == NULL)
		// 	break ;
		free(line);
	// }
	return (0);
}