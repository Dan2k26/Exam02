#include<unistd.h>

int main (int argc, char **argv)
{
    int i = 0;
    int stop = 1;
    int y;

    if (argc == 3)
    {
        while (argv[1][i])
        {
            y = i - 1;
            if (i != 0)
            {
                while (argv[1][y])
                {
                    stop = 1;
                    if (argv[1][i] == argv[1][y])
                    {
                        stop = 0;
                        break;
                    }
                    y--;
                } 
            }   
            y = 0;
            while (argv[2][y] && stop != 0)
            {
                if (argv[1][i] == argv[2][y])
                {
                    write(1, &argv[1][i], 1);
                    break;
                }
                y++;
            }
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}
