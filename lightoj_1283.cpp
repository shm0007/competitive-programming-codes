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
ll int dp[102][102][102];
ll int arr[150],n,m;
ll int rec(int pos,int left,int right)
{
    //cout<<pos<<endl;
    if(pos>n+1 )
    {
        return 0;
    }
    if(dp[pos][left][right]!=-1)
        return dp[pos][left][right];
    ll  int ret = 0;

    if(arr[pos]>=arr[left] &&arr[pos]<=arr[right])
    {
        ret= max(ret,rec(pos+1,pos,right) +1);
        ret= max(ret,rec(pos+1,left,pos)+1);
    }
    ret= max(ret,rec(pos+1,left,right));

//        ret= max(ret,rec(take,left,right));



    return dp[pos][left][right] = ret;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int cs=1; cs<=t; cs++)
    {
        scanf("%d",&n);
        for(int i=2; i<=n+1; i++)
        {
            scanf("%d",&arr[i]);
        }
        arr[0]=-1;
        arr[1]=100000000;
        memset(dp,-1,sizeof dp);
        printf("Case %d: %lld\n",cs,rec(2,0,1));


    }

    return 0;
}
