// Name Froilan Buendia
// Class (CECS 325-01)
// Project Name (Prog 0 – Install Linux and C++)
// Due Date 08/29/2022
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.

#include <iostream>
using namespace std;
// Fibo function
int fibo(int n)
{
    if (n == 1 || n == 0)
        return 1;
    else
        return fibo(n-1) + fibo(n-2); // recursion
}
int main()
{
    for (int i = 1; i <= 20; i++)
        cout << i << ":" << fibo(i)<<endl;
        
    return 0;
}