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
int lower_bd,upper_bd;
int arr[100010];
int serc(int low,int high,int key)
{
    if(low>high)
    {
        lower_bd=high;
        upper_bd=low;
        return -1;
    }
    int mid=(low+high)/2;
    if(arr[mid]==key)
    return mid;
    if(arr[mid]>key)
    {
        return serc(low,mid-1,key);
    }
    else
    return serc(mid+1,high,key);
}
int main()
{
    int t,n,m,u,v;
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++)
    {
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
        sort(arr,arr+n);
        printf("Case %d:\n",cs);
        for(int i=0;i<m;i++)
        {
            scanf("%d %d",&u,&v);
            int ans=serc(0,n-1,u);
            if(ans==-1)
            ans=upper_bd;
            int ans2=serc(0,n-1,v);
            if(ans2==-1)
            ans2=lower_bd;
            printf("%d\n",ans2-ans+1);
        }
    }

    return 0;
}


