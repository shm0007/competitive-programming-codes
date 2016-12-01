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
int number[1000100];

int main()
{
    int t,mod,n;
    char name[150];
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++)
    {
        scanf("%d %s",&n,name);

            if(!strcmp("Alice",name))
            {
                 if(n%3==1)
                {
                                 printf("Case %d: Bob\n",cs);
                }
                else
                printf("Case %d: Alice\n",cs);
            }

            else
            {
                if(n%3==0)
                {
                 printf("Case %d: Alice\n",cs);
               }
                else
                printf("Case %d: Bob\n",cs);
;            }
    }
    return 0;
}


