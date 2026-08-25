#include <iostream>
#include <cctype>

int main(int ac, char** av)
{
    int i;

    i = 1;
    if(ac > 1)
    {
        while(av[i])
        {
            int j;
            
            j = 0;
            while(av[i][j])
            {
                std::cout << (char)std::toupper((unsigned char)av[i][j]);
                j++;
            }
            i++;
        }
        std::cout << std::endl;
    }
    else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return 0;
}
