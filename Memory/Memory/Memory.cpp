#include <iostream>

#include "fibo.h"

void demoSwithCase(int n) 
{
    switch (n)
    {
    case 0:
    case 1:
        std::cout << "case 0 or 1";
        break;
    case 2:
        std::cout << "case 2";
        break;
    default:
        std::cout << "default";
    }
    // TODO something here
    std::cout << std::endl << std::endl;
}

int f(int a) 
{
    int y = a * 3;
    std::cout << "@a:" << &a << std::endl
        << "@y:" << &y << std::endl;
    return y;
}


int main()
{
    int x = 0;
    int z = f(x);
    std::cout << "@x:" << &x << std::endl
        << "@z:" << &z << std::endl;
    std::cout << "@main:" << &main << std::endl
        << "@f:" << &f << std::endl;
    
    // crash test stack limit
    int n = 100;
   /* uint64_t res1 = fiboSwitch(n);
    uint64_t res2 = fiboIf(n);*/
    uint64_t res3 = fiboFor(n);
    std::cout << "Fibo: " 
        /*<< res1 << std::endl
        << res2 << std::endl*/
        << res3 << std::endl;
    demoSwithCase(0);
    demoSwithCase(1);
    demoSwithCase(2);
    demoSwithCase(10);

}

