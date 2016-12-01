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
#define PI (2* acos(0))
#define pb push_back
#define ll long long
using namespace std;
//int X[]= {0,0,1,-1};
//int Y[]= {-1,1,0,0};
//int X[]= {0,0,1,1,1,-1,-1,-1};
//int Y[]= {-1,1,0,1,-1,0,1,-1};
int Set(int N,int pos){return N = N | (1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}
int reset(int N,int pos){return  N = N & ~(1<<pos);}
int dp[17][(1<<16)+10];
int grid[18][18],n;
int rec(int pos,int mask)
{
    if(pos>=n)
    return 0;
    if(dp[pos][mask]!=-1)
    return dp[pos][mask];
    int ret=0;
    for(int i=0;i<n;i++)
    {
//        if(i==pos)continue;
        if(check(mask,i)==0)
        ret= max(ret,grid[pos][i]+rec(pos+1,Set(mask,i)));
    }
    return dp[pos][mask]=ret;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            scanf("%d",&grid[i][j]);
        }
        memset(dp,-1,sizeof dp);
        int ans=rec(0,0);
        printf("Case %d: %d\n",cs,ans);

    }
}
