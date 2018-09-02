#include <bits/stdc++.h>
 
	#define ll          long long
	#define pb          push_back
	#define mp          make_pair
	#define pii         pair<int,int>
	#define vi          vector<int>
	#define all(a)      (a).begin(),(a).end()
	#define lol        1000000007
	#define endl        '\n'
	#define rep(i,a,b)	for(int i=a;i<b;i++)
	using namespace std;
 
	void MOD(ll &x)
	{
		if (x >= lol) x -= lol;
		if (x < 0) x += lol;
	}


	int n, s;
	vector<int> arr[100000];
	int visited[100000] = {0};
	int groups = 0;

	void bfs(int i)
	{
		if(!visited[i])
		{
			visited[i] = 1;
			int m = arr[i].size();
			rep(j,0,m)
			{
				bfs(arr[i][j]);
			}
		}
		
	}


	void solve()
	{
		cin>>n>>s;
		rep(i,0,n)
		{
			arr[i].clear();
			visited[i] = 0;
		}
		groups = 0;
		while(s--)
		{
			int x, y;
			cin>>x>>y;
			arr[x].pb(y);
			arr[y].pb(x);
		}
		
		rep(i,0,n)
		{
			if(!visited[i])
			{
				groups++;
				bfs(i);
			}
		}
		cout<<groups<<endl;
		
		
		
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