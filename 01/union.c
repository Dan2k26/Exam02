#include <unistd.h>

void	union1(const char *s1, const char *s2)
{
	int asci[255];
	int i = 0;

	while (i < 255)
		asci[i++] = 0;
	while (*s1)
	{
		if (!asci[(int)(*s1)])
		{
			write(1, s1, 1);
			asci[(int)(*s1)] = 1;
		}
		++s1;
	}
	while (*s2)
	{
		if (!asci[(int)(*s2)])
		{
			write(1, s2, 1);
			asci[(int)(*s2)] = 1;
		}
		++s2;
	}
	write(1, "\n", 1);
}

int main(int argc, char **argv)
{
	if (argc == 3)
		union1(argv[1], argv[2]);
	else
		write(1, "\n", 1);		
	return (0);
}
