/*
 * author : cladzen
 */
#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define pf push_front
#define mp make_pair
#define vi vector<int>
#define vs vector<string>
#define vc vector<char>
#define vll vector<long long int>
#define mii map<int, int>
#define nline "\n"
#define MOD 1000000007
using namespace std;

int bin(int a, int b, int m) {
    if (b==0) return 1;
    int res = 1;
    while (b) {
        if (b&1) res = ((res%m)*(a%m))%m;
        a = ((a%m)*(a%m))%m;
        b>>=1;
    }
    return res;
}

bool fermatTest(int n, int iter=5) {
    for (int i=0; i<iter; i++) {
        int a = 2 + rand()%(n-3);
        if (bin(a, n-1, n)!=1) return false; // certain
    }
    return true; // probable 99.9999%
}

void solve() {
    cout << fermatTest(13) << nline;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("Input.txt", "r", stdin);
        freopen("Output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // your code goes here
    int t; t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
