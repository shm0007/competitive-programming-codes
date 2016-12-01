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
    int t,n,c;
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++)
    {
        scanf("%d %d",&n,&c);
        int T;
        if(n)
        {T=c/n;
        if(c%n!=0)
        T++;
        T/=2;
        }
        else
        T=c-1;
        printf("Case %d: %d\n",cs,T);
    }

    return 0;
}

