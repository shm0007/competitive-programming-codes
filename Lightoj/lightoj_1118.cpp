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
    scanf("%d",&t);
    double x1,x2,y1,y2,r1,r2,c,theta1,theta2,ans;
    for(int cs=1; cs<=t; cs++)
    {
        scanf("%lf %lf %lf %lf %lf %lf",&x1,&y1,&r1,&x2,&y2,&r2);

        c= sqrt (((x1-x2)*(x1-x2)) + ((y1-y2)*(y1-y2)));
        if((r1-r2)*(r1-r2) < (x1-x2)*(x1-x2) +(y1-y2)*(y1-y2) && (x1-x2)*(x1-x2) +(y1-y2)*(y1-y2) < (r1+r2)*(r1+r2))
        {
            theta1= acos( ((r1*r1) + (c*c) - (r2*r2) )/(2.0 *r1*c));
            theta2= acos(((r2*r2) + (c*c) - (r1*r1) )/(2.0 *r2*c));
            theta1*=2.0;
            theta2*=2.0;
            ans = 0.5* theta1 * r1*r1;
            ans += (0.5* theta2 * r2*r2);
            ans -=( 0.5* r1* r1*sin(theta1));
            ans -=( 0.5* r2*r2* sin(theta2));


        }
        else if(c<=max(r1,r2))
        {

            ans=(PI)* min(r2,r1)* min(r1,r2);
        }
        else
            ans=0.0;
        printf("Case %d: %.10lf\n",cs,ans);

    }
    return 0;
}


