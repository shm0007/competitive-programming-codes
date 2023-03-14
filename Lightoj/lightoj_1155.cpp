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

const int INF = 2000000000;
struct Edge
{
    int from, to, cap, flow, index;
    Edge(int from, int to, int cap, int flow, int index) :
        from(from), to(to), cap(cap), flow(flow), index(index) {}
};

struct Dinic
{
    int N;
    vector<vector<Edge> > G;
    vector<Edge *> dad;
    vector<int> Q;

    Dinic(int N) : N(N), G(N), dad(N), Q(N) {}

    void AddEdge(int from, int to, int cap)
    {
        G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
        if (from == to) G[from].back().index++;
        G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
    }

    long long BlockingFlow(int s, int t)
    {
        fill(dad.begin(), dad.end(), (Edge *) NULL);
        dad[s] = &G[0][0] - 1;

        int head = 0, tail = 0;
        Q[tail++] = s;
        while (head < tail)
        {
            int x = Q[head++];
            for (int i = 0; i < G[x].size(); i++)
            {
                Edge &e = G[x][i];
                if (!dad[e.to] && e.cap - e.flow > 0)
                {
                    dad[e.to] = &G[x][i];
                    Q[tail++] = e.to;
                }
            }
        }
        if (!dad[t]) return 0;

        long long totflow = 0;
        for (int i = 0; i < G[t].size(); i++)
        {
            Edge *start = &G[G[t][i].to][G[t][i].index];
            int amt = INF;
            for (Edge *e = start; amt && e != dad[s]; e = dad[e->from])
            {
                if (!e)
                {
                    amt = 0;
                    break;
                }
                amt = min(amt, e->cap - e->flow);
            }
            if (amt == 0) continue;
            for (Edge *e = start; amt && e != dad[s]; e = dad[e->from])
            {
                e->flow += amt;
                G[e->to][e->index].flow -= amt;
            }
            totflow += amt;
        }
        return totflow;
    }

    long long GetMaxFlow(int s, int t)
    {
        long long totflow = 0;
        while (long long flow = BlockingFlow(s, t))
            totflow += flow;
        return totflow;
    }
};
int main()
{
    int t,n,m;
    scanf("%d",&t);

    for(int cs=1;cs<=t;cs++)
    {
        scanf("%d",&n);
        Dinic G(n+n+3);
        int u,v,w,temp;
        for(int i=0; i<n; i++)
        {
            scanf("%d",&temp);
            G.AddEdge(i , n+i,temp);
//            G.AddEdge(n+i,i,temp);
//            printf("%d %d\n",i,n+i);//,u-1,v+n-2);

        }
        scanf("%d",&m);
        for(int i=0; i<m; i++)
        {
            scanf("%d %d %d",&u,&v,&w);
                G.AddEdge(u+n-1,v-1,w);
//                G.AddEdge(v+n-1,u-1,w);
//                printf("%d %d %d %d\n",u,v,u+n-1,v-1);
//                printf("%d %d %d %d\n",u,v,u-1,v+n-1);



        }
        int b,d;
        int st=n+n+1;
        int en=st+1;
        scanf("%d %d",&b,&d);
        for(int i=0;i<b;i++)
        {
            scanf("%d",&u);
            G.AddEdge(st,u-1,10000000);
//            G.AddEdge(u-1,st,10000000);
//            printf("%d %d\n",st,u-1);
        }
        for(int i=0;i<d;i++)
        {
            scanf("%d",&u);
            G.AddEdge(u+n-1,en,10000000);
//            G.AddEdge(en,u+n-1,10000000);

//            printf("%d %d",u+n-1,en);
        }
        printf("Case %d: %d\n",cs,G.GetMaxFlow(st,en));


    }
return 0;
}

