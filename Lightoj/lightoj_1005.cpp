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
ll int dp[50][50][50];
ll int rec(ll int n,ll int m,ll int k)
{
    if(k>n || k>m)
    return 0;
    if( n==0 || m==0)
    return 0;
    if(k==0)
    return 1;

    if(m==1)
    return n;
    if(dp[n][m][k]!=-1)
    return dp[n][m][k];
    return  n*rec(n-1,m-1,k-1) + rec(n,m-1,k);
}
int main()
{
   ll int t,n,k;
    scanf("%lld",&t);
    memset(dp,-1,sizeof dp);
    for(int cs=1;cs<=t;cs++)
    {
        scanf("%lld %lld",&n,&k);
        printf("Case %d: %lld\n",cs,rec(n,n,k));
    }

    return 0;
}


