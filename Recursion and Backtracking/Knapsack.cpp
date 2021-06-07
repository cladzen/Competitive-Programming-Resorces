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

int knapsack(int n, int w, int W[], int V[]) {
    // if number of weights or the knapsack size is zero
    if (n==0 or w==0) return 0;
    // if the weight is greater than the remaining knapsack weight
    if (W[n-1]>w) return knapsack(n-1, w, W, V);
    // here we take the maximum value of if we take the current weight or not
    else 
        return max(knapsack(n-1, w, W, V), V[n-1]+knapsack(n-1, w-W[n-1], W, V)); 
}

int knapsackDP(int n, int w, int W[], int V[]) {
    // dynammic programming approach
    int dp[n+1][w+1];
    for (int i=0; i<=n; i++) {
        for (int j=0; j<=w; j++) {
            if (i==0 or j==0) dp[i][j] = 0;
            else if (W[n-1]<=w) 
                dp[i][j] = max(dp[i-1][j], V[i-1]+dp[i-1][j-W[i-1]]);
            else dp[i][j] = dp[i-1][j-1];
        }
    }
    return dp[n][w];
}

void solve(int t) {
    int W[3] = {10, 20, 30};
    int V[3] = {60, 100, 120};
    int n = sizeof(W)/sizeof(int);
    int w = 50;
    cout << knapsackDP(n, w, W, V) << nline;
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
