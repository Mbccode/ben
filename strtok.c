#include "shell.h"

/**
* _strtok - Tokenizes  array of strings
* @str: string variable
* @delim: delimiter
* Return: return the value of "tok_St" on success
*/
char *_strtok(char *str, const char *delim)
{
	char *tok_St;
	char *tok_End;
	static char *next_Tok;

	if (str != NULL)
		next_Tok = str; /* Initialize or reset the tokenized */

	if (next_Tok == NULL || *next_Tok == '\0')
		return (NULL); /* No more tokens to parse*/

	tok_St = strtok_help(next_Tok, delim); /* Find the start of the next token */
	tok_End = _strpbrk(tok_St, delim); /* Find the end of the token */

	if (tok_End != NULL)
	{
		tok_End = '\0'; /* Replace the delimiter with a null terminator */
		next_Tok = tok_End + 1; /* Set the nextToken pointer for the next call */
	}
	else
	{
		next_Tok = NULL; /* No more tokens */
	}
	return (tok_St); /* Return the current token */
}


/************ strtok_help Function************/

/**
 * strtok_help - Entry point
 * @str: string variable
 * @delim: delimiter
 * Return: return the value of "str" on success
 */

char *strtok_help(char *str, const char *delim)
{
	while (*str != '\0' && _strchr(delim, *str) != NULL)
		str++;
	return (str);
}

/*********** _STRBRK FUNCTION *************/

/**
 * _strpbrk - search a string for any of a set of bytes
 * @strGet: string to searched through
 * @strSET: string that has a byte to be located
 *
 * Return: a pointer to the byte in strGet that matches
 * one of the bytes in strSET, or NULL if not found.
 */
char *_strpbrk(const char *strGet, const char *strSET)
{
	while (*strGet != '\0')
	{
		const char *str_set = strSET;

		while (*str_set != '\0')
		{
			/* If condition is true "strGet" is type cast char* */
			if (*strGet == *str_set)
				return ((char *)strGet);
			str_set++;
		}
		strGet++;
	}
	return (NULL);
}

/********** _STRCHR FUNCTION **********/

/**
 * _strchr - Function that iterates through a string to find
 * a character
 * @strGet: String to be iterated.
 * @charGet: Character to be found.
 * Return: A pointer to the character in the string or NULL
 *         if character is not found.
 */
char *_strchr(const char *strGet, int charGet)
{
	while (*strGet != '\0')
	{
		/* strGet is cast to char* if condition is through*/
		if (*strGet == charGet)
			return ((char *)strGet);
		strGet++;
	}
	return (NULL);
}
