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
int lef[1005],righ[1005],jump_lef[1005],jump_righ[1005];
int dp[1005][2],n;
int rec(int pos,int now)
{
    if(pos>=n)
        return 0;
    if(dp[pos][now]!=-1)
        return dp[pos][now];
    int ret1;
    if(now==0)
    {

        ret1= rec(pos+1,now) ;
        ret1= min(ret1,rec(pos+1,now^1)+jump_lef[pos]);
        ret1+=lef[pos];
    }
    else
    {

        ret1= rec(pos+1,now) ;
        ret1= min(ret1,rec(pos+1,now^1)+jump_righ[pos]);
        ret1+=righ[pos];
    }
    return dp[pos][now]=ret1;

}
int main()
{
    int t;
    scanf("%d",&t);
    for(int cs=1; cs<=t; cs++)
    {
        scanf("%d",&n);
        for(int i=0; i<n; i++)
            scanf("%d",&lef[i]);
        for(int i=0; i<n; i++)
            scanf("%d",&righ[i]);
        for(int i=0; i<n-1; i++)
            scanf("%d",&jump_lef[i]);
        for(int i=0; i<n-1; i++)
            scanf("%d",&jump_righ[i]);
            memset(dp,-1,sizeof dp);
        int ans= rec(0,0);
        ans= min(ans,rec(0,1));
        printf("Case %d: %d\n",cs,ans);

    }
    return 0;
}


