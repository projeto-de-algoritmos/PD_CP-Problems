class Solution
{
public:
    int longestValidParentheses(std::string s)
    {
        std::stack<int> openIndices;                       // stack que armazena o index da abertura de parenteses
        std::vector<int> maxLengthEndingAt(s.length(), 0); // array DP c comprimento maximo de parenteses validos

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                openIndices.push(i);
            }
            else
            {
                if (openIndices.empty()) // verifica se ta vazio
                {
                    continue;
                }
                int leftIndex = openIndices.top();
                openIndices.pop();
                int rightIndex = i;
                int currentLength = rightIndex - leftIndex + 1;

                // update no array DP c o maxlenght de parenteses validos terminando no index, fznd a verificação caso seja index 0
                if (leftIndex > 0)
                {
                    maxLengthEndingAt[rightIndex] = maxLengthEndingAt[leftIndex - 1] + currentLength;
                }
                else
                {
                    maxLengthEndingAt[rightIndex] = currentLength;
                }
            }
        }

        if (maxLengthEndingAt.empty())
        {
            return 0;
        }

        return *std::max_element(maxLengthEndingAt.begin(), maxLengthEndingAt.end()); // retorna o maximo global
    }
};