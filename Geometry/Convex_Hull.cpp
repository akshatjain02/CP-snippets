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


struct point
{
	double x, y;
};

vector<point> hull;

bool cmp(point a, point b)
{
	return a.x < b.x || (a.x==b.x && a.y<b.y);
}

bool cw(point a, point b, point c)
{
	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

bool ccw(point a, point b, point c)
{
	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}

void convex_hull(vector<point> arr)
{
	sort(all(arr), cmp);
	point p1 = arr[0], p2 = arr.back();
	vector<point> up, down;
	up.pb(p1);
	down.pb(p1);
	rep(i,1,arr.size())
	{
		if(i==arr.size()-1 || cw(p1,arr[i],p2))
		{
			while (up.size() >= 2 && !cw(up[up.size()-2], up[up.size()-1], arr[i]))
                up.pop_back();
            up.push_back(arr[i]);
        }
        if (i == arr.size() - 1 || ccw(p1, arr[i], p2)) {
            while(down.size() >= 2 && !ccw(down[down.size()-2], down[down.size()-1], arr[i]))
                down.pop_back();
            down.push_back(arr[i]);
        }
	}
	rep(i,0,up.size())
        hull.pb(up[i]);
    for (int i = down.size() - 2; i > 0; i--)
        hull.pb(down[i]);

}

void solve()
{
	
	
	
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