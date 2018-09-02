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
#define SIZE		1000005
#define debug(x)        cerr << #x << " = " << x << endl;
using namespace std;
 
 
void MOD(ll &x)
{
	if (x >= lol) x -= lol;
	if (x < 0) x += lol;
}
 
 
typedef struct QUERY
{
    ll k;
    int x, y;
    int pos;
}QUERY;
 
 
ll arr[SIZE+5], tree[4*SIZE+5], b[SIZE+5];
int n, q;
 
 
void build(int node, int start, int end)
{
	if(start>end) return; 
	if(start==end) tree[node] = b[start];
	else
	{
		int mid = (start+end)/2;
		build(2*node, start, mid);
		build(2*node+1, mid+1, end);
 
		tree[node] = tree[2*node] + tree[2*node+1];
	}
}
 
 
void update(int node, int start, int end, int ind, int val)
{
	if(start>end) return;
	if(start==end)
	{
		b[ind] = val;
		tree[node] = val;
	}
	else
	{
		int mid = (start+end)/2;
		if(ind<=mid) update(2*node, start, mid, ind, val);
		else update(2*node+1, mid+1, end, ind, val);
		
		tree[node] = tree[2*node] + tree[2*node+1];
	}
}
 
 
int query1(int node, int start, int end, int l, int r)
{
	if(r<start || end<l) return 0;
	if(l<=start && end<=r) return tree[node];
 
	int mid = (start+end)/2;
	int p1 = query1(2*node, start, mid, l, r);
	int p2 = query1(2*node+1, mid+1, end, l, r);
 
	return (p1 + p2);
}
 

bool myfunc(QUERY q1, QUERY q2)
{
    return q1.k < q2.k;
}
 
 
void solve()
{
	cin>>n;
	pair<ll, int> sarr[n+1];
	rep(i,1,n+1)
	{
	    cin>>arr[i];
	    b[i] = 1;
	    sarr[i] = mp(arr[i], i);
	}
	build(1,1,n);
	sort(sarr+1, sarr+n+1);
	cin>>q;
	QUERY query[q];
	rep(i,0,q)
	{
	    int a, b;
	    ll k;
	    cin>>a>>b>>k;
	    query[i].x = a;
	    query[i].y = b;
	    query[i].k = k;
	    query[i].pos = i;
	}
	
	sort(query, query+q, myfunc);
	
	int ans[q] = {0};
	
	int po = 1;
	rep(i,0,q)
	{
	    while(po<=n && sarr[po].first<=query[i].k)
	    {
	        update(1,1,n,sarr[po].second,0);
	        po++;
	    }
	    ans[query[i].pos] = query1(1,1,n,query[i].x, query[i].y);
	}
	
	rep(i,0,q)cout<<ans[i]<<endl;
	
 
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