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
//#define int long long
using namespace std;
//int X[]= {0,0,1,-1};
//int Y[]= {-1,1,0,0};
//int X[]= {0,0,1,1,1,-1,-1,-1};
//int Y[]= {-1,1,0,1,-1,0,1,-1};
#define INF 10e20
int dist[5010];
struct edge
{
     int u;
    int cost;

    edge(int a,int b)
    {
        u=a;
        cost=b;
    }
    bool operator <(const edge &p)const
    {
        return cost>p.cost;
    }
};
vector<int>grid[5100];
vector<int>cost[5010];
int dist2[5010];
int dijkstra(int N)
{

    for(int i=0; i<=N; i++)
        {
            dist[i]=1<<29;
        dist2[i]=1<<29;

        }
    priority_queue<edge>Q;
    Q.push(edge(1,0));
    dist[1]=0;
    while(!Q.empty())
    {
        edge top=Q.top();
        Q.pop();
        int u=top.u;

        for(int i=0; i<(int)grid[u].size(); i++)
        {
            int v=grid[u][i];
            if(dist[u]+cost[u][i]<dist[v])
            {
                dist2[v]=dist[v];
                dist[v]=dist[u]+cost[u][i];
                Q.push(edge(v,dist2[v]));
            }

            else if(dist[u]+cost[u][i]>dist[v] && dist[u]+cost[u][i]<dist2[v])
            {
                dist2[v]=dist[u]+cost[u][i];
            Q.push(edge(v,dist2[v]));
            }
            else if(dist2[u]+cost[u][i]>dist[v] && dist2[u]+cost[u][i]<dist2[v])
            {
                dist2[v]=dist2[u]+cost[u][i];
            Q.push(edge(v,dist2[v]));
            }



        }
    }
    return dist2[N];
}
int main()
{
//    freopen("in.txt","w",stdout);
    int t,n,m,u,v,cst;

    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++)
    {
        scanf("%d %d",&n,&m);
        for(int i=0;i<m;i++)
        {
            scanf("%d %d %d",&u,&v,&cst);
            grid[u].pb(v);
            grid[v].pb(u);
            cost[u].pb(cst);
            cost[v].pb(cst);

        }
        printf("Case %d: %d\n",cs,dijkstra(n));
        for(int i=0; i<=n; i++)
        {
            grid[i].clear();
            cost[i].clear();
        }
    }

    return 0;
}



