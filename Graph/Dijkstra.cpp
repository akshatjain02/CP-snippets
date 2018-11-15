#include <bits/stdc++.h>
 
#define ll          long long
#define pb          push_back
#define mp          make_pair
#define pii         pair<int,int>
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define lol         1000000007
#define endl        '\n'
#define rep(i,a,b)  for(int i=a;i<b;i++)
#define F           first
#define S           second
#define SIZE        1000005
using namespace std;

void MOD(ll &x)
{
    if (x >= lol) x -= lol;
    if (x < 0) x += lol;
}



vector<pair<ll,ll>> arr[SIZE];
ll dist[SIZE];
int vis[SIZE];
int n, m;
int par[SIZE];
// vi tree[SIZE];          // Dijkstra Tree


void dijkstra(int source)
{
    dist[source] = 0;
    priority_queue< pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll,ll>> > Q;
    Q.push(mp(0,source));
    while(!Q.empty())
    {
        pair<ll, ll> p = Q.top();
        Q.pop();
        ll x = p.second;
        if(!vis[x])
        {
            // if(x != source) tree[x].pb(par[x]), tree[par[x]].pb(x);      // Dijkstra Tree
            vis[x] = 1;
            rep(i,0,arr[x].size())
            {
                ll w = arr[x][i].first;
                ll e = arr[x][i].second;
                if((dist[x]+w)<dist[e])
                {
                    dist[e] = dist[x]+w;
                    par[e] = x;
                    Q.push(mp(dist[e],e));
                }
            }
        }
    }
}




void solve()
{
    cin>>n>>m;
    rep(i,0,n)
    {
        arr[i].clear();
        vis[i] = 0;
        dist[i] = LLONG_MAX;
    }
    rep(i,0,m)
    {
        int x, y;
        ll r;
        cin>>x>>y>>r;
        x--;
        y--;
        arr[x].pb(mp(r,y));
        arr[y].pb(mp(r,x));
    }
    
    // Path from source to destination
    int source = 0;
    int destination = n-1;
    dijkstra(source);
    if(dist[destination]==LLONG_MAX) cout<<-1;
    else
    {
        stack<int> path;
        int i = destination;
        while(i!=source)
        {
            path.push(i);
            i = par[i];
        }
        path.push(source);
        while(!path.empty())
        {
            cout<<path.top()+1<<" ";
            path.pop();
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
//  cin>>t;
    while(t--){
        solve();
    }
    return 0;
}