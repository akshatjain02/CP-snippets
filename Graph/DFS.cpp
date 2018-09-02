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



ll n, p;
vector<int> arr[100005];
int vis[100005] = {0};
ll mem = 0;
ll comp = 0;
ll ans = 0;


   
void dfs(int i)
{
    if(!vis[i])
    {
        vis[i] = 1;
        mem++;
        rep(j,0,arr[i].size())
        {
     	   dfs(arr[i][j]);
        }            
    }
}



void solve()
{
    cin>>n>>p;
    rep(i,0,n)
    {
	   	arr[i].clear();
       	vis[i] = 0;
    }
    mem = 0;
    comp = 0;
    ans = 0;
    rep(i,0,p)
    {
        ll x, y;
        cin>>x>>y;
        arr[x].pb(y);
        arr[y].pb(x);
    }
    rep(i,0,n)
    {
        if(!vis[i])
        {
	       	comp++;					  //comp = no of groups/components
            mem = 0;
            dfs(i);
            //ans += mem;             //mem = no of members in last component
        }
    }
    cout<<ans;
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