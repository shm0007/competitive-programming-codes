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
ll int dp[65][65];
char arr[150];
ll int rec(int st,int end)
{
    if(st==end)
    return 1;
    if(st>end)
    return 0;
    if(dp[st][end]!=-1)
    return dp[st][end];
    if(arr[st]==arr[end])
    {
        return dp[st][end] = (1+ rec(st+1,end)+rec(st,end-1) );
    }
    return dp[st][end]= rec(st+1,end)+ rec(st,end-1)- rec(st+1,end-1);
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++)
    {
        scanf("%s",arr);
        memset(dp,-1,sizeof(dp));
        printf("Case %d: %lld\n",cs,rec(0,strlen(arr)-1));
    }
    return 0;
}


