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
double serc(double low,double high, double x,double y)
{
    if(high-low<=1e-8)
        return high;
    double mid=(low+high)/2.0;
    if((mid+(mid*x)/y)-200<=1e-8 || 200-(mid+(mid*x)/y)<=1e-8)
        return mid;
       else
        if((mid+(mid*y)/x)<=200)
       return serc(mid,high,x,y);
    return serc(low,mid,x,y);
}
int main()
{
    double x,y,c;
    int t;
    scanf("%d",&t);
    for(int cs=1; cs<=t; cs++)
    {
        scanf("%lf %lf",&x,&y);
        double ans=serc(0.0,200.0,x,y);
        printf("Case %d: %.10lf\n",cs,ans);
    }


    return 0;
}



