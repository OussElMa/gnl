#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
int     search_new_line(char *s);
char    *read_and_stash(int fd, char *stash);
char    *extract_line(char *line_in);
char	*clean_up(char *line_in);
char    *get_next_line(int fd);
# endif
