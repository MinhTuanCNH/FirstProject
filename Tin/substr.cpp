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

string s;
ll f[1005][1005];

bool check(string res){
	for(int i = 0; i < res.size() / 2; i++) if(res[i] != res[res.size() - i - 1]) return 0;
	return 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    getline(cin, s);
    cin.ignore();
    
    int ans = 0;
    for(int i = 0; i < s.size(); i++){
    	string x = "";
    	for(int j = i; j < s.size(); j++){
    		x += s[j];
    		if(check(x)) ans = max(ans, j - i + 1);
    	}
    }
    
    string t = s;
    reverse(t.begin(), t.end());
    //cout << t << ' ' << s; 
    ll n = t.size();
    t = " " + t;
    s = " " + s;
    f[0][0] = 0;
    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= n; j++){
    		if(s[i] == t[j]) f[i][j] = max(f[i-1][j-1] + 1, 1ll);
    		else f[i][j] = max(f[i-1][j], f[i][j-1]);
    	}
    }
    
    cout << ans << '\n' << f[n][n];
    return 0;
}

// tuntun
