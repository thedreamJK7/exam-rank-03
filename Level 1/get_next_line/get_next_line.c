#include "get_next_line.h"

int ft_getchar(int fd)
{
	static	t_buffer buff;

	if (buff.n == 0)
	{
		buff.n = read(fd, buff.buffer, BUFFER_SIZE);
		if (buff.n < 0)
		{
			buff.n = 0;
			return (-13);
		}
		buff.bufp = buff.buffer;
	}
	if (--buff.n >= 0)
	{
		return ((unsigned char)*buff.bufp++);
	}
	buff.n = 0;
	return (EOF);
}

int ft_putc(t_string *str, char c)
{
	char	*tmp;
	size_t	i;

	if (str->len + 1 > str->capa)
	{
		tmp = str->str;
		str->str = malloc(sizeof(char) * (str->capa + BLOCK_SIZE));
		if (!str->str)
		{
			free(tmp);
			return (-13);
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

char	*get_next_line(int fd)
{
	t_string str;
	char		c;

	str.str = NULL;
	str.capa = 0;
	str.len = 0;
	while (1)
	{
		c = ft_getchar(fd);
		if (c == -13)
		{
			free(str.str);
			return (NULL);
		}
		if (c == EOF)
			break ;
		if (ft_putc(&str, c))
			return (NULL);
		if (c == '\n')
			break;
	}
	if (str.len > 0)
		if (ft_putc(&str, '\0'))
			return (NULL);
	return (str.str);
}
