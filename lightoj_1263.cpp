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
int ct=0;
vector<int>grid[1010];
int money[1200];
int vis[1200];
ll int dfs(int u)
{
    if(vis[u]==1)
        return 0;
    vis[u]=1;
    int sz=grid[u].size();
    ll int ans=money[u];
    ct++;
    for(int i=0; i<sz; i++)
    {
        ans+=dfs(grid[u][i]);
    }
    return ans;
}
int main()
{
    int t,n,m,u,v;
    scanf("%d",&t);
    for(int cs=1; cs<=t; cs++)
    {
        memset(vis,0,sizeof(vis));
        scanf("%d %d",&n,&m);
        int total=0;
        for(int i=0; i<n; i++)
        {
            scanf("%d",&money[i]);
            total+=money[i];
        }
        for(int i=0; i<m; i++)
        {
            scanf("%d %d",&u,&v);
            grid[u-1].pb(v-1);
            grid[v-1].pb(u-1);

        }
        int ans;
        int flag=0;
        for(int i=0; i<n; i++)
        {
            if(vis[i]==0)
            {
                ct=0;
                ans=dfs(i);
//                printf("ans->%d %d %d %d\n",ans,i,ct,total/n);
                if(ans%ct!=0)
                {
                    flag=1;
                    break;
                }
                if(ans/ct!=total/n)
                {
                    flag=1;
                    break;
                }

            }
        }
        if(flag==0)
            printf("Case %d: Yes\n",cs);
        else
            printf("Case %d: No\n",cs);
        for(int i=0; i<n; i++)
            grid[i].clear();
    }
    return 0;
}


