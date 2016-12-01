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


vector< ll int > Lt, Rt;
ll int a[20];

void generate(ll sum, int st, int en, vector< ll int > &v)
{

    if(st == en)
    {
        v.push_back(sum);
        return;
    }

    for(int i = 0; i < 3; i++) generate(sum + a[st] * i, st + 1, en, v);

}
int serc(int low, int high,int key)
{
    if(low>high)
        return -1;
    int mid=(low+high)/2;
    if(Lt[mid]==key)
        return mid;
    if(Lt[mid]>key)
    {
        return serc(low,mid-1,key);
    }
    else
    {
        return serc(mid+1,high,key);
    }

}
int main()
{

    int t,n;
    ll int coin;
    scanf("%d",&t);
    for(int cs=1; cs<=t; cs++)
    {
        scanf("%d %lld",&n,&coin);
        for(int i=0;i<n;i++)
        scanf("%lld",&a[i]);
        Lt.clear();
        Rt.clear();
        int md;
        md = n >> 1;
        generate(0, 0, md, Lt);
        generate(0, md, n, Rt);
        sort(Lt.begin(),Lt.end());
        int len=Rt.size();
        bool flag=false;
        for(int i=0; i<len; i++)
        {
            if(serc(0,Lt.size(),coin-Rt[i]) !=-1)
            {
                flag=true;
                printf("Case %d: Yes\n",cs);
                break;

            }
        }
        if(!flag)
            printf("Case %d: No\n",cs);
    }
    return 0;
}
