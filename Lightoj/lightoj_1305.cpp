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
    int x1,x2,x3,y1,y2,y3;
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++)
    {
        scanf("%d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3);
        int midx=(x1+x3);
        int midy=(y1+y3);
        int x4=midx-x2;
        int y4=midy-y2;

        int d1=x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2);
                int d2=x1*(y4-y3) + x4*(y3-y1)+ x3*(y1-y4);
//            printf("d1%d %d\n",d1,d2);
                    printf("Case %d: %d %d %d\n",cs,x4,y4,abs(d1));
    }
    return 0;
}


