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



int n;
ll arr[1000005]={0}, BIT[1000005] = {0};        ////CHANGES ACCORDING TO QUERY




void update(int x, ll val)
{
    int i=x;
    while(x<=n)
    {
        BIT[x] += (val - arr[i]);       //CHANGES ACCORDING TO QUERY
        x += (x&-x);
    }
    arr[i] = val;                       //CHANGES ACCORDING TO QUERY        
}




ll query(int l, int r)
{
    ll suml=0, sumr=0;
    l--;
    
    while(l>0)
    {
        suml += BIT[l];                 //CHANGES ACCORDING TO QUERY
        l -= (l&-l);
    }
    
    while(r>0)
    {
        sumr += BIT[r];                 //CHANGES ACCORDING TO QUERY
        r -= (r&-r);
    }
    
    return sumr-suml;                   //CHANGES ACCORDING TO QUERY
    
}




void solve()
{
	rep(i,0,n+2)
	{
	    BIT[i] = arr[i] = 0;        //CHANGES ACCORDING TO QUERY
	}
	cin>>n;
	rep(i,1,n+1)
	{
	    int x;
	    cin>>x;
	    update(i, x);
	}
	
	int q;
	cin>>q;
	while(q--)
	{
	    int x, y;
	    cin>>x>>y;
	    cout<<query(x,y)<<endl;
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