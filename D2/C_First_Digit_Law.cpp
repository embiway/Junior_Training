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
        prod = (prod*a);
        a = (a*a);
        b >>= 1;
    }
    return prod;
}

vector<pair<ll,ll>> bounds;


vector<double> find_prob(vector<pair<ll,ll>> a){
    vector<double> prob;
    for(auto it : a){
        ll l = it.ff , r = it.ss;
        ll sum = 0;
        for(auto it1 : bounds){
            // cout << max(0ll , min(it1.ss , r) - max(it1.ff , l) + 1) << "\n";
            sum += max(0ll , min(it1.ss , r) - max(it1.ff , l) + 1);
        }

        prob.pb((sum * 1.0) / (r - l + 1));
    }
    return prob;
}
void solve(){
    for(ll i = 0 ; i <= 18 ; i++){
        ll cnt1 = power(10 , i);
        bounds.pb({cnt1 , 2*cnt1 - 1});
    }
	ll n;
    cin >> n;
    vector<pair<ll,ll>> a(n);
    for(auto &it : a){
        cin >> it.ff >> it.ss;
    }

    ll k;
    cin >> k;
    vector<double> prob = find_prob(a);
    double dp[n][n+1];

    for(ll i = 0 ; i < n ; i++){
        for(ll j = 0 ; j <= n ; j++){
            dp[i][j] = 0.0;
        }
    }
    dp[0][0] = (1 - prob[0]);
    dp[0][1] = prob[0];

    for(ll i = 1 ; i < n ; i++){
        for(ll j = 0 ; j <= n ; j++){
            dp[i][j] = dp[i-1][j] * (1 - prob[i]);
            if(j > 0){
                dp[i][j] += (dp[i-1][j-1] * prob[i]);
            }
        }
    }

    ll num = ceil((1.0 * k * n)/100);

    double sum = 0;

    for(ll i = num ; i <= n ; i++){
        sum += dp[n-1][i];
    }

    printf("%.15lf\n" , sum);
}
signed main(){
	ll t = 1;
	// cin >> t;
	while(t--){
		solve();
	}
}