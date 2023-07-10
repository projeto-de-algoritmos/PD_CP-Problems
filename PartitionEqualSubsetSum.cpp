class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int n = nums.size();
        int totalSum = 0;

        for (int num : nums)
        {
            totalSum += num;
        }

        if (totalSum % 2 != 0)
        {
            return false;
        }

        int targetSum = totalSum / 2;
        vector<bool> M(targetSum + 1, false);
        M[0] = true;

        for (int i = 0; i < n; i++)
        {
            for (int j = targetSum; j >= nums[i]; j--)
            {
                M[j] = M[j] || M[j - nums[i]];
            }
        }

        return M[targetSum];
    }
};