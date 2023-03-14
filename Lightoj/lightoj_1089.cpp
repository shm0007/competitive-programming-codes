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
int tree[400900];
int N;
void update(int indx, int val)
{
    while(indx <= N)
    {
        tree[indx] += val;
        indx += (indx & -indx);
    }
    return ;
}
 int query(int indx)
{
    int sum = 0;
    while(indx > 0)
    {
        sum += tree[indx];
        indx -= (indx & -indx);
    }
    return sum;
}
int inp[50010][2],qur[100010];
int main()
{
    int t,q,u,l,r,val,n;
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++)
    {

        memset(tree, 0, sizeof(tree));
        set<int>S;
        scanf("%d %d",&n,&q);
        for(int i=0;i<n;i++)
        {
            scanf("%d %d",&inp[i][0],&inp[i][1]);
            S.insert(inp[i][0]);
            S.insert(inp[i][1]);
        }
        for(int i=0;i<q;i++)
        {
            scanf("%d",&qur[i]);
                S.insert(qur[i]);
        }
        int in=1;
        map<int,int>mp;
        for(set<int> :: iterator  it=S.begin();it!=S.end();it++)
        {
            mp[*it]=in++;
        }
        printf("Case %d:\n",cs);
        N=in;
        for(int i=0;i<n;i++)
        {
            update(mp[inp[i][0]],1);
            update(mp[inp[i][1]]+1,-1);
        }
        for(int i=0;i<q;i++)
        {
                printf("%d\n",query(mp[qur[i]]));
        }


    }

    return 0;
}
