#include <bits/stdc++.h>
using namespace std;

//GeeksForGeeks solutions doesn't require memoization xD! A recursive solution passes the testcases ;)
class Solution{
public:
    int subsetSum(int n, int sum, int a[]) {
        if (sum == 0)
            return true;
        if (n == 0)
            return false;
            
        if (a[n - 1] > sum)
            return subsetSum (n - 1, sum, a);
        else
            return (subsetSum (n - 1, sum - a[n - 1], a) || subsetSum (n - 1, sum, a));
    }

    int equalPartition(int n, int a[]) {
        int sum = 0;
        for (int i = 0; i < n; i++) sum += a[i];
        
        if (sum % 2 != 0)
            return false;
        
        return subsetSum(n, sum / 2, a);
    }
};

int main(){
    int t;
    cin >> t;
    while (t--){
        int N;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++)
            cin >> arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}