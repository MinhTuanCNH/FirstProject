#include <bits/stdc++.h>
#define ll long long
#define FOR(i,a,b) for(ll i=a; i<=b; i++)
#define FOD(i,a,b) for(ll i=a; i>=b; i--)
#define For(x,m) for(auto x: m)
#define size(s) int(s.size())
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define vll vector<long long>

const long long mod = 1e9 + 7;
const long long inf = 1e18 - 1;

using namespace std;

pair<ll, ll> a[3], b[3];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    FOR(i,0,2){
        cin >> a[i].fi >> a[i].se;
        b[i].fi = a[i].se, b[i].se = a[i].fi;
    }
    sort(a, a + 3); sort(b, b + 3);
    if(a[0].fi == a[1].fi && a[1].fi == a[2].fi) cout << b[2].fi - b[0].fi + 1;
    else if(a[0].fi == a[1].fi) cout << b[2].fi - b[0].fi + 1 + a[2].fi - a[1].fi;
    else if(a[2].fi == a[1].fi) cout << b[2].fi - b[0].fi + 1 + a[2].fi - a[0].fi;
    else if(b[0].fi == b[1].fi && b[1].fi == b[2].fi) cout << a[2].fi - a[0].fi + 1;
    else if(b[0].fi == b[1].fi) cout << a[2].fi - a[0].fi + 1 + b[2].fi - b[1].fi;
    else if(b[2].fi == b[1].fi) cout << a[2].fi - a[0].fi + 1 + b[2].fi - b[0].fi;
    else{
    	cout << b[2].fi - b[0].fi + 1 + abs(a[1].fi - a[2].fi) + abs(a[1].fi - a[0].fi);
    }
    cout << '\n';
    for(int i = b[2].fi; i >= b[0].fi; i--){
    	cout << a[1].fi << ' ' << i << '\n';
    }
    for(int i = a[0].fi; i < a[1].fi; i++){
    	cout << i << ' ' << a[0].se << '\n';
    }
    for(int i = a[2].fi; i > a[1].fi; i--){
    	cout << i << ' ' << a[2].se << '\n';
    }
    return 0;
}
