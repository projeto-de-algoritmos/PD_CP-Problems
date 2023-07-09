class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int numCount = nums.size();
        int totalSum = target + accumulate(nums.begin(), nums.end(), 0);
        if (totalSum < 0)
        {
            return 0;
        }
        int i = 0;
        while (i < numCount)
        {
            nums[i] = 2 * nums[i];
            i++;
        }
        vector<vector<int>> dp(numCount + 1, vector<int>(totalSum + 1, 0));
        dp[0][0] = 1;
        int j = 1;
        while (j <= numCount)
        {
            int k = 0;
            while (k <= totalSum)
            {
                dp[j][k] = dp[j - 1][k];
                if (k >= nums[j - 1])
                {
                    dp[j][k] += dp[j - 1][k - nums[j - 1]];
                }
                k++;
            }
            j++;
        }
        return dp[numCount][totalSum];
    }
};
