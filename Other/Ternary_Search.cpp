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

int n;
pair<double,double> arr[SIZE];

double findradius(double x)
{
	double r = 0;
	rep(i,0,n)
	{
		double val = ((arr[i].F-x)*(arr[i].F-x)+arr[i].S*arr[i].S)/(2*arr[i].S);
		r = max(r,val);
	}
	return r;
}

double ternary_search(double l, double r)
{
	double eps = 1e-7;
	while(r-l > eps)
	{
		double m1 = l + (r-l)/3;
		double m2 = r - (r-l)/3;
		double r1 = findradius(m1);
		double r2 = findradius(m2);
		if(r1>r2) l = m1;	//finds minima
		else r = m2;
	}
	return findradius(l);
}

void solve()
{
	deci(15);	//don't forget this -_-
	cin>>n;
	rep(i,0,n) cin>>arr[i].F>>arr[i].S;
	rep(i,1,n)
	{
		if((arr[0].S)*(arr[i].S)<0)
		{
			cout<<-1;
			return;
		}
		arr[i].S = abs(arr[i].S);
	}
	arr[0].S = abs(arr[0].S);
	cout<<ternary_search(-1e9, 1e9)<<endl;	
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
//	cin>>t; int i=1;
	while(t--){
		//cout<<"Case #"<<i++<<": ";
		solve();
  	  	//cout<<endl;	
  	}
	return 0;
}