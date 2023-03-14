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
int arr[1000005];
int main()
{
    int t,n,temp;
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++)
    {

        memset(arr,0,sizeof arr);
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&temp);
            arr[temp]++;
        }
        if(n==1)
        {
                    printf("Case %d: %s\n",cs,arr[0]==1? "yes":"no");
                    continue;

        }
        int flag=0;
        for(int i=0;i<(n/2);i++)
        {
            if(arr[i]+ arr[n-(i+1)]!=2)
            {
                flag=1;
                break;
            }
        }

        printf("Case %d: %s\n",cs,flag==0? "yes":"no");
    }

    return 0;
}


