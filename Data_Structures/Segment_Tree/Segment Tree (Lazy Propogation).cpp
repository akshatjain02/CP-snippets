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
#define SIZE        1000005
#define debug(x)        cerr << #x << " = " << x << endl;

using namespace std;

void MOD(ll &x)
{
	if (x >= lol) x -= lol;
	if (x < 0) x += lol;
}




int n, q;
ll arr[SIZE], tree[4*SIZE], lazy[4*SIZE];




void build(int node, int start, int end)
{
    if(start>end)return;
    if(start==end)tree[node]=arr[start];
    else
    {
        int mid = (start+end)/2;
        
        build(2*node, start, mid);
        build(2*node+1, mid+1, end);
        
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}




void update(int node, int start, int end, int l, int r, ll val)
{
    if(lazy[node])
    {
        tree[node] += (end - start + 1)*lazy[node];     //be careful b/w = and +=
        if(start!=end)
        {
            lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(start>end || start>r || end<l) return;
    
    if(start>=l && end<=r)
    {
        tree[node] += (end-start+1)*val;        //be careful b/w = and +=
        if(start!=end)
        {
            lazy[2*node] += val;
            lazy[2*node+1] += val;
        }
        return;
    }
    int mid = (start+end)/2;
    update(2*node, start, mid, l, r, val);
    update(2*node+1, mid+1, end, l, r, val);
    
    tree[node] = tree[2*node] + tree[2*node+1];
}




ll query(int node, int start, int end, int l, int r)
{
    if(start > end || start > r || end < l) return 0;
    if(lazy[node])
    {
        tree[node] += (end - start + 1)*lazy[node];     //be careful b/w = and +=
        if(start != end)
        {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(start >= l and end <= r) return tree[node];
    
    int mid = (start + end)/2;
    ll p1 = query(node*2, start, mid, l, r);
    ll p2 = query(node*2 + 1, mid + 1, end, l, r);

    return (p1 + p2);
}





void solve()
{
	cin>>n>>q;
	rep(i,1,n+1)cin>>arr[i];
	//rep(i,1,n+1) arr[i]=0;
	rep(i,0,4*SIZE+1) lazy[i]=0;
	
	build(1,1,n);
	
	while(q--)
	{
	    int type;
	    cin>>type;
	    if(type)
	    {
	        int x, y;
	        cin>>x>>y;
	        cout<<query(1,1,n,x,y)<<endl;
	    }
	    else
	    {
	        int x, y;
	        ll v;
	        cin>>x>>y>>v;
	        update(1,1,n,x,y,v);
	    }
	}
	
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
	return 0;
}