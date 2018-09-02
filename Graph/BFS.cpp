#include <bits/stdc++.h>
 
#define ll          long long
#define pb          push_back
#define mp          make_pair
#define pii         pair<int,int>
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define lol        1000000007
#define endl        '\n'
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;

void MOD(ll &x)
{
    if (x >= lol) x -= lol;
    if (x < 0) x += lol;
}


ll n, m;
vector<int> arr[100000];
int vis[100000] = {0};
ll dist[100000];
queue<int> q;


void bfs(int s)
{
    vis[s] = 1;
    dist[s] = 0;
    q.push(s);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        rep(i,0,arr[u].size())
        {
            int v = arr[u][i];
            if(!vis[v])
            {
                vis[v] = 1;
                dist[v] = dist[u] + 1;
                q.push(v);
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
    q.clear();
    rep(i,0,m)
    {
        int x, y;
        cin>>x>>y;
        //x--;
        //y--;
        arr[x].pb(y);
        arr[y].pb(x);
    }
    int source;
    //cin>>source;
    //source--;
    bfs(source);       
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}