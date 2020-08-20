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
#define inf 1000000000000000
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
string s;
ll nB , ns , nc , pB , ps , pc;

bool check(ll num , ll amt){

    // cout << num << "\n";
    ll req_b = 0 , req_s = 0 , req_c = 0;
    for(auto it : s){
        if(it == 'B')req_b += num;
        else if(it == 'S')req_s += num;
        else req_c += num;
    }

    // cout << (max(0ll , req_b - nB) * pB + max(0ll , req_s - ns) * ps + max(0ll , req_c - nc) * pc) << "\n";
    return amt >= (max(0ll , req_b - nB) * pB + max(0ll , req_s - ns) * ps + max(0ll , req_c - nc) * pc);
}
void solve(){
    cin >> s;

    
    cin >> nB >> ns >> nc >> pB >> ps >> pc;

    ll amt;
    cin >> amt;

    ll beg = 0 , last = inf , mid , ans = 0;

    while(beg <= last){
        mid = (beg + last) >> 1;
        if(check(mid , amt)){
            ans = mid;
            beg = mid + 1;
        }
        else last = mid - 1;
    }

    cout << ans << "\n";
}
signed main(){
	int t = 1;
	// cin >> t;
	while(t--){
		solve();
	}
}