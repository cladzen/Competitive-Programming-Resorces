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

bool wildcardPatternMatching(string pattern, string str) {
    int n = pattern.size();
    int m = str.size();
    bool dp[n+1][m+1];

    // dp initialization
    for (int i=0; i<n+1; i++) {
        for (int j=0; j<m+1; j++) {
            if (i==0 and j==0) dp[i][j] = true;
            else if (i==0) dp[i][j] = false;
            else if (j==0 and pattern[i-1]=='*') dp[i][j] = dp[i-1][j];
            else if (j==0) dp[i][j] = false;
        }
    }

    // dynamic programming top down approach
    for (int i=1; i<n+1; i++) {
        for (int j=1; j<m+1; j++) {
            if (pattern[i-1]==str[j-1]) 
                dp[i][j] = dp[i-1][j-1];
            else if (pattern[i-1]=='?') 
                dp[i][j] = dp[i-1][j-1];
            else if (pattern[i-1]=='*') 
                dp[i][j] = dp[i-1][j] || dp[i][j-1];
            else dp[i][j] = false;
        }
    }
    // return
    return dp[n][m];
}

void solve(int t) {
    string pattern, str; cin >> pattern >> str;
    cout << wildcardPatternMatching(pattern, str) << nline;
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
