
// Problem : Sky Code
// Contest : SPOJ - Classical
// URL : https://www.spoj.com/problems/MSKYCODE/
// Memory Limit : 1536 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)


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
#define vi vector<ll>
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

const ll max_n = 1e5 + 9;

typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
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
void solve(ll n){
	// ll n;
	// cin >> n;
	ll a[n] , max1 = 0;
	for(ll i = 0 ; i < n ; i++){
		cin >> a[i];
		max1 = max(max1 , a[i]);
	}
	
	ll dp[n][max1 + 1][5];
	memset(dp , 0 , sizeof(dp));
	for(ll i = 0 ; i < n ; i++){
		dp[i][0][0] = 1;
	}
	dp[0][a[0]][1] = 1;
	for(ll i = 1 ; i < n ; i++){
		for(ll j = 0 ; j <= max1 ; j++){
			for(ll k = 1 ; k <= 4 ; k++){
				dp[i][j][k] += dp[i-1][j][k];
				dp[i][__gcd(a[i] , j)][k] += dp[i-1][j][k-1];
			}
		}
	}
	
	cout << dp[n-1][1][4] << "\n";
}
signed main(){
	ll t = 1;
	// cin >> t;
	while(cin >> t){
		solve(t);
	}
}