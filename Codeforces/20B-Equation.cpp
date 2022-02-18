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

long double a, b, c, d;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b >> c;
    d = (b * b) - 4 * a * c;
    if(a != 0){
    	if(d > 0){
    		cout << 2 << '\n';
    		long double x, y;
    		x = (- b - sqrt(d)) / (2 * a);
    		y = (- b + sqrt(d)) / (2 * a);
    		cout << fixed << setprecision(9) << min(x, y) << '\n' << max(x, y);
    	}
    	if(d == 0){
    		cout << 1 << '\n';
    		cout << fixed << setprecision(9) << (- b) / (2 * a);
    	}
    	if(d < 0) cout << 0;
    }
    else{
    	if(b == 0){
    		if(c == 0) cout << -1;
    		else cout << 0;
    	}
    	else{
    		cout << 1 << '\n';
    		cout << fixed << setprecision(9) << (- c) / b;
    	}
    }
    return 0;
}

// tuntun
