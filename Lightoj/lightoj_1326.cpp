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
#define MOD 10056
int dp[1010];
int comb[1004][1004];
int rec(int n)
{
    if(dp[n]!=-1)
        return  dp[n];
    int ret=0;
    for(int i=1; i<n; i++)
    {
        ret+=((rec(n-i)%MOD)*(comb[n][i])%MOD)%MOD;
        ret%=MOD;
    }
    return dp[n]= (ret+1)%MOD;
}
void prec_nCr(void)
{
    for(int i=0; i<=1000; i++)
        comb[i][0]=1;
    for(int i=1; i<=1000; i++)
        for(int j=1; j<=i; j++)
            comb[i][j]=(comb[i-1][j]+comb[i-1][j-1])%MOD;
    return ;
}
int main()
{
    int t;
    prec_nCr();
    scanf("%d",&t);
    memset(dp,-1,sizeof(dp));
    dp[1]=1;
    for(int cs=1; cs<=t; cs++)
    {
        int n;
        scanf("%d",&n);
        printf("Case %d: %d\n",cs,rec(n));
    }
    return 0;
}
