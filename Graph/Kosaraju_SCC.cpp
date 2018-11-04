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

vi adj[SIZE];
vi adj_rev[SIZE];
stack<int> s;
int vis[SIZE] = {0};

void dfs1(int source)
{
	vis[source] = 1;
	for(int i : adj[source]) if(!vis[i]) dfs1(i);
	s.push(source);
}

void dfs2(int source)
{
	vis[source] = 1;
	for(int i : adj_rev[source]) if(!vis[i]) dfs2(i);
}

void solve()
{
	int n, m;
	cin>>n>>m;
	while(m--)
	{
		int x, y;
		cin>>x>>y;
		x--, y--;
		adj[x].pb(y);
		adj_rev[y].pb(x);
	}
	rep(i,0,n) if(!vis[i]) dfs1(i);
	rep(i,0,n) vis[i] = 0;
	while(!s.empty())
	{
		int source = s.top();
		s.pop();
		if(!vis[source]) dfs2(source);
	}	
	
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