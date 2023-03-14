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
  ll  int t,l,p;
    scanf("%lld",&t);
    for(int cs=1;cs<=t;cs++)
        {
            scanf("%lld %lld",&l,&p);
            printf("Case %d:",cs);
          ll  int n=l-p;
//            if(n<=p)
//            printf(" impossible\n");
//            else
            {
                vector<ll int>V;
                for(ll int i=1;i*i<=n;i++)
                {
                    if(n%i==0)
                    {
                        if(i>p)
                        V.pb(i);
                        if(n/i>p && i!=n/i)
                        V.pb(n/i);
                    }
                }
                sort(V.begin(),V.end());
                if(V.size()>0)
                for(int i=0;i<V.size();i++)
                printf(" %lld",V[i]);
                else
                printf(" impossible");
                puts("");
            }

        }
    return 0;
}
