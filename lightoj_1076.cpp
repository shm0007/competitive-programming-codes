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
int n,m;
int arr[1010];
int check(int key)
{
    int sum=0,counter=1;
    for(int i=0;i<n;i++)
    {
        if(sum+arr[i]<=key)
        sum+=arr[i];
        else
        sum=arr[i],counter++;
    }
    return counter;
}
int ans=1<<29;
void serc(int low,int high)
{
    if(low>high)
    return ;
    int mid=(low+high)/2;
    if(check(mid)<=m)
    {
//        printf("%d %d %d\n",mid,low,high);
        ans=min(ans,mid);
        serc(low,mid-1);
        return ;
    }
    serc(mid+1,high);
    return ;
}
int get_max(int key)
{
    int sum=0,counter=0;
    for(int i=0;i<n;i++)
    {
        if(sum+arr[i]<=key)
        sum+=arr[i];
        else
        {
            counter=max(counter,sum);
        sum=arr[i];

        }
    }
//    printf("%d %d\n",counter,key);
    return max(sum,counter);
}
int main()
{

    int t;
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++)
    {
        int sum=0;
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        sum+=arr[i];

        }
        serc(0,sum);
        sum=get_max(ans);
        printf("Case %d: %d\n",cs,sum);
        ans=1<<29;
    }

    return 0;
}


