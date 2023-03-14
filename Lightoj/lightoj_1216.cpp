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
    int t;
    double r1,r2,h,p;
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++)
    {
        scanf("%lf %lf %lf %lf",&r1,&r2,&h,&p);
        r1= r2 + ((r1-r2)*p)/h;
        printf("Case %d: %.10lf\n",cs, (p *(PI)*(r2*r2 + r1*r2 + r1*r1))/3.0 );
    }


    return 0;
}

