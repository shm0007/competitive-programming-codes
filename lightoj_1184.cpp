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
int V,graph[110][110];
int rGraph[110][110];
bool bfs( int s, int t, int parent[]);
int fordFulkerson( int s, int t);
typedef struct{
int h,age,sex;
}ST;
int main()
{
    int st,end,u,v,w,cs=1,t,m,n;
    ST men[150];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        V=n+m+2;
        end=m+n+1;
        for(int i=0;i<n;i++)
        {
            graph[0][i+1]++;
            scanf("%d %d %d",&men[i].h,&men[i].age,&men[i].sex);

        }
        for(int i=0;i<m;i++)
        {
                scanf("%d %d %d",&u,&v,&w);
                for(int j=0;j<n;j++)
            {
                if(w==men[j].sex && abs(men[j].h-u)<=12 && abs(men[j].age-v)<=5)
                {
                    graph[j+1][i+n+1]++;

                }
            }
                    graph[i+n+1][end]++;

        }

    int FLOW=fordFulkerson(0,end);

    printf("Case %d: %d\n",cs++,FLOW);
    memset(rGraph,0,sizeof(rGraph));
    memset(graph,0,sizeof(graph));

    }

    return 0;
}

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
