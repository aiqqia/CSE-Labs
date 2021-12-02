#ifndef __REMOVEEXCESS_H__
#define __REMOVEEXCESS_H__
int removeExcess(char *fileName)
{ // to remove spaces, tabs and comments
	FILE *fa, *fb;
	int ca, cb;
	fa = fopen(fileName, "r");
	if (fa == NULL)
	{
		printf("Cannot open file \n");
		exit(0);
	}
	fb = fopen("space_output.c", "w");
	ca = getc(fa);
	while (ca != EOF)
	{
		if (ca == ' ' || ca == '\t')
		{
			putc(' ', fb);
			while (ca == ' ' || ca == '\t')
				ca = getc(fa);
		}
		if (ca == '/')
		{
			cb = getc(fa);
			if (cb == '/')
			{
				while (ca != '\n')
					ca = getc(fa);
			}
			else if (cb == '*')
			{
				do
				{
					while (ca != '*')
						ca = getc(fa);
					ca = getc(fa);
				} while (ca != '/');
			}
			else
			{
				putc(ca, fb);
				putc(cb, fb);
			}
		}
		else
			putc(ca, fb);
		ca = getc(fa);
	}
	putc('$', fb);
	fclose(fa);
	fclose(fb);
	return 0;
}
#endif