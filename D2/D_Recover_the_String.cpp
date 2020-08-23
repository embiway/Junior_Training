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
ll find_val(ll num){
    ll beg = 0 , last = inf , mid , ans = -1;
    while(beg <= last)
    {
        mid = (beg + last) >> 1;
        if(mid * (mid - 1) / 2 == num){
            return mid;
        }
        else if(mid * (mid - 1) / 2 < num){
            beg = mid + 1;
        }
        else last = mid - 1;
    }
    return -1;
}


void solve(){
	ll a00 , a01 , a10 , a11;
    cin >> a00 >> a01 >> a10 >> a11;

    ll zero = 0 , ones = 0;

    zero = find_val(a00);
    ones = find_val(a11);
    
    if(a00 == 0 && a11 == 0){
        if(a01 + a10 == 1){
            zero = 1 , ones = 1;
        }
    }
    else if(a00 == 0){
        if(a01 + a10)zero = 1;
    }
    else if(a11 == 0){
        if(a01 + a10)ones = 1;
    }

    // cout << zero << " " << ones << "\n";
    if(zero == -1 || ones == -1){
        cout << "Impossible\n";
        return;
    }
    if(zero * ones != a01 + a10){
        cout << "Impossible\n";
        return;
    }

    ll cnt = ones , sum = 0;
    vector<ll> zeroes(zero);
    for(ll i = 0 ; i < zero ; i++){
        if(sum + cnt <= a01){
            zeroes[i] = cnt;
            sum += cnt;
        }
        else{
            while(sum + cnt > a01){
                cnt--;
            }
            zeroes[i] = cnt;
            sum += cnt;
        }
    }

    for(ll i = 1 ; i < zero ; i++){
        zeroes[i-1] -= zeroes[i];
    }

    int num = 0;
    for(auto it : zeroes){
        num += it;
    }

    string str = string(ones - num , '1');
    string s;
    for(auto it : zeroes){
        s.push_back('0');
        for(ll i = 0 ; i < it ; i++){
            s.pb('1');
        }
    }
    s = str + s;
    if(s.size() == 0){
        for(int i = 0 ; i < ones ; i++)s += "1";
        for(int i = 0 ; i < zero ; i++)s += "0";
        if(s.size() == 0)s += "0";

        cout << s << "\n";
    }
    else
    cout << s << "\n";
}
signed main(){
	ll t = 1;
	// cin >> t;
	while(t--){
		solve();
	}
}