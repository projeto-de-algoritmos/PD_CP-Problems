class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> L(n, 1);

        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i <= j - 1; i++)
            {
                if (nums[i] < nums[j])
                {
                    L[j] = max(L[j], L[i] + 1);
                }
            }
        }

        int maxLen = *max_element(L.begin(), L.end());

        return maxLen;
    }
};