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

// longest common subsequence using recursion
int lcs(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();
    // when any of the strings are empty
    if (n==0 or m==0) return 0;
    // if the values are equal
    if (s1[n-1]==s2[m-1]) 
        return 1 + lcs(s1.substr(0, n-1), s2.substr(0, m-1));
    // if the values are not equal
    else 
        return max(lcs(s1.substr(0, n-1), s2.substr(0, m)), lcs(s1.substr(0, n), s2.substr(0, m-1)));
}

// longest common subsequence using dynammic programming 
int lcsDP(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();
    // this will store the length of the longest subsequence 
    // among different length of strings
    int dp[n+1][m+1];
    // bottom up approach
    for (int i=0; i<=n; i++) {
        for (int j=0; j<=m; j++) {
            if (i==0 or j==0) dp[i][j] = 0;
            else if (s1[i-1]==s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][m];
}

void solve(int t) {
    string s1 = "alanvalan";
    string s2 = "lavalan";
    cout << lcsDP(s1, s2) << nline;
    return;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("Input.txt", "r", stdin);
        freopen("Output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // your code goes here
    int t = 1;
    while (t--) {
        solve(t);
    }
    return 0;
}
