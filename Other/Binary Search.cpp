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


void solve()
{
    ll n;
    cin>>n;
    ll start = 1, end = n;
    while(start<=end)
    {
        ll mid = (start+end)/2;
        ll n1 = n;
        ll c1=0, c2=0;
        while(n1>mid)
        {
            n1 -= mid;
            ll temp = n1/10;
            n1 -= temp;
            c1 += mid;
            c2 += temp;
        }
        c1 += n1;
        debug(c1);debug(c2);
        if(c1==c2)
        {
            cout<<mid;
            return;
        }
        else if(c1<c2) start = mid+1;
        else end = mid-1;
    }
	cout<<start;
	
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