#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <bitset>
#define ll long long
 
using namespace std;
ifstream f("nasa.in");
ofstream g("nasa.out");
bitset<100000001> sol;
bool ciur[50000];
unsigned int i,j,radB,A,B,nr,sq;
 
void ciurr()
{
    int i,j;
    for(i=2;i*i<=radB;i++)
    {
        if(!ciur[i])
        {
            for(j=i*i;j<=radB;j+=i) ciur[j]=1;
        }
    }
}
 
int main()
{
    f>>A>>B;
    radB=sqrt(B);
    ciurr();
    nr=B-A+1;
    for(int i=2;i<=radB;i++)
    {
        if(!ciur[i])
        {
            sq=i*i;
            j=(A-1)/sq+1;
            j*=sq;
            for(;j<=B;j+=sq)
            {
                if(sol[j-A]==0) nr--, sol[j-A]=1;
            }
        }
    }
    g<<nr<<'\n';
    return 0;
}