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

int phi(int n) {
    // euler's totient function 
    int temp = n;
    int result = n;
    for (int i=2; i*i<=n; i++) {
        if (temp%i==0) {
            result -= result/i;
            while (temp%i==0) {
                temp /= i;
            }
        }
    }
    if (temp>1) {
        result -= result/temp;
    }
    return result;
}

void solve() {
    cout << phi(10) << nline;
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
