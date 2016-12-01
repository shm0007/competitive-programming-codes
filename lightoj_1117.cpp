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
int Set(int N,int pos){return N = N | (1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}
int reset(int N,int pos){return  N = N & ~(1<<pos);}
//int mask[1<<20];
ll int arr[20];
ll int get(int n,ll int num)
{
    ll int ans=0;

    for(int i=1;i< (1<<n);i++)
    {
        ll int lcm=1;
        for(int j=0;j<n;j++)
        {
            if(check(i,j))
            {
                lcm=(lcm*arr[j])/__gcd(lcm,arr[j]);
            }
        }
//        cout<<__builtin_popcount(i)<<" ";
//        printf("%lld %lld %lld\n",lcm,num,num/lcm);

//        mask[i]=num/lcm;
//        if(__builtin_popcount(i)%2==1)
//        ans+=mask[i];
//        else
//        ans-=mask[i];
        if(__builtin_popcount(i)%2==1)
        ans+=num/lcm;
        else
        ans-=num/lcm;


    }
return ans;
}
int main()
{
    int t,n;
    ll int num;
    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++)
    {
        scanf("%lld %d",&num,&n);
        for(int i=0;i<n;i++)
        scanf("%lld",&arr[i]);
        printf("Case %d: %lld\n",cs,num-get(n,num));
//        for(int i=1;i<n;i++)
    }

    return 0;
}

