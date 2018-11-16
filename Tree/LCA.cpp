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
int lcatree[4*SIZE+5];

void preprocess(int v, int p)
{
	par[v][0] = p;
	if(p) depth[v] = depth[p] + 1;
	rep(i,1,LOGSIZE) if(par[v][i-1]) par[v][i] = par[par[v][i-1]][i-1];
	for(int u : adj[v]) if(p-u) preprocess(u,v);
}

int lca(int v, int u)
{
	if(depth[v]<depth[u]) swap(u,v);
	rev(i,0,LOGSIZE) if(par[v][i] && depth[par[v][i]]>=depth[u]) v = par[v][i];
	if(v == u) return v;
	rev(i,0,LOGSIZE) if(par[v][i] - par[u][i]) v = par[v][i], u = par[u][i];
	return par[v][0];
}

void buildLcaTree(int node, int start, int end)
{
	if(start>end) return;
	if(start==end) lcatree[node] = start;
	else
	{
		int mid = (start+end)/2;
		buildLcaTree(2*node, start, mid);
		buildLcaTree(2*node+1, mid+1, end);

		lcatree[node] = lca(lcatree[2*node], lcatree[2*node+1]);
	}
}

int lcaquery(int node, int start, int end, int l, int r)
{
	if(r<start || end<l) return -1;
	if(l<=start && end<=r) return lcatree[node];

	int mid = (start+end)/2;
	int p1 = lcaquery(2*node, start, mid, l, r);
	int p2 = lcaquery(2*node+1, mid+1, end, l, r);

	if(p1 == -1) return p2;
	if(p2 == -1) return p1;

	return lca(p1, p2);
}

void solve()
{
	rep(i,0,SIZE)
	{
		rep(j,0,LOGSIZE) par[i][j] = 0;
		depth[i] = 0;
	}
	int n;
	cin>>n;
	rep(i,0,n-1)
	{
		int x, y;
		cin>>x>>y;
		// x++; y++;		// x and y should be 1 indexed
		adj[x].pb(y);
		adj[y].pb(x);
	}
	int root = 1;
	preprocess(root, 0);
	buildLcaTree(1,1,n);
	int q;
	cin>>q;
	while(q--)
	{
		int u, v;
		cin>>u>>v;
		// u--; v--;		// u and v should be 1 indexed
		cout<<lcaquery(1,1,n,u,v)<<endl;
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