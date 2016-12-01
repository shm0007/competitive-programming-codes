/*
Shamim Ehsan
SUST CSE 12
*/
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
#include<limits.h>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<deque>
#include<algorithm>
#include<sstream>
#define PI (2* acos(0))
#define pb push_back
#define ll long long
using namespace std;
//int X[]= {0,0,1,-1};
//int Y[]= {-1,1,0,0};
//int X[]= {0,0,1,1,1,-1,-1,-1};
//int Y[]= {-1,1,0,1,-1,0,1,-1};
#define MOD  1000000007
ll bigmod(ll int n,ll int p)
{
    if(p==1)
        return n;
    if(p==0)
        return 1;
    ll int tmp =bigmod(n,p/2);
    ll int ans=((tmp%MOD)*(tmp%MOD))%MOD;
    if(p%2==1)
        ans*=n;
    ans%=MOD;
    return ans;
}
ll int fact[2000010];
//ll modular_inverse[2000010];

int main()
{

    fact[0]=1;
    for(int i=1; i<=2000000; i++)
        fact[i]=(fact[i-1]*(ll)i)%MOD;
//    for(int i=0; i<=2000000; i++)
//    {
//        modular_inverse[i]=bigmod(i,MOD-2);
//    }

    int t;
    ll int n,m,N,M;
    scanf("%d",&t);
    for(int cs=1; cs<=t; cs++)
    {
        scanf("%lld %lld",&N,&M);
        n=N+M-1;
        m=M-1;
//        printf("%lld %lld\n",n,m);
        ll int ans=(fact[n]%MOD * bigmod( ((fact[m]%MOD)*(fact[n-m]%MOD)) %MOD ,MOD-2) );
        printf("Case %d: %lld\n",cs,ans%MOD);
    }
    return 0;
}
