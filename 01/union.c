#include <unistd.h>

int main void(int argc, char **argv)
{
    int i = 0;
    int ascii[255];

    if (argc == 3)
    {
        while(ascii[i])
        {
            ascii[i] = 0;
            i++;
        }
        i = 0;
        while (argv[1][i])
        {
            if (ascii[i] == 0)
            {
                write(1, argv[1][i], 1);
                ascii[i] = 1;
            }
        }
        i = 0;
        while (argv[2][i])
        {
            if (ascii[i] == 0)
            {
                write(1, argv[1][i], 1);
                ascii[i] = 1;
            }
        }
    }
    write(1, "\n", 1);
    return (0);
}
