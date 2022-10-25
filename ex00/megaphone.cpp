#include <iostream>

int main(int argc, char **argv)
{
    int     i;
    size_t  j;

    i = 1;
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    else 
    {
        while(argv[i])
        {
            std::string str(argv[i]);
            j = 0;
            while (j < str.length())
            {
                std::cout << (char)std::toupper(str[j]);
                j++;  
            }
            i++;
        }
        std::cout << std::endl;
    }
    return (0);
}