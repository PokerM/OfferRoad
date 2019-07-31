class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> mem(n, vector<int>(n, 0));
        return longestPalindromeSubseq(0, s.size()-1, s, mem);
    }
    int longestPalindromeSubseq(int l, int r, string& s, vector<vector<int>>& mem){
        if(l>r)return 0;
        if(l==r)return 1;
        if(mem[l][r])return mem[l][r];
        return mem[l][r]=(s[l]==s[r]?2 + longestPalindromeSubseq(l+1, r-1, s, mem) : max(longestPalindromeSubseq(l+1, r, s, mem), longestPalindromeSubseq(l, r-1, s, mem)));
    }
};

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if(s.size()<2)return s.size();
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n, 0));
        for(int i=0;i<n;i++)dp[1][i] = 1;
        for(int i=2;i<=n;i++){//length
            for(int j=0;j<n-i+1;j++){//start index
                dp[i][j] = s[j] == s[j+i-1]?2 + dp[i-2][j+1] : max(dp[i-1][j], dp[i-1][j+1]);
            }
        }
        return dp[n][0];
    }
};

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if(s.size()<2)return s.size();
        int n = s.size();
        //vector<vector<int>> dp(n+1, vector<int>(n, 0));
        vector<int> v0(n, 0), v1(n, 1), v2(n, 0);
        
        for(int i=2;i<=n;i++){//length
            for(int j=0;j<n-i+1;j++){
                //dp[i][j] = s[j] == s[j+i-1]?2 + dp[i-2][j+1] : max(dp[i-1][j], dp[i-1][j+1]);
                v2[j] = s[j]==s[j+i-1]?2 + v0[j+1] : max(v1[j], v1[j+1]);
            }
            swap(v1, v2);
            swap(v0, v2);
        }
        return v1[0];
    }
};