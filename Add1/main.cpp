#include <iostream>


void rec (int A)
{
    if (A % 2 == 1) std::cout << "N is not a power of two"<<std::endl;
    else if (A!=2)
    {
        rec(A/2);
    }
    
    if (A==2) std::cout << "N is a power of two"<<std::endl;
}

int main()
{
    int N;
    std::cin >> N;
    
    if ((N<0) || (N>=1000000000))
    {
        std::cout << "N is incorrect"<<std::endl;
    }
    else
    {
        if (N % 2 == 1)
        {
            std::cout << "N is odd"<<std::endl;
        }
        else
        {
            rec (N);
        }
    }
    
    return 0;
}
