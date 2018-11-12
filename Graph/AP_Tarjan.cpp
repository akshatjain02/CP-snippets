#include <bits/stdc++.h>
 
#define ll          long long
#define pb          push_back
#define mp          make_pair
#define pii         pair<int,int>
#define vi          vector<int>
#define vll         vector<ll>
#define all(a)      (a).begin(),(a).end()
#define lol         1000000007
#define rep(i,a,b)	for(int i=a;i<b;i++)
#define rev(i,a,b)	for(int i=b-1;i>=a;i--)
#define SIZE        1000005
#define debug(x)    cerr << #x << " = " << x << endl;
#define F 			first
#define S 			second
#define endl        '\n'
#define deci(n) 	cout<<fixed<<setprecision(n);
const double 		pi=acos(-1.0);


using namespace std;

void MOD(ll &x)
{
	if (x >= lol) x -= lol;
	if (x < 0) x += lol;
}

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }

int n, m;
vi adj[SIZE];
int disc[SIZE], low[SIZE];
bool vis[SIZE], AP[SIZE];
int APcount = 0;
int timer = 0;

void dfs(int u, int par)
{
	vis[u] = true;
	disc[u] = low[u] = timer++;
	int child = 0;
	for(int v : adj[u])
	{
		if(!vis[v])
		{
			child++;
			dfs(v, u);
			low[u] = min(low[u], low[v]);
			if(par==-1 && child>1) AP[u] = true, APcount++;
			if(par!=-1 && low[v]>=disc[u]) AP[u] = true, APcount++;
		}
		else if(par!=v) low[u] = min(low[u], disc[v]);
	}
}

void solve()
{
	timer = 0;
	APcount = 0;
	rep(i,0,SIZE)
	{
		adj[i].clear();
		vis[i] = false;
		AP[i] = false;
		disc[i] = 0;
		low[i] = INT_MAX;
	}
	// int n, m;
	cin>>n>>m;
	rep(i,0,m)
	{
		int x, y;
		cin>>x>>y;
		x--; y--;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	// dfs(0, -1);
	rep(i,0,n) if(!vis[i]) dfs(i, -1);

	cout<<APcount<<endl;
	rep(i,0,n) if(AP[i]) cout<<i+1<<" ";
	
	
}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	#ifndef ONLINE_JUDGE
//	    freopen("input.txt", "r", stdin);
//	    freopen("output.txt", "w", stdout);
//	#endif
	int t=1;
//	cin>>t; int i=1;
	while(t--){
		//cout<<"Case #"<<i++<<": ";
		solve();
  	  	//cout<<endl;	
  	}
	return 0;
}