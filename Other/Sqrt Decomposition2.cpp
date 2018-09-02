//Codechef CHEFEXQ

#include <bits/stdc++.h>
 
#define ll          long long
#define pb          push_back
#define mp          make_pair
#define pii         pair<int,int>
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define lol        1000000007
#define endl        '\n'
#define rep(i,a,b)  for(int i=a;i<b;i++)
#define SIZE        1050000
#define SQSIZE      320
#define debug(x)        cerr << #x << " = " << x << endl;
 
using namespace std;
 
void MOD(ll &x)
{
    if (x >= lol) x -= lol;
    if (x < 0) x += lol;
}
 
 
int n, q;
int arr[SIZE], prefxor[SIZE], freq[SQSIZE][SIZE];
int blksize;
 
 
void update(int ind, int val)
{
    int i=ind;
    int blkind = i/blksize;
    if(!(i%blksize))
    {
        freq[blkind][prefxor[i]]--;
        prefxor[i] ^= (val^arr[ind]);
        freq[blkind][prefxor[i]]++;
        i++;
    }
    while(i%blksize)
    {
        freq[blkind][prefxor[i]]--;
        prefxor[i] ^= (val^arr[ind]);
        freq[blkind][prefxor[i]]++;
        i++;
    }
    
    arr[ind] = val;
}
 
 
 
int query(int ind, int k)
{
    int ans = 0;
    int i = 0;
    int lastxor = k;
    int blkind = 0;
    while((i+blksize)<=ind)
    {
        if(i) lastxor ^= prefxor[i-1];
        ans += freq[blkind][lastxor];
        i += blksize;
        blkind++;
    }
    if(i)lastxor ^= prefxor[i-1];
    while(i<=ind)
    {
        ans += (prefxor[i]==lastxor);
        i++;
    }
    return ans;
}
 
 
 
 
void solve()
{
    cin>>n>>q;
    blksize = (int)sqrt(n);
    int lastxor;
    rep(i,0,n)
    {
        cin>>arr[i];
        int blkind = i/blksize;
        if(!(i%blksize)) lastxor = 0;
        else lastxor = prefxor[i-1];
        prefxor[i] = lastxor^arr[i];
        freq[blkind][prefxor[i]]++;
    }
    
    while(q--)
    {
        int t, x, y;
        cin>>t>>x>>y;
        x--;
        if(t==1)update(x,y);
        else cout<<query(x,y)<<endl;
    }
 
    
}
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
//  cin>>t;
    while(t--){
        solve();
    }
    return 0;
}  