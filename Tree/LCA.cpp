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
#define SIZE        500005
#define LOGSIZE		19
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

vi adj[SIZE];
int par[SIZE][LOGSIZE];		//stores 2^j th ancestor of i
int depth[SIZE] = {0};

void preprocess(int v, int p)
{
	par[v][0] = p;
	if(p+1) depth[v] = depth[p] + 1;
	rep(i,1,LOGSIZE) if(par[v][i-1]+1) par[v][i] = par[par[v][i-1]][i-1];
	for(auto u : adj[v]) if(p-u) preprocess(u,v);
}

int lca(int v, int u)
{
	if(depth[v]<depth[u]) swap(u,v);
	rev(i,0,LOGSIZE) if((par[v][i]+1) && depth[par[v][i]]>=depth[u]) v = par[v][i];
	if(v == u) return v;
	rev(i,0,LOGSIZE) if(par[v][i] - par[u][i]) v = par[v][i], u = par[u][i];
	return par[v][0];
}

void solve()
{
	rep(i,0,SIZE)
	{
		rep(j,0,LOGSIZE) par[i][j] = -1;
		depth[i] = 0;
	}
	int n;
	cin>>n;
	rep(i,0,n-1)
	{
		int x, y;
		cin>>x>>y;
		x--; y--;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	int root = 0;
	preprocess(root, -1);
	int q;
	cin>>q;
	while(q--)
	{
		int u, v;
		cin>>u>>v;
		u--; v--;
		cout<<lca(u,v)+1<<endl;
	}



	
	
}

/* 
* (Actually read this pls -_-)
    * Really bad errors: int overflow (use ll), array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Don't forget to sort the array
    * Common sense: do something instead of nothing, you are smarter than you think you are.
    * Remove debugs
*/

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