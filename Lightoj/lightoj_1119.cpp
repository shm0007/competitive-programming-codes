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
int dp[ (1<<16) +10];
int price[20][20];
int rec(int mask,int n)
{
    if((1<<n) -1 == mask)
    return 0;
    if(dp[mask]!=-1)
    return dp[mask];
    int ret=1<<29;
    for(int i=0;i<n;i++)
    {
        if(check(mask,i)==0)
        {
            int temp=price[i][i];
            for(int j=0;j<n;j++)
            {
                if(i!=j && check(mask,j)!=0)
                {
                    temp+=price[i][j];
                }
            }
            mask=Set(mask,i);
            ret=min(ret,temp+rec(mask,n));
            mask=reset(mask,i);
        }
    }
    return dp[mask]=ret;
}
int main()
{
    int t,n;
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            scanf("%d",&price[i][j]);
        memset(dp,-1,sizeof(dp));
        //printf("asadf");
        printf("Case %d: %d\n",cs,rec(0,n));

    }

        return 0;
}

