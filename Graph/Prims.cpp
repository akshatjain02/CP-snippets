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


int n, m;
vector<pair<ll,int>> arr[100000];
int vis[100000] = {0};
ll minCost = 0;


void prim(int x)
{
    priority_queue<pair<ll,int>, vector<pair<ll, int>>, greater<pair<ll,int>>> Q;
    Q.push(mp(0,x));
    while(!Q.empty())
    {
        pair<ll, int> p = Q.top();
        Q.pop();
        int x = p.second;
        if(!vis[x])
        {
            vis[x] = 1;
            minCost += p.first;
            rep(i,0,arr[x].size())
            {
                int y = arr[x][i].second;
                if(!vis[y])
                    Q.push(arr[x][i]);
            }            
        }
    }   
}


void solve()
{
    cin>>n>>m;
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
    prim(0);
    cout<<minCost<<endl;
		
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