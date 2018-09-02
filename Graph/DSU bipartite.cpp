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
 

int n, m;
vector<int> adj[SIZE];
int color[SIZE];
int blocked[SIZE]={0};
int dsu[SIZE];
int size[SIZE];


ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }


int root(int v)
{
    if(v==dsu[v]) return v;
    return dsu[v]=root(dsu[v]);
}


void merge(int a, int b)
{
	int ra = root(a);
    int rb = root(b);
    if(size[ra]<size[rb]){ swap(a,b); swap(ra,rb);}
    if(ra==rb)
    {
    	if(color[a]==color[b])
    	{
    		blocked[ra] = 1;
    	}
    }
    else
    {
    	if(color[a]==color[b]){rep(i,0,adj[rb].size())color[adj[rb][i]] ^= 1;}
    	rep(i,0,adj[rb].size()) adj[ra].pb(adj[rb][i]);
        dsu[rb] = ra;
        size[ra] += size[rb];
        blocked[ra] |= blocked[rb];
    }
}
 
 
void solve()
{
	cin>>n>>m;
	int arr[n];
	rep(i,0,n) cin>>arr[i];
    rep(i,0,SIZE)
    {
    	dsu[i]=i;
    	size[i]=1;
    	adj[i].pb(i);
    	color[i]=1;
    	blocked[i]=0;
    }
	while(m--)
	{
		int x, y;
		cin>>x>>y;
		x--;
		y--;
		merge(x,y);
	}
	
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