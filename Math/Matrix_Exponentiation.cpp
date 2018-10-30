#include <bits/stdc++.h>
 
#define ll          long long
#define pb          push_back
#define mp          make_pair
#define pii         pair<int,int>
#define vi          vector<int>
#define vll         vector<ll>
#define all(a)      (a).begin(),(a).end()
#define lol         1000000007
#define rep(i,a,b)    for(int i=a;i<b;i++)
#define rev(i,a,b)    for(int i=b-1;i>=a;i--)
#define SIZE        1000005
#define debug(x)    cerr << #x << " = " << x << endl;
#define F             first
#define S             second
#define endl        '\n'
#define deci(n)     cout<<fixed<<setprecision(n);
const double         pi=acos(-1.0);


using namespace std;

void MOD(ll &x)
{
    if (x >= lol) x -= lol;
    if (x < 0) x += lol;
}

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }


void multiply(ll a[3][3], ll b[3][3])
{
    ll product[3][3];

    rep(i,0,3)
    {
        rep(j,0,3)
        {
            product[i][j] = 0;
            rep(k,0,3)
            {
                MOD(product[i][j] += (a[i][k]*b[k][j])%lol);
            }
        }
    }

    rep(i,0,3) rep(j,0,3) a[i][j] = product[i][j];

}

ll power(ll m[3][3], ll n)
{
    ll ret[3][3] = {{1,0,0}, {0,1,0}, {0,0,1}};     //identity matrix

    while(n)
    {
        if(n%2) multiply(ret, m);
        n /= 2;
        multiply(m, m);
    }

    return ((ret[0][0]*7)%lol + (ret[0][1]*4)%lol + (ret[0][2]*2)%lol)%lol;     //depends on base cases
}

ll findans(ll n)
{    
    if(n==1) return 2;
    if(n==2) return 4;              //base cases
    // if(n==3) return 7;
    ll m[3][3] = {{1,1,1}, {1,0,0}, {0,1,0}};       //depends on dp relation
    return power(m, n-3);      //depends on base cases
}

void solve()
{
    ll n;
    cin>>n;
    cout<<findans(n)<<endl;  
    
}

/* 
* (Actually read this pls)
    * Really bad errors: int overflow (use ll), array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do something instead of nothing, you are smarter than you think you are.
    * Remove debugs
*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    #ifndef ONLINE_JUDGE
//        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
//    #endif
    int t=1;
   // cin>>t; int i=1;
    while(t--){
        //cout<<"Case #"<<i++<<": ";
        solve();
            //cout<<endl;    
      }
    return 0;
}