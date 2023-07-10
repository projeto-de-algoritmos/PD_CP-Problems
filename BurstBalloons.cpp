class Solution
{
public:
    int maxCoins(vector<int> &nums)
    {
        int numCount = nums.size();
        vector<int> extendedNums(numCount + 2);
        extendedNums[0] = 1;
        extendedNums[numCount + 1] = 1;
        for (int i = 1; i <= numCount; i++)
        {
            extendedNums[i] = nums[i - 1];
        }

        vector<vector<int>> dp(numCount + 2, vector<int>(numCount + 2, 0));
        for (int len = 1; len <= numCount; len++)
        {
            for (int left = 1; left <= numCount - len + 1; left++)
            {
                int right = left + len - 1;
                for (int i = left; i <= right; i++)
                {
                    int currentCoins = extendedNums[left - 1] * extendedNums[i] * extendedNums[right + 1] +
                                       dp[left][i - 1] + dp[i + 1][right];
                    dp[left][right] = max(dp[left][right], currentCoins);
                }
            }
        }
        return dp[1][numCount];
    }
};
