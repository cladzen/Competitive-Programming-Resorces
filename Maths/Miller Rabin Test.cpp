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

bool checkComposite(int n, int d, int s, int a) {
    int x = bin(a, d, n);
    if (x==1 or x==n-1) return false;
    for (int i=1; i<s; i++) {
        x = (x*x)%n;
        if (x==n-1) return false;
    }
    return true;
}

bool millerRabinTest(int n, int iter=5) {
    int s = 0;
    int d = n-1; // even
    while (d&1==0) {
        s++;
        d>>=1;
    }
    for (int i=0; i<iter; i++) {
        int a = 2 + rand()%(n-3);
        if (checkComposite(n, d, s, a)) return false;
    }
    return true;
}

void solve() {
    cout << millerRabinTest(13) << nline;
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
