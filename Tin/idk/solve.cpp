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

ll n, ans = inf;
ll d, x, y, num;

void solve(ll a, ll b, ll c){
	x = y = num = -inf;
	d = (b * b) - 4 * a * c;
    if(a != 0){
    	if(d > 0){
    		num = 2;
    		x = (- b - sqrt(d)) / (2 * a);
    		y = (- b + sqrt(d)) / (2 * a);
    	}
    	if(d == 0){
    		num = 1;
    		x = (- b) / (2 * a);
    	}
    	if(d < 0) num = 0;
    }
    else{
    	if(b == 0){
    		if(c == 0) num = inf;
    		else num = 0;
    	}
    	else{
    		num = 1;
    		x = (- c) / b;
    	}
    }
}

bool check(ll i, ll x){
	if(x * x + i * x - n == 0) return 1;
	return 0;
}

int sum(ll x){
	int res = 0;
	while(x > 0){
		res += x % 10;
		x /= 10;
	}
	return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i < 162; i++){
    	solve(1, i, -n);
    	if(num == 0) continue;
    	if(num == 1){
    		if(check(i, x) && sum(x) == i) ans = min(ans, x);
    	}
    	if(num == 2){
    		if(check(i, x) && sum(x) == i) ans = min(ans, x);
    		if(check(i, y) && sum(y) == i) ans = min(ans, y);
    	}
    	if(num == inf){
    		ll tun = 0, j = i;
    		while(j > 9){
    			tun = tun * 10 + 9;
    			j -= 9;
    		}
    		if(j > 0) tun = tun * 10 + j;
    		ans = min(ans, tun);
    	}
    }
    if(ans == inf) cout << -1;
    else cout << ans;
    return 0;
}

// tuntun
