#include <iostream>
using namespace std;

main ();
void cuenta (int n)
{
    if(n == 0)
    {
        return;
    }
    cout << n << endl;
    cuenta (n-1);
}