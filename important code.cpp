#include <iostream>
#include <fstream>
#include <cstring>
 
using namespace std;
ifstream f("adunare.in");
ofstream g("adunare.out");
long long a,b;
 
int main()
{
    f>>a>>b;
    g<<a+b<<'\n';
    return 0;
}