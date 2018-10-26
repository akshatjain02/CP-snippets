#include <bits/stdc++.h>
 
#define ll          long long
#define pb          push_back
#define mp          make_pair
#define pii         pair<int,int>
#define vi          vector<int>
#define vll         vector<ll>
#define all(a)      (a).begin(),(a).end()
#define lol         1000000007
#define rep(i,a,b)	for(int i=a;i<b;i++)
#define SIZE        1000005
#define debug(x)    cerr << #x << " = " << x << endl;
#define F first
#define S second
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	std::cerr << name << " = " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');std::cerr.write(names, comma - names) << " = " << arg1<<" |";__f(comma+1, args...);
}
#else
#define trace(...)
#endif
#define endl        '\n'
#define deci(n) cout<<fixed<<setprecision(n);
const double pi=acos(-1.0);


using namespace std;

void MOD(ll &x)
{
	if (x >= lol) x -= lol;
	if (x < 0) x += lol;
}

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }


ll memo[20][2];
vi digits;

ll num(int pos)
{
	ll num=0;
	rep(i,pos,digits.size())
	{
		num *= 10;
		num += (ll)digits[i];
	}
	return num;
}

ll dp(int pos, bool check)
{
	if(pos>=digits.size()) return 0;
	if(memo[pos][check]!=-1) return memo[pos][check];
	
	ll res = 0;
	int limit = digits[pos];

	if(check)
	{
		rep(d,0,10)
		{
			res += (dp(pos+1,1) + (ll)d*(ll)pow(10,digits.size()-pos-1));
		}
	}
	else
	{
		rep(d,0,limit)
		{
			res += (dp(pos+1, 1) + (ll)d*(ll)pow(10,digits.size()-pos-1));
		}
		res += (dp(pos+1, check) + (ll)limit*(num(pos+1) + 1));
	}
	return memo[pos][check] = res;
}

ll findans(ll n)
{
	digits.clear();
	memset(memo,-1,sizeof(memo));
	if(n<0) return 0;
	while(n)
	{
		digits.pb(n%10);
		n /= 10;
	}
	reverse(all(digits));
	return dp(0,0);
}


void solve()
{
	ll a, b;
	cin>>a>>b;
	ll ans = findans(b) - findans(a-1);
	cout<<ans<<endl;
}



// Remove  debugs!!

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	#ifndef ONLINE_JUDGE
//	    freopen("input.txt", "r", stdin);
//	    freopen("output.txt", "w", stdout);
//	#endif
	int t=1;
	cin>>t; int i=1;
	while(t--){
		//cout<<"Case #"<<i++<<": ";
		solve();
  	  	//cout<<endl;	
  	}
	return 0;
}