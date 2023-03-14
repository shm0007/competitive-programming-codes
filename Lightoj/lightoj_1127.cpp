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



ll int a[35];

void generate(ll sum, int st, int en, vector< ll int > &v)
{

    if(st == en)
    {
        v.push_back(sum);
        return;
    }

    for(int i = 0; i < 2; i++) generate(sum + a[st] * i, st + 1, en, v);

}
int serc(int low, int high,int key,vector<ll int> &V)
{
    if(low>high)
        return high;
    int mid=(low+high)/2;
    if(V[mid]==key)
        return mid;
    if(V[mid]>key)
    {
        return serc(low,mid-1,key,V);
    }
    else
    {
        return serc(mid+1,high,key,V);
    }

}
ll int cum[(1<<16)+10];
int main()
{

    int t,n;
    ll int coin;
    scanf("%d",&t);
    for(int cs=1; cs<=t; cs++)
    {
        scanf("%d %lld",&n,&coin);
        for(int i=0; i<n; i++)
            scanf("%lld",&a[i]);
        vector< ll int > Lt, Rt;
        int md;

        md = n >> 1;
        generate(0, 0, md, Lt);
        generate(0, md, n, Rt);
        sort(Lt.begin(),Lt.end());
        sort(Rt.begin(),Rt.end());
//        for(int i=0; i<Lt.size(); i++)
//            printf("%lld\n",Lt[i]);
//        for(int i=0; i<Rt.size(); i++)
//            printf("rt%lld\n",Rt[i]);

        int len_left=Lt.size();
        int len_right=Rt.size();
        ll int ans=0;
        int fnd;
        for(int i=0; i<len_left; i++)
        {
            fnd=upper_bound (Rt.begin(),Rt.end(),(ll)coin-Lt[i])-Rt.begin();

//            fnd=serc(0,identical.size(),coin-Lt[i],identical);
//            printf("%lld %lld %lld\n",Lt[i],identical[fnd],cum[fnd]);
//            if(fnd !=-1)
            {

                ans+= (ll)(fnd);

            }
        }

        printf("Case %d: %lld\n",cs,ans);
    }
    return 0;
}
