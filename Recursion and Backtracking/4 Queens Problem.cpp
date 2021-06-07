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

// Basic 4 queen's problem
// 4x4 grid can be represented using a 1 D array
int grid[4];
bool rowAttack[4] = {0};
bool columnAttack[4] = {0};
bool check(int row, int column) {
    // checks if a queen can be placed at the given position
    if (rowAttack[row] or columnAttack[column]) return false;
    else return true;
}

bool queens(int row) {
    if (row==4) return true;
    for (int column=0; column<4; column++) {
        if (check(row, column)) {
            grid[row] = column;
            rowAttack[row] = true;
            columnAttack[column] = true;
            if (queens(row+1)) return true;
            grid[row] = -1;
            rowAttack[row] = false;
            columnAttack[column] = false;
        }
        else continue;
    }
    return false;
}

void solve(int t) {
    memset(grid, -1, sizeof(grid));
    bool ans = queens(0);
    cout << ans << nline;
    for (auto column : grid) cout << column << nline;
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
