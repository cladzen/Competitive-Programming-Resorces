// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int t[201][201];
    int f[201][201];
    int bp(int i, int j, string S, bool b) {
        if (i>j) return 0;
        if (i==j) {
            if (b) {
                if (S[i]=='T') return 1;
                else return 0;
            }
            else {
                if (S[i]=='F') return 1;
                else return 0;
            }
        }
        int ans = 0;
        if (b==1) {
            if (t[i][j]!=-1) return t[i][j];
            for (int k=i+1; k<j; k+=2) {
                if (S[k]=='|') {
                    ans += (bp(i, k-1, S, true)*bp(k+1, j, S, false));
                    ans += (bp(i, k-1, S, true)*bp(k+1, j, S, true));
                    ans += (bp(i, k-1, S, false)*bp(k+1, j, S, true));
                }
                else if (S[k]=='&') {
                    ans += (bp(i, k-1, S, true)*bp(k+1, j, S, true));
                }
                else if (S[k]=='^') {
                    ans += (bp(i, k-1, S, true)*bp(k+1, j, S, false));
                    ans += (bp(i, k-1, S, false)*bp(k+1, j, S, true));
                }
            }
            t[i][j] = ans;
        }
        else {
            if (f[i][j]!=-1) return f[i][j];
            for (int k=i+1; k<j; k+=2) {
                if (S[k]=='|') {
                    ans += (bp(i, k-1, S, false)*bp(k+1, j, S, false));
                }
                else if (S[k]=='&') {
                    ans += (bp(i, k-1, S, false)*bp(k+1, j, S, true));
                    ans += (bp(i, k-1, S, true)*bp(k+1, j, S, false));
                    ans += (bp(i, k-1, S, false)*bp(k+1, j, S, false));
                }
                else if (S[k]=='^') {
                    ans += (bp(i, k-1, S, true)*bp(k+1, j, S, true));
                    ans += (bp(i, k-1, S, false)*bp(k+1, j, S, false));
                }
            }
            f[i][j] = ans;
        }
        return ans%1003;
    }
    int countWays(int N, string S){
        // code here
        for (int i=0; i<201; i++) {
            for (int j=0; j<201; j++) {
                t[i][j] = -1;
                f[i][j] = -1;
            }
        }
        return bp(0, N-1, S, true);
    }
};

// { Driver Code Starts.

int main(){
    #ifndef ONLINE_JUDGE
        freopen("Input.txt", "r", stdin);
        freopen("Output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
