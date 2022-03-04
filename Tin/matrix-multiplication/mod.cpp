#include <bits/stdc++.h>

#define int int64_t
#define fi first
#define se second

#define vi vector<int>
#define vll vector<long long>
#define sz(s) int(s.size())

const long long mod = 1e9 + 7;
const long long inf = 1e18 - 1;
const int MaxN = 1e2 + 5;
const int sum = 40000;

using namespace std;

struct matrix{
	vector< vector<int> > res;
	
	auto & operator [] (int i) { 
		return res[i]; 
	}
	
	matrix(const vector <vector <int> > &d): res(d) { }
	
	int row() const {
		return res.size();
	}
	
	int col() const {
		return res[0].size();
	}
	
	matrix(int r, int c) : res(r, vector<int> (c)) {}
	
	
};

int t, x, n, m;

int calc(int a, int b) {
    if(b <= 1) {
        return (!b) ? 0 : a;
    }

    int s = calc(a, b / 2);
    return (b % 2) ? (s + s + a) % m : (s + s) % m;
}

matrix multi(matrix a, matrix b){
	matrix c(a.row(), b.col());
	for(int i = 0; i < a.row(); i++){
		for(int j = 0; j < b.col(); j++){
			c[i][j] = 0;
			for(int k = 0; k < a.col(); k++){
				c[i][j] += calc(a[i][k] , b[k][j]) % m;
			}
		}
	}
	return c;
}

matrix pow(matrix a, int val){
	if(val == 1) return a;
	matrix s = pow(a, val/2);
	if(val & 1) return multi(multi(s, s), a);
	return multi(s, s);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> t;
    while(t--){
    	cin >> x >> n >> m;
    	string s = to_string(x);
    	int p = 1, q = x % m;
    	for(int i = 1; i <= sz(s); i++) p *= 10, p %= m;
    	//cout << p << ' ' << q << '\n';
    	matrix M({{p, 0}, {q, 1}});
    	matrix AC({{q, 1}});
    	matrix gg = multi(AC, pow(M, n - 1));
    	/*for(int i = 0; i < gg.row(); i++){
    		for(int j = 0; j < gg.col(); j++) cout << gg[i][j] % m << ' ';
    		cout << '\n';
    	}
    	//cout << '\n';*/
    	cout << gg[0][0] % m << '\n';
    }
    
    return 0;
}

//answer : 838211797110
