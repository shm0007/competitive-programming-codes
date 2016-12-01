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
int arr[101000];
typedef struct{
int a;int b;

}ST;

ST tree[301000];
ST MIN(ST A,ST B)
{
    if(A.a<=B.a)
    return A;
    return B;
}
void create(int node, int st, int end)
{
    if(st==end)
    {
        tree[node].a=arr[st];
        tree[node].b=st+1;

        return;
    }
    int left=node*2;
    int right =left+1;
    int mid=(st+end)/2;
    create(left,st,mid);
    create(right,mid+1,end);
    if(tree[left].a<=tree[right].a)
   tree[node]=(tree[left]);
    else
    tree[node]=tree[right];
}
ST zero;
ST query(int node,int st, int end,int i,int j)
{
    if(i==st &&j==end)
    return tree[node];
    if(i>end || j<st)
    return zero;
    if(st>=i && end<=j)
    return (tree[node]);
    int left=node*2;
    int right =left+1;
    int mid=(st+end)/2;
    if(j<=mid)
    {
        return query(left, st, mid, i, j);
    }
    else if(i > mid)
    {
        return query(right, mid+1, end, i, j);
    }
    else return MIN(query(left, st, mid, i, mid) , query(right, mid+1, end, mid+1, j));
}
ll int get(int st,int en,int N)
{
    ST tm=query(1,1,N,st,en);
    ll int temp=(ll)tm.a*(ll)(en+1-st);
    if(tm.b-1>st)
    {   temp=max(temp,get(st,tm.b-1,N));

    }
    if(tm.b+1<en)
    temp=max(temp,get(tm.b+1,en,N));
    return temp;

}
int main()
{
    zero.a=0,zero.b=0;
    int t,n,q ;
         int u,v;;
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
        create(1,0,n-1);
        printf("Case %d: ",cs);
//        for(int i=1;i<=q;i++)
        {

//            scanf("%d %d",&u,&v);
//            ST tm=query(1,1,n,u,v);

           ll int ans= get(1,n,n);

            printf("%lld\n",ans);

        }
    }
return 0;
}

