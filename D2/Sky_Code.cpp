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
void solve(){
    int n;
    cin >> n;
	vector<int> a(n);
    int max1 = 0;
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
        max1 = max(max1 , a[i]);
    }


    int dp[n][max1 + 1][5];
    memset(dp , 0 , sizeof(dp));
    // vector<vector<vector<int>>> dp(n , vector<vector<int>> (max1 + 1 , vector<int> (5 , 0)));
    for(int i = 0 ; i < n ; i++){
        dp[i][0][0] = 1;
    }
    dp[0][a[0]][1] = 1;
    // cout << "a[0]" << a[0] << "\n"; 
    for(int i = 1 ; i < n ; i++){
        for(int j = 0 ; j <= max1 ; j++){
            for(int k = 1 ; k <= 2 ; k++){
                dp[i][j][k] += dp[i-1][j][k];
                dp[i][__gcd(j , a[i])][k] += dp[i-1][j][k-1];
            }
        }
    }
    

    // for(int i = 0 ; i < n ; i++){
    //     for(int j = 0 ; j <= max1 ; j++){
    //         for(int k = 0 ; k <= 4 ; k++){
    //             cout << "(" << i << " " << j << " " << k << ") : " << dp[i][j][k] << " ";
    //         }
    //         cout << "\n";
    //     }
    // }
    cout << dp[n-1][1][2] << "\n";
}
signed main(){
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}
}