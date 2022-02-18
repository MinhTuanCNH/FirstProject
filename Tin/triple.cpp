#include <bits/stdc++.h>

#define ll long long
#define fi first
#define se second

#define vi vector<int>
#define vll vector<long long>

const long long mod = 1e9 + 7;
const long long inf = 1e18 - 1;
const int MaxN = 1005;

using namespace std;

ll n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    ll f[100005];
    f[1] = 3; f[2] = 8;
    ll res = 2;
    for(int i = 3; i <= n; i++){
    	f[i] = (f[i - 1] * 3 - res + mod) % mod;
    	if(res < 0) res += mod;
    	res = f[i - 1] - (res % mod);
    }
    cout << f[n];
    return 0;
}

// tuntun
