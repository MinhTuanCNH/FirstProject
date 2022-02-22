#include <bits/stdc++.h>

#define ll long long
#define fi first
#define se second

#define vi vector<int>
#define vll vector<long long>
#define sz(s) int(s.size())

const long long mod = 1e9 + 7;
const long long inf = 1e18 - 1;
const int MaxN = 2e5 + 5;
const int sum = 40000;

using namespace std;

ll n;
string s;

bool check_num(char c){
	if(c >= '0' && c <= '9') return 1;
	return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for(int tun = 1; tun <= n; tun++){
    	cin >> s;
    	vector<char> a[1108];
    	int j = 0;
    	a[j].push_back(s[0]);
    	for(int i = 1; i < sz(s); i++){
    		if(check_num(s[i]) != check_num(s[i - 1])) j++;
    		a[j].push_back(s[i]);
    	}
    	if(j == 1){
    		cout << "R";
    		ll res = 0;
    		for(int i = 0; i < sz(a[1]); i++) res = res * 10 + (a[1][i] - '0');
    		cout << res << "C";
    		res = 0;
    		for(int i = 0; i < sz(a[0]); i++) res = res * 26 + (a[0][i] - 'A' + 1);
    		cout << res << '\n';
    	}
    	else{
    		ll res = 0;
    		for(int i = 0; i < sz(a[3]); i++) res = res * 10 + (a[3][i] - '0');
    		string ac = "";
    		//cout << res << '\n';
    		while(res > 0){
    			if(res % 26 != 0) ac += char((res % 26) + 'A' - 1), res /= 26;
    			else if(res % 26 == 0) ac += char(26 + 'A' - 1), res = res / 26 - 1;
    			//cout << res % 26 << ' ';
    		}
    		reverse(ac.begin(), ac.end());
    		cout << ac;
    		for(int i = 0; i < sz(a[1]); i++) cout << a[1][i];
    		cout << '\n';
    	}
    }
    
    return 0;
}

// tuntun
