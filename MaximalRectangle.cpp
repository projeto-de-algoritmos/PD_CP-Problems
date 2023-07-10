class Solution
{
public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        if (matrix.empty())
            return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> lb(cols, 0);
        vector<int> rb(cols, cols);
        vector<int> h(cols, 0);
        int maxA = 0;

        int i = 0;
        while (i < rows)
        {
            int clb = 0, crb = cols;
            int j = 0;

            while (j < cols)
            {
                if (matrix[i][j] == '1')
                {
                    h[j] += 1;
                    lb[j] = max(lb[j], clb);
                }
                else
                {
                    h[j] = 0;
                    lb[j] = 0;
                    clb = j + 1;
                }

                j++;
            }

            j = cols - 1;
            while (j >= 0)
            {
                if (matrix[i][j] == '1')
                    rb[j] = min(rb[j], crb);
                else
                {
                    rb[j] = cols;
                    crb = j;
                }

                j--;
            }

            j = 0;
            while (j < cols)
            {
                maxA = max(maxA, h[j] * (rb[j] - lb[j]));
                j++;
            }

            i++;
        }

        return maxA;
    }
};
