
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



ll arr[SIZE+5], tree[4*SIZE+5];
int n, q;




void build(int node, int start, int end)
{
	if(start>end) return;
	if(start==end) tree[node] = arr[start];	
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
		arr[ind] = val;
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





int query(int node, int start, int end, int l, int r)
{
	if(r<start || end<l) return 0;
	if(l<=start && end<=r) return tree[node];

	int mid = (start+end)/2;
	int p1 = query(2*node, start, mid, l, r);
	int p2 = query(2*node+1, mid+1, end, l, r);

	return (p1 + p2);
}





void solve()
{
	cin>>n>>q;
	rep(i,1,n+1) cin>>arr[i];
	build(1,1,n);
	rep(i,1,q+1)
	{
		int type;
		int x, y;
		cin>>type>>x>>y;
		if(type==1)
		{
			ll ans = query(1,1,n,x,y);
			cout<<ans<<endl;
		}
		else
		{
			update(1,1,n,x,y);
		}
	}

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