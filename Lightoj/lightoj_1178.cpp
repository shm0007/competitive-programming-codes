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
int main()
{
    int t;
    double a,b,c,d;
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++)
    {
        scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
        if(a<c)swap(a,c);
        double s=((a-c)+ b+d)/2.0;
        double area= sqrt(s*(s-a+c)*(s-b)*(s-d));
        double h =area*2.0/(a-c);
        printf("Case %d: %0.10lf\n",cs,0.5*(a+c)*h);
    }
    return 0;
}

