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
	int n , m;
    cin >> n >> m;
    string p;
    cin >> p;

    if(m == 0){
        cout << power(26 , n) << "\n";
        return;
    }
    vector<int> a(m);
    for(auto &it : a)cin >> it , it--;

    int num = p.size();
    vector<int> z(num);
    for(int i = 1 , l = 0 , r = 0 ; i < num ; i++){
        if(i <= r){
            z[i] = min(r - i + 1 , z[i-l]);
        }
        while(i + z[i] < num && p[z[i]] == p[i + z[i]])
            z[i]++;
        
        if(i + z[i] - 1 > r)l = i , r = i + z[i] - 1;
    }


    vector<int> diff(n+1 , 0);
    diff[a[0]]++;
    diff[a[0] + num]--;

    for(int i = 1 ; i < m ; i++){
        if(a[i] >= a[i-1] + num){
            diff[a[i]]++;
            diff[a[i] + num]--;
        }
        else{
            int comm_size = a[i-1] + num - a[i];
            if(z[num-comm_size] == comm_size){
                diff[a[i]]++;
                diff[a[i] + num]--;
            }
            else{
                cout << 0 << "\n";
                return;
            }
        }
    }

    ll cnt = 0;
    for(int i = 1 ; i < n ; i++){
        diff[i] += diff[i-1];
    }
    for(int i = 0 ; i < n ; i++){
        if(diff[i] == 0)cnt++;
    }

    cout << power(26 , cnt) << "\n";
}
signed main(){
	int t = 1;
	// cin >> t;
	while(t--){
		solve();
	}
}