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
ll int dp[210][12][22][2];
int n,m,MOD;
int arr[1200];
int mod(int n)
{
    if(n<0)
        n+=(ceil(-n*1.00/MOD)*MOD);
    return n%MOD;
}
ll int rec(int pos,int take,int sum ,int flag)
{
    if(pos>n)
    return 0;
    if(take==m)
    {
//        printf("summ--->%d \n",sum);
        if(sum%MOD==0 && flag)
        return 1;
        return 0;
    }
    if(pos==n)
    return 0;
    if(dp[pos][take][sum][flag]!=-1)
    return dp[pos][take][sum][flag];
    ll int ret=0;
    ret+=rec(pos+1,take,sum,flag);
    ret+=rec(pos+1,take+1,mod(sum+mod(arr[pos])),1);
    return dp[pos][take][sum][flag]=ret;
}
int main()
{
    int t,q,cs=1;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d %d",&n,&q);
        if(n==0 && q==0)
        return 0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);

        }
        printf("Case %d:\n",cs++);
        for(int QQ=1;QQ<=q;QQ++)
        {
            scanf("%d %d",&MOD,&m);
            memset(dp,-1,sizeof dp);
            ll int ans=rec(0,0,0,0);
            printf("%lld\n",ans);
        }

    }

    return 0;
}
