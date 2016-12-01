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
    int t,one,two,n,m;
    ll int arr[1500];
    scanf("%d",&t);
    for(int cs=1; cs<=t; cs++)
    {
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++)
        {
            ll int temp;
            one=0;
            for(int j=0;j<m;j++)
            {
                scanf("%lld",&temp);
                one+=temp;
            }
            arr[i]=one;

        }
        int ans=arr[0];
        for(int i=1; i<n; i++)
        {
            ans^=((arr[i]));

        }


        printf("Case %d: %s\n",cs,ans?"Alice":"Bob");
    }
    return 0;
}




