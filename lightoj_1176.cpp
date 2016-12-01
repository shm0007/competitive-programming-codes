///////////////////
//  Shamim Ehsan //
//  SUST CSE 12  //
//  2012331035   //
///////////////////
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
using namespace std;
//int X[]= {0,0,1,-1};
//int Y[]= {-1,1,0,0};
//int X[]= {0,0,1,1,1,-1,-1,-1};
//int Y[]= {-1,1,0,1,-1,0,1,-1};
int V,graph[110][110];
int rGraph[110][110];
bool bfs( int s, int t, int parent[])
{
    bool visited[110];
    memset(visited, 0, sizeof(visited));
    queue <int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v=0; v<V; v++)
        {
            if (visited[v]==false && rGraph[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return (visited[t] == true);
}

int fordFulkerson( int s, int t)
{
    int u, v;

    for (u = 0; u < V; u++)
        for (v = 0; v < V; v++)
             rGraph[u][v] = graph[u][v];

    int parent[V];
    int max_flow = 0;
    while (bfs( s, t, parent))
    {
        int path_flow = INT_MAX;
        for (v=t; v!=s; v=parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }

        for (v=t; v != s; v=parent[v])
        {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }
        max_flow += path_flow;
    }
    return max_flow;
}

int main()
{
    int st,end,u,v,w,cs=1,t,m,n;
    char st1[150],st2[150];
    scanf("%d",&t);
    map<string,int>mp;
    mp["XXL"]=6;
    mp["XL"]=1;
    mp["L"]=2;
    mp["M"]=3;
    mp["S"]=4;
    mp["XS"]=5;

    for(int cs=1;cs<=t;cs++)
    {
        scanf("%d %d",&n,&m);
        n*=6;
        printf("Case %d: ",cs);
        end=m+n+1;
        V=end+1;
             for(int i=1;i<=6;i++)
        {
            graph[0][i]+=(n/6);
            graph[i][0]+=(n/6);
        }
        for(int i=0;i<m;i++)
        {
            scanf("%s %s",st1,st2);
           u=mp[st1];
        v=mp[st2];
//        printf("%d %d %d\n",u,v,i+7);
            graph[u][i+7]++;
//            graph[i+7][u]++;
            graph[v][i+7]++;
//            graph[i+7][v]++;
//            graph[end][i+7]++;
            graph[i+7][end]++;

        }
    int FLOW=fordFulkerson(0,end);
    if(FLOW!=m)
    printf("NO\n");
    else
    printf("YES\n");
    memset(rGraph,0,sizeof(rGraph));
    memset(graph,0,sizeof(graph));

    }

    return 0;
}
