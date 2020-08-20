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
	string s;
    cin >> s;

    int n = s.size();
    vector<int> pi(n);
    for(int i = 1 ; i < n ; i++){
        int j = pi[i-1];
        while(j > 0 && s[i] != s[j]){
            j = pi[j-1];
        }

        if(s[i] == s[j])j++;
        pi[i] = j;
    }

    int cnt[n] = {0};
    for(int i = 0 ; i < n ; i++){
            cnt[pi[i]]++;
    }
    for(int i = n-1 ; i > 0 ; i--){
        cnt[pi[i-1]] += cnt[i];
    }
    
    for(int i = 0 ; i <= n ; i++)cnt[i]++;

    
    // cout << "\n";
    vector<int> z(n);
    for(int i = 1 , l = 0 , r = 0 ; i < n ; i++){
        if(i <= r){
            z[i] = min(r - i + 1 , z[i-l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]])z[i]++;
        if(i + z[i] - 1 > r)r = i + z[i] - 1 , l = i;
    }

    vector<pair<int,int>> vec;
    vec.pb({n , 1});
    for(int i = 0 ; i < n ; i++){
        if(i + z[i] == n){
            vec.pb({z[i] , cnt[z[i]]});
        }
    }

    cout << vec.size() << "\n";
    reverse(all(vec));
    for(auto i : vec){
        cout << i.ff << " " << i.ss << "\n";
    }
}
signed main(){
	int t = 1;
	// cin >> t;
	while(t--){
		solve();
	}
}