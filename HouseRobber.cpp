class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        vector<int> M(nums.size() + 1);
        M[0] = 0;
        M[1] = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            M[i + 1] = max(M[i], M[i - 1] + nums[i]);
        }
        return M[nums.size()];
    }
};