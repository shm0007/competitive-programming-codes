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
int main()
{
    int t,one[1500],two[1500],n;
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&one[i]);

        }
        for(int i=0;i<n;i++)
        {
            scanf("%d",&two[i]);

        }
        int ans=(two[0]-one[0]) -1;
        for(int i=1;i<n;i++)
        {
             ans^= ( (two[i]-one[i]) -1);

        }

        printf("Case %d: %s wins\n",cs,ans?"white":"black");
    }
    return 0;
}


