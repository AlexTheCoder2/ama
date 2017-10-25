#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <algorithm>
 
//131702
using namespace std;
ifstream f("ghicit.in");
ofstream g("ghicit.out");
struct miau{int val1, val2, poz;} v[66000];
struct miau2{int val, poz;} v2[66000];
int n,m,i,j,p[18][132000],pas=1,lungime,pasmax,nrdif;
long long sol;
char s[132000];
 
bool cmp(miau a, miau b)
{
    return (a.val1<b.val1 ||(a.val1==b.val1 && a.val2<b.val2));
}
 
bool cmp2(miau2 a, miau2 b)
{
    return a.val<b.val;
}
 
int lcp(int a, int b)
{
    int val=0,pas=pasmax;
    if(a==b) return n-a;
    for(pas=pasmax;pas>=0 && a<n && b<n;pas--)
    {
        if(p[pas][a]==p[pas][b]) val+=1<<pas, a+=1<<pas, b+=1<<pas;
    }
    return val;
}
 
int main()
{
    f.getline(s,50300);
    lungime=n=strlen(s);
    while(lungime<131703) s[lungime]='$',lungime++;
    s[lungime]=0;
    for(i=0;i<n;i++) p[0][i]=s[i]-'a'+1;
 
    for(pas=1;(1<<pas-1)<=n;pas++)
    {
        for(i=0;i<n;i++) v[i]={p[pas-1][i],p[pas-1][i+(1<<(pas-1))],i};
        sort(v,v+n,cmp);
        nrdif=1;
        p[pas][v[0].poz]=1;
        for(i=1;i<n;i++)
        {
            if(!(v[i].val1==v[i-1].val1 && v[i].val2==v[i-1].val2)) nrdif++;
            p[pas][v[i].poz]=nrdif;
        }
        pasmax=pas;
    }
    sol=1LL*n*(n+1)/2;
    for(i=0;i<n;i++) v2[i]={p[pasmax][i],i};
    sort(v2,v2+n,cmp2);
    for(i=0;i<n-1;i++) sol-=lcp(v2[i].poz,v2[i+1].poz);
    g<<sol<<'\n';
    return 0;
}