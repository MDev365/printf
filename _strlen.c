/**
 * _strlen - return the length of a string
 * @s: the string
 *
 * Return: (int) the lenght of the string
 */
int _strlen(const char *s)
{
	int i;

	if (!s)
		return (0);

	for (i = 0 ; s[i] != '\0' ; i++)
	{
	}
	return (i);
}
