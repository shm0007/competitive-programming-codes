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
double dp[510][510];
void prec(void)
{
    for(int i=0;i<=500;i++)
    dp[i][0]=0;
    for(int i=1;i<=500;i++)
    {
//        if(i%2==1)
        dp[0][i]=1;
//        else
//        dp[0][i]=0;
    }
    for(int i=1;i<=500;i++)
        for(int j=1;j<=500;j++)
        {
            dp[i][j]=(dp[i-1][j-1]*((double)i/(double)(i+j)));
            if(j-2>=0)
            dp[i][j]+=(dp[i][j-2]*((double)j/(double)(i+j)) );

        }
   return ;
}
int main()
{
    int t,m,n;
    scanf("%d",&t);
    prec();
    for(int cs=1; cs<=t; cs++)
    {
        scanf("%d %d",&n,&m);
        printf("Case %d: %.10lf\n",cs,dp[n][m]);
    }

    return 0;
}

