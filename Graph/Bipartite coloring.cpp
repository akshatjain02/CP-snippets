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
#define SIZE        100005
#define debug(x)    cerr << #x << " = " << x << endl;

using namespace std;

void MOD(ll &x)
{
	if (x >= lol) x -= lol;
	if (x < 0) x += lol;
}


vector<int> adj[SIZE];
int color[SIZE];


// using bfs
bool isBipartite(int src)
{
	memset(color,-1,sizeof(color[0])*SIZE);
	color[src] = 1;

	queue<int> q;
	q.push(src);

	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		rep(i,0,adj[u].size())
		{
			if(color[adj[u][i]]==-1)
			{
				color[adj[u][i]] = 1^color[u];
				q.push(adj[u][i]);
			}
			else if(color[adj[u][i]] == color[u]) return false;
		}
	}

	return true;

}


ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }



void solve()
{
	int n, m;
	cin>>n>>m;
	int arr[n];
	rep(i,0,n) cin>>arr[i];
	
	
	
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
//	cin>>t;
	while(t--){
		//cout<<"Case #"<<i++<<": ";
		solve();
  	  	//cout<<endl;	
  	}
	return 0;
}