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

int gcdextended(int a, int b, int& x, int& y) {
    if (b==0) {
        x = 1;
        y = 0;
        return a;
    }
    int g = gcdextended(b, a%b, x, y);
    int tmp = x;
    x = y;
    y = tmp - y*(a/b);
    return g;
}

bool diophantine(int a, int b, int c, int& x, int& y, int& g) {
    g = gcdextended(abs(a), abs(b), x, y);
    if (c%g) return false;
    x = x*(c/g);
    y = y*(c/g);
    if (a<0) x = -x;
    if (b<0) y = -y;
    return true;
}

void solve() {
    int x, y, g;
    cout << diophantine(30, 75, 120, x, y, g) << " " << x << " " << y << " " << g << nline;
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
