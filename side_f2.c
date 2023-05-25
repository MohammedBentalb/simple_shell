#include "shell.h"

/**
 * _getln_side - getline helper function
 * @lane: pointer
 * @n: pointer
 * Return: Return 0 || 1
 */
int _getln_side(char **lane, size_t *n)
{
	if (*lane == NULL || *n == 0)
	{
		*n = 128;
		*lane = malloc(*n);
		if (*lane == NULL)
		return (-1);
	}
return (0);
}
/**
 * _getline - Function reads input from file
 * @lane: string input
 * @n: int input
 * @std: FILE input
 * Return: pos || 0 || -1
 */
ssize_t _getline(char **lane, size_t *n, FILE *std)
{
	ssize_t b = 0;
	size_t pos = 0, size;
	static char buffer[READ_BUF_SIZE];
	static size_t buffer_sz, buffer_pos;
	char *nw_buffer;

	if (lane == NULL || n == NULL || std == NULL
		|| _getln_side(lane, n) == -1)
		return (-1);
	while (1)
	{
		if (buffer_pos >= buffer_sz)
		{
		b = read(std->_fileno, buffer, READ_BUF_SIZE);
			if (b <= 0 && pos == 0)
				return (-1);
			else if (b <= 0)
				break;
			buffer_sz = b;
			buffer_pos = 0;
		}
		if (pos >= *n - 1)
		{
		size = *n * 2;
		nw_buffer = realloc(*lane, size);
		if (nw_buffer == NULL)
			return (-1);
		*lane = nw_buffer;
		*n = size;
		}
		(*lane)[pos++] = buffer[buffer_pos++];
		if ((*lane)[pos - 1] == '\n')
			break;
	}
(*lane)[pos] = '\0';
return (pos);
}

/**
 * _isnumber - Function that see if str is num
 * @s: string
 * Return: 1 || 0
 */
int _isnumber(const char *s)
{
	int count;

	if (s == NULL || s[0] == '\0')
		return (0);
	for (count = 0; s[count] != '\0'; count++)
	{
	if (!_isdigit(s[count]))
		return (0);
	}
return (1);
}

/**
 * _isdigit - Sub function
 * @s: int
 * Return: s >= '0' && s <= '9'
 */
int _isdigit(int s)
{
return (s >= '0' && s <= '9');
}
