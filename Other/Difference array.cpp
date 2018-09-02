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
 
		void solve()
		{
			ll n, m;
			cin>>n>>m;
			ll arr[n] = {0};
			ll type[m], l[m], r[m], count[m+1], dcount[m] = {0};	//dcount[i] = count[i] - count[i+1]
			rep(i,0,m)
			{
				cin>>type[i]>>l[i]>>r[i];
				l[i]--;
				r[i]--;
				count[i] = 1;
			}
			count[m] = 1;
			for(int i=m-1; i>=0; i--)
			{
				MOD(count[i] = dcount[i] + count[i+1]);
				if(type[i]==2)
				{
					MOD(dcount[r[i]] += count[i]);
					MOD(dcount[l[i]-1] -= count[i]);
				}
			}
			ll darr[n] = {0};	//darr[i] = arr[i] - arr[i+1]
			for(int i=m-1; i>=0; i--)
			{
				if(type[i]==1)
				{
					MOD(darr[r[i]] += count[i]);
					MOD(darr[l[i]-1] -= count[i]);
				}
			}
			MOD(arr[n-1] = darr[n-1]);
			for(int i=n-2;i>=0;i--)
			{
				MOD(arr[i] = darr[i] + arr[i+1]);
			}
			rep(i,0,n)
			{
				cout<<arr[i]<<" ";
			}
			cout<<endl;
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