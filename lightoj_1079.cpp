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
typedef struct{
int money;
double prob;
}ST;
ST arr[110];
int dp[105][10100];
int main()
{
    int t;
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++)
    {
        scanf("%lf %d",&P,&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d %lf",&arr[i].money,&arr[i].prob);
        }
//        mp[0.0]=in++;
        printf("Case %d: %d\n",cs,rec(0,0));
    }

    return 0;
}

