#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int knapSackR (int W, int wt[], int val[], int n) { 
    if (n == 0 || W <= 0)
        return 0;
        
    if (dp[n][W] != -1)
        return dp[n][W];
        
    if (wt[n - 1] <= W)
        dp[n][W] = max ((val[n - 1] + knapSackR (W - wt[n - 1], wt, val, n - 1)), knapSackR (W, wt, val, n - 1));
    else
        dp[n][W] = knapSackR (W, wt, val, n - 1);
    
    return dp[n][W];
}

int knapSack (int W, int wt[], int val[], int n) {
    memset (dp, -1, sizeof(dp));
    knapSackR (W, wt, val, n);
}


int main()
 {
    int t;
    cin >> t;
    while(t--)
    {
        int n, w;
        cin >> n >> w;
        
        int val[n];
        int wt[n];
        
        for(int i = 0; i < n; i++)
            cin >> val[i];
        
        for(int i = 0; i < n; i++)
            cin >> wt[i];
        
        cout << knapSack (w, wt, val, n) <<endl;
    }
	return 0;
}