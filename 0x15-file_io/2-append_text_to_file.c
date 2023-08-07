#include "main.h"

/**
 * append_text_to_file - for appending text at end of a file
 * @filename: a  pointer to the file name
 * @text_content: string added to end of file
 *
 * Return: -1 If function fails or filename is NULL
 *         -1 If file does not exist or user lacks write permissions
 *         1 Otherwise
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int o, a, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	o = open(filename, O_WRONLY | O_APPEND);
	a = write(o, text_content, len);

	if (o == -1 || a == -1)
		return (-1);

	close(o);

	return (1);
}
