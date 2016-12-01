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
int dist[210];
struct edge
{
     int u;
    int cost;
    int gas;
    edge(int a,int b,int c)
    {
        u=a;
        cost=b;
        gas=c;
    }
    bool operator <(const edge &p)const
    {
        return cost>p.cost;
    }
};
int n,m;
vector<int>grid[210];
vector<int>cost[210];
int fuel[1500];
double dijkstra(int start,int end,int N,int mx_fuel)
{

    for(int i=0; i<=205; i++)
        dist[i]=1<<29;
    priority_queue<edge>Q;
    Q.push(edge(start,0,min(mx_fuel,fuel[start])));
    dist[start]=0;
    while(!Q.empty())
    {
        edge top=Q.top();
        Q.pop();
        int u=top.u;
        int current_gas=top.gas;
        if(u==end)
            return dist[end];
        for(int i=0; i<(int)grid[u].size(); i++)
        {
            int v=grid[u][i];
            if(dist[u]+cost[u][i]<dist[v] && current_gas>=dist[u]+cost[u][i] )
            {
                dist[v]=dist[u]+cost[u][i];

                Q.push(edge(v,dist[v], min(mx_fuel,current_gas+ fuel[v]-dist[u]+cost[u][i])));
            printf("%d %d %d\n",v,dist[v],min(mx_fuel,current_gas+ fuel[v]-dist[u]+cost[u][i]));

            }
        }
    }
    return -1;
}
int main()
{
//    freopen("in.txt","w",stdout);
    int t,n,m,u,v,cst;

    scanf("%d",&t);
    for(int cs=1;cs<=t;cs++)
    {
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++)
        scanf("%d",&fuel[i]);
        for(int i=0;i<m;i++)
        {
            scanf("%d %d %d",&u,&v,&cst);
            grid[u].pb(v);
            grid[v].pb(u);
            cost[u].pb(cst);
            cost[v].pb(cst);

        }
        int q;
        scanf("%d",&q);
        for(int i=0;i<q;i++)
        {
            scanf("%d %d %d",&cst,&u,&v);
            cout<<dijkstra(u,v,n,cst)<<endl;
        }
        for(int i=0; i<205; i++)
        {
            grid[i].clear();
            cost[i].clear();
        }
    }

    return 0;
}


