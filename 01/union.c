#include <unistd.h>

int main (int argc, char **argv)
{
    int i = 0;
    int ascii[255];
    int ar;

    if (argc == 3)
    {
        while(i < 255)
        {
            ascii[i] = 0;
            i++;
        }
        i = 0;
        while (argv[1][i])
        {
            ar = (int)argv[1][i];
            if (ascii[ar] == 0)
            {
                write(1, &argv[1][i], 1);
                ascii[ar] = 1;
            }
            i++;
        }
        i = 0;
        while (argv[2][i])
        {
            ar = (int)argv[2][i];
            if (ascii[ar] == 0)
            {
                write(1, &argv[2][i], 1);
                ascii[ar] = 1;
            }
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}
