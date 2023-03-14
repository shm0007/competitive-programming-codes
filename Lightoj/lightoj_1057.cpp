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
int Set(int N,int pos)
{
    return N = N | (1<<pos);
}
bool check(int N,int pos)
{
    return (bool)(N & (1<<pos));
}
int reset(int N,int pos)
{
    return  N = N & ~(1<<pos);
}

struct ST
{
    int x,y;
};
vector<ST>V;
int get(int i, int j)
{
    ST one = V[i];
    ST two = V[j];
return max(abs(one.x-two.x) ,abs(one.y-two.y) );
    //return min(abs(one.x-two.x) ,abs(one.y-two.y) ) +1 + max(abs(one.x-two.x) ,abs(one.y-two.y) ) -min(abs(one.x-two.x) ,abs(one.y-two.y) ) ;

}
int dp[ (1<< 16) +10][20],len;
int rec(int mask,int prev)
{
    if(dp[mask][prev]!=-1)
        return dp[mask][prev];
    if(__builtin_popcount(mask) ==len) return get(prev,0);
    int ret=1<<30;
    for(int i=1; i<len; i++)
    {
        if(check(mask,i)==0)
        {
            ret= min(ret, get(i,prev) +rec(Set(mask,i) , i));
        }
    }
    return dp[mask][prev] = ret;
}
int main()
{
    int t,n,m;
    char grid[50][50];
    scanf("%d",&t);
    ST temp;
    for(int cs=1; cs<=t; cs++)
    {
        scanf("%d %d",&n,&m);
        for(int i=0; i<n; i++)
        {
            scanf("%s",grid[i]);
            for(int j=0; j<m; j++)
                if(grid[i][j]=='x')
                {
                    temp.x=i;
                    temp.y=j;
                    V.pb(temp);
                }


        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
                if(grid[i][j]=='g')
                {
                    temp.x=i;
                    temp.y=j;
                    V.pb(temp);
                }
        }

        len = V.size();
        memset(dp,-1,sizeof dp);
        int ans= rec(Set(0,0),0);
        printf("Case %d: %d\n",cs,ans);
        V.clear();
    }

    return 0;
}


