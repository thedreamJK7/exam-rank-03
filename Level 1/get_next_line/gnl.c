# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# define BLOCK_SIZE 4096
# define READ_ERROR -99

# include <stddef.h>
# include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_buffer
{
	ssize_t	n;
	char	*bufp;
	char	buf[BUFFER_SIZE];
}			t_buffer;

typedef struct s_string
{
	char	*str;
	size_t	len;
	size_t	capa;
}			t_string;

static int	ft_getc(int fd)
{
	static t_buffer	buf;

	if (buf.n == 0)
	{
		buf.n = read(fd, buf.buf, BUFFER_SIZE);
		if (buf.n < 0)
		{
			buf.n = 0;
			return (READ_ERROR);
		}
		buf.bufp = buf.buf;
	}
	if (--buf.n >= 0)
	{
		return ((unsigned char)*buf.bufp++);
	}
	buf.n = 0;
	return (EOF);
}

static int	ft_putc(t_string *str, char c)
{
	size_t	i;
	char	*tmp;

	if (str->len + 1 > str->capa)
	{
		tmp = str->str;
		str->str = (char *)malloc((str->capa + BLOCK_SIZE) * sizeof(char));
		if (!str->str)
		{
			free(tmp);
			return (1);
		}
		i = 0;
		while (i < str->len)
		{
			str->str[i] = tmp[i];
			i++;
		}
		free(tmp);
		str->capa += BLOCK_SIZE;
	}
	str->str[str->len] = c;
	str->len++;
	return (0);
}

char	*get_next_line1(int fd)
{
	t_string	str;
	char		c;

	str.str = NULL;
	str.len = 0;
	str.capa = 0;
	while (1)
	{
		c = ft_getc(fd);
		if (c == READ_ERROR)
		{
			free(str.str);
			return (NULL);
		}
		if (c == EOF)
			break ;
		if (ft_putc(&str, c))
			return (NULL);
		if (c == '\n')
			break ;
	}
	if (str.len > 0)
		if (ft_putc(&str, '\0'))
			return (NULL);
	return (str.str);
}