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

int X[]= {0,0,1,-1};
int Y[]= {-1,1,0,0};
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

bool FindMatch(int i, const VVI &w, VI &mr, VI &mc, VI &seen)
{
    for (int j = 0; j < w[i].size(); j++)
    {
        if (w[i][j] && !seen[j])
        {
            seen[j] = true;
            if (mc[j] < 0 || FindMatch(mc[j], w, mr, mc, seen))
            {
                mr[i] = j;
                mc[j] = i;
                return true;
            }
        }
    }
    return false;
}

int BipartiteMatching(const VVI &w)
{
    VI mr = VI(w.size(), -1);
    VI mc = VI(w[0].size(), -1);

    int ct = 0;
    for (int i = 0; i < w.size(); i++)
    {
        VI seen(w[0].size());
        if (FindMatch(i, w, mr, mc, seen)) ct++;
    }
    return ct;
}
vector<int>voy[260];
vector<int>vut[350];
int n,mx=0;
char arr[100][100];
map< pair<int,int> ,int > GH;
map< pair<int,int> ,int > HM;
map<int, pair<int,int> > REVGH;
map< int,pair<int,int> > REVHM;

void ghost(int r,int c)
{
//    printf("%d %d",r,c);
    int ct=0;
    int pos_ghost= GH[make_pair(r,c)];
    int pos_hum;
    int dist[30][30];
    memset(dist,-1,sizeof(dist));
    queue<int>Q;
    Q.push(r);
    Q.push(c);
    dist[r][c]=0;
    while(!Q.empty())
    {
        int tx=Q.front();
        Q.pop();
        int ty=Q.front();
        Q.pop();
        for(int i=0; i<4; i++)
        {
            int nx=tx+X[i];
            int ny=ty+Y[i];
            if(nx>=0 && nx<n && ny>=0 && ny<n && arr[nx][ny]!='#' && dist[nx][ny]==-1)
            {
                Q.push(nx);
                Q.push(ny);
                dist[nx][ny]=dist[tx][ty]+1;
                if(arr[nx][ny]=='H')
                {
                    mx=max(mx,dist[nx][ny]);
//                    printf("as%d %d\n",nx,ny);

                    pair<int,int>pr;
                    pr=make_pair(nx,ny);
                    vut[pos_ghost].push_back(HM[pr]);
                    voy[pos_ghost].push_back(dist[nx][ny]);
//                    printf("dist%d\n",dist[nx][ny]);
                }
            }
        }

    }
    return ;
}
int main()
{
    int  m,u,v,t;
    scanf("%d", &t);
    for(int cs=1; cs<=t; cs++)
    {
        bool found=false;
        REVGH.clear();
        REVHM.clear();
        GH.clear();
        HM.clear();
        scanf("%d", &n);
        pair<int,int>prr;
        int M=0;
        int N=0;
        for(int i=0; i<n; i++)
        {
            scanf("%s",arr[i]);
            for(int j=0; j<n; j++)
            {
                if(arr[i][j]=='G')
                {
                    prr= make_pair(i,j);
                    if(GH.find(prr)==GH.end())
                    {
                        GH[prr]=M++;
                        REVGH[M-1]=prr;
                    }
                }
                if(arr[i][j]=='H')
                {
                    prr= make_pair(i,j);
                    if(HM.find(prr)==HM.end())
                    {
                        HM[prr]=N++;
                        REVHM[N-1]=prr;
                    }
                }
            }
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {

                if(arr[i][j]=='G')
                    ghost(i,j);
            }
        }
        for(int total=1; total<=mx; total++)
        {
            VVI w(M,VI(N,0));
            for(int i=0; i<M; i++)
            {
                pair<int,int>pg;
                pair<int,int>pp;
                pg=REVGH[i];

                for(int j=0; j<voy[i].size(); j++)
                {
                    if(voy[i][j]<=total)
                        {
                                        w[i][vut[i][j]]=1;

                                            pp=REVHM[vut[i][j]];
//                printf(" %d (%d %d ) --- %d (%d %d )  %d\n",GH[pg],pg.first,pg.second,HM[pp],pp.first,pp.second,voy[i][j]);

                        }

//                                    pp=REVHM[vut[i][j]];
//                printf(" %d (%d %d ) --- %d (%d %d )  %d\n",GH[pg],pg.first,pg.second,HM[pp],pp.first,pp.second,voy[i][j]);

                }
            }
            int match=BipartiteMatching(w);
            if(match==N)
            {
                printf("Case %d: %d\n",cs,(total-1)*2 +4);
                found=true;
                break;
            }
        }
        if(!found)
        printf("Case %d: Vuter Dol Kupokat\n", cs);
        mx=0;
        for(int i=0;i<=max(M,N);i++)
        {
            voy[i].clear();
            vut[i].clear();
        }
    }
    return 0;
}
