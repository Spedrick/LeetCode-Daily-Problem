const int mod=1e9+7;
class Solution {
    int f(int n, int x0, int x1, vector<int>& dp){
        if (dp[n] != -1) return dp[n];
        long long ans;

        if (n <= x0) ans=1;
        if ( n >= x0) ans += f(n-x0, x0, x1, dp);
        if ( n >= x1) ans += f(n-x1, x0, x1, dp);
        
        return dp[n] = ans % mod;
    }
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        if(zero > one) swap(zero, one);
        vector<int> dp(high+1, -1);
        return (f(high, zero, one, dp) - f(low-1, zero, one, dp) + mod) % mod;
    }
};