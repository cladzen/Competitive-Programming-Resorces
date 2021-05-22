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

int binR(int base, int power) {
    if (power==0) return 1;
    int res = binR(base, power/2);
    if (power%2==1) return base*res*res;
    return res*res;
}

int binI(int base, int power) {
    int res = 1;
    while (power>0) {
        if (power&1) res = res*base;
        base = base*base;
        power>>=1;
    }
    return res;
}
void solve() {
    cout << binR(3, 3) << " " << binI(4, 3) << nline;
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
