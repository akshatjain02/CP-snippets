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
int vis[SIZE] = {0};
vi topsort;

void topological_sort(int s)
{
	vis[s] = 1;
	for(auto i:adj[s])
	{
		if(!vis[i]) topological_sort(i);
	}
	topsort.pb(s);
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
		// adj[y].pb(x);
	}
	// for lexographically smallest sorting
	rep(i,0,n) sort(all(adj[i]), greater<int>());
	for(int i=n-1;i>=0;i--)
	{
		if(!vis[i]) topological_sort(i);
	}
	reverse(all(topsort));
	rep(i,0,n) cout<<topsort[i]+1<<" ";

	
	
}



// Remove  debugs!!

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	int t=1;
//	cin>>t; int i=1;
	while(t--){
		//cout<<"Case #"<<i++<<": ";
		solve();
  	  	//cout<<endl;	
  	}
	return 0;
}