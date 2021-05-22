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

int mod_mulI(int a, int b) {
    int res = 0;
    a = a%MOD;
    while (b) {
        if (b&1) res = (res+a)%MOD;
        a = (2*a)%MOD;
        b>>=1;
    }
    return res;
}
int mod_mulR(int a, int b) {
    if (b==0) return 0;
    int res = mod_mulR(a, b/2)%MOD;
    if (b%2==1) return (a%MOD) + ((2*res)%MOD);
    return (2*res)%MOD;
}
void solve() {
    int x, y;
    cout << mod_mulI(4, 5) << " " << mod_mulR(4, 5) << nline;
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
