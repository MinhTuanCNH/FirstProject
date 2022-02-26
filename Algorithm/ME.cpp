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

matrix multi(matrix a, matrix b){
	matrix c(a.row(), b.col());
	for(int i = 0; i < a.row(); i++){
		for(int j = 0; j < b.col(); j++){
			c[i][j] = 0;
			for(int k = 0; k < a.col(); k++){
				c[i][j] += (a[i][k] * b[k][j]) % 10;
			}
		}
	}
	return c;
}

matrix sum(matrix a, matrix b){
	matrix c(a.row(), b.col());
	for(int i = 0; i < a.row(); i++){
		for(int j = 0; j < b.col(); j++){
			c[i][j] = (a[i][j] + b[i][j]) % 10;
		}
	}
	return c;
}

matrix pow(matrix a, int n){
	if(n == 1) return a;
	matrix s = pow(a, n/2);
	if(n & 1) return multi(multi(s, s), a);
	return multi(s, s);
}

matrix pow1(matrix a, int n){
	if(n == 1) return a;
	matrix s = pow1(a, n/2);
	if(n & 1) return sum(sum(multi(s, pow(a, n/2)), s), pow(a, n));
	return sum(s, multi(s, pow(a, n/2)));
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k; cin >> n >> k;
    matrix a(n, n);
    
    for(int i = 0; i < n; i++)
    	for(int j = 0; j < n; j++)
    		cin >> a[i][j];
    		
    matrix chill = pow1(a, k);
    for(int i = 0; i < chill.row(); i++){
    	for(int j = 0; j < chill.col(); j++){
    		cout << chill[i][j] % 10 << ' ';
    	}
    	cout << '\n';
    }	
    return 0;
}
