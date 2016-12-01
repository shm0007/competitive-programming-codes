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

typedef struct
{
    int st,end,w;

} node;
node temp;
vector<node>graph;
int dist[2500];
int par[1500];
bool BellmanFord(int source,int V,int E)
{
    for(int i=0; i<=V; i++)
        par[i]=i;

    for (int i = 0; i < V; i++)
        dist[i]   = 1<<29;
    dist[source] = 0;
    for (int i = 0; i < V-1; i++)
    {
        for (int j = 0; j < E; j++)
        {
            int u = graph[j].st;
            int v = graph[j].end;
            int weight = graph[j].w;
            if (dist[u] + weight < dist[v] && dist[u]!=(1<<29))
            {
//                if(v==3)
//                printf("as %d %d %d %d\n",dist[v], dist[u] , weight,u);

                dist[v] = dist[u] + weight;
                par[v]=u;
            }
        }
    }

    // Step 3: check for negative-weight cycles.  The above step guarantees
    // shortest distances if graph doesn't contain negative weight cycle.
    // If we get a shorter path, then there is a cycle.
    int flag=0;
    for (int i = 0; i < E; i++)
    {
        int u = graph[i].st;
        int v = graph[i].end;
        int weight = graph[i].w;
         if (dist[u] + weight < dist[v] && dist[u]!=(1<<29))
           {
//            if(v==3)
//                printf("bs %d %d\n",dist[v], dist[u] + weight);

//                printf("Graph contains negative weight cycle");
            flag=1;
            break;
        }
    }
    if(flag)
        return false;
    else
        return true;
}
//void print(int en)
//{
//    if(en==1)
//    {
//        printf("1\n")
//    }
//}
int main()
{
    int V,E;
    int t,cs=1;;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&V);
        int cost[1500];
        for(int i=0; i<V; i++)
            scanf("%d",&cost[i]);
        scanf("%d",&E);
        for(int i=0; i<E; i++)
        {
            int u,v;
            scanf("%d %d",&u,&v);
            u--;
            v--;
            temp.st=u;
            temp.end=v;
            temp.w=(cost[v]-cost[u]) *(cost[v]-cost[u]) *(cost[v]-cost[u]);
              graph.pb(temp);
//            temp.st=v;
//            temp.end=u;
//            temp.w=(cost[u]-cost[v]) *(cost[u]-cost[v]) *(cost[u]-cost[v]);
//            graph.pb(temp);

        }
//        E*=2;
        int q;
        printf("Case %d:\n",cs++);
        scanf("%d",&q);
        bool an=BellmanFord(0,V,E);

        while(q--)
        {
            int EN;
            scanf("%d",&EN);
//            if(!an)
//            {
//                puts("?");
//            }
//            else
            {
                if(dist[EN-1]>=3 && dist[EN-1]!=(1<<29))
                printf("%d\n",dist[EN-1]);
                else
                puts("?");
            }
        }

        graph.clear();
    }

    return 0;
}
