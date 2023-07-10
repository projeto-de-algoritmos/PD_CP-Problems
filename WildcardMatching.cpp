class Solution
{
public:
    bool isMatch(const string &s, const string &p)
    {
        vector<vector<int>> dp(s.length() + 1, vector<int>(p.length() + 1, -1)); // memo
        return match(0, 0, s, p, dp) == 1;
    }

    int match(int i, int j, const string &s, const string &p, vector<vector<int>> &dp)
    {
        if (dp[i][j] != -1)
            return dp[i][j];

        if (i == s.length() && j == p.length())
            return dp[i][j] = 1;

        if (j == p.length())
        {
            return dp[i][j] = 0;
        }

        if (i == s.length())
        {
            for (int k = j; k < p.length(); k++)
            {
                if (p[k] != '*')
                    return dp[i][j] = 0;
            }
            return dp[i][j] = 1;
        }

        if (s[i] == p[j] || p[j] == '?')
            return dp[i][j] = match(i + 1, j + 1, s, p, dp);

        if (p[j] == '*')
        {
            return dp[i][j] = match(i + 1, j, s, p, dp) || match(i, j + 1, s, p, dp);
        }

        return dp[i][j] = 0;
    }
};