#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define vi vector<int>
#define vll vector<ll> 
#define all(x) (x).begin() , (x).end()
#define inf 1000000000
#define mod 1000000007

void dbg(){
	cerr << endl;
}
template<typename Head , typename... Tail>
void dbg(Head h , Tail... t){
	cerr << h << " ";
	dbg(t...);
}

#ifdef EMBI_DEBUG
#define debug(...) cerr << "(" << #__VA_ARGS__  << "): ", dbg(__VA_ARGS__)
#else 
#define debug(...)
#endif

const int max_n = 1e5 + 9;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
ll power(ll a , ll b)
{
    ll prod = 1;
    while(b)
    {
        if(b&1)
        prod = (prod*a)%mod;
        a = (a*a)%mod;
        b >>= 1;
    }
    return prod;
}
vector<vector<int>> a;
vector<vector<int>> dp;
void dfs(int s , int p = -1){
    int inc = 1 , exc = 0;
    for(auto it : a[s]){
        if(it != p){
            dfs(it , s);
            inc += min(dp[it][0] , dp[it][1]);
            exc += dp[it][1];
        }
    }

    dp[s][0] = exc;
    dp[s][1] = inc;
}
void solve(){
    int n;
    cin >> n;
    a.resize(n+1);
    dp.resize(n+1 , vector<int>(2 , inf));
    for(int i = 0 ; i < n-1 ; i++){
        int x , y;
        cin >> x >> y;
        a[x].pb(y);
        a[y].pb(x);
    }

    dfs(1);
    cout << min(dp[1][0] , dp[1][1]) << "\n";
}
signed main(){
	int t = 1;
	// cin >> t;
	while(t--){
		solve();
	}
}