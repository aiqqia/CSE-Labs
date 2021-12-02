#ifndef __REMOVEPREPROCESS_H__
#define __REMOVEPREPROCESS_H__
int removePreprocess()
{ // to ignore preprocessor directives
	FILE *finp = fopen("space_output.c", "r");
	char c = 0;
	char buffer[100];
	buffer[0] = '\0';
	int i = 0;
	char *includeStr = "include", *defineStr = "define", *mainStr = "main";
	int mainFlag = 0, row = 1;
	while (c != EOF)
	{
		c = fgetc(finp);
		if (c == '#' && mainFlag == 0)
		{
			c = 'a';
			while (isalpha(c) != 0)
			{
				c = fgetc(finp);
				buffer[i++] = c;
			}
			buffer[i] = '\0';
			if (strstr(buffer, includeStr) != NULL || strstr(buffer, defineStr) != NULL)
			{
				row++;
				while (c != '\n')
				{
					c = fgetc(finp);
				}
			}
			else
			{
				for (int j = 0; j < i; j++)
					;
				while (c != '\n')
				{
					c = fgetc(finp);
				}
			}
			i = 0;
			buffer[0] = '\0';
		}
		else
		{
			if (mainFlag == 0)
			{
				buffer[i++] = c;
				buffer[i] = '\0';
				if (strstr(buffer, mainStr) != NULL)
				{
					mainFlag = 1;
				}
			}
			if (c == ' ' || c == '\n')
			{
				buffer[0] = '\0';
				i = 0;
			}
		}
	}
	fclose(finp);
	return row;
}
#endif