#include <bits/stdc++.h>
 
#define ll          long long
#define pb          push_back
#define mp          make_pair
#define pii         pair<int,int>
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define lol         1000000007
#define endl        '\n'
#define rep(i,a,b)	for(int i=a;i<b;i++)
#define SIZE		1000005
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



void dijkstra(int source)
{
	dist[source] = 0;
	multiset<pair<ll,ll>> pqueue;		//priority queue stores vertices
	priority_queue< pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll,ll>> > Q;
	Q.push(mp(0,source));
	while(!Q.empty())
	{
		pair<ll, ll> p = Q.top();
		Q.pop();
		ll x = p.second;
		if(!vis[x])
		{
			vis[x] = 1;
			rep(i,0,arr[x].size())
			{
				ll w = arr[x][i].first;
				ll e = arr[x][i].second;
				if((dist[x]+w)<dist[e])
				{
					dist[e] = dist[x]+w;
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
	int source;
	cin>>source;
	dijkstra(source);
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}