#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> computePrefixFunction(const string &pattern)
{
    int m = pattern.length();
    vector<int> prefix(m, 0);
    int k = 0;
    for (int q = 1; q < m; q++)
    {
        while (k > 0 && pattern[q] != pattern[k])
            k = prefix[k - 1];
        if (pattern[q] == pattern[k])
            k++;
        prefix[q] = k;
    }
    return prefix;
}

vector<int> kmpMatcher(const string &text, const string &pattern)
{
    int n = text.length();
    int m = pattern.length();
    vector<int> prefix = computePrefixFunction(pattern);
    vector<int> matchPositions;
    int q = 0;
    for (int i = 0; i < n; i++)
    {
        while (q > 0 && text[i] != pattern[q])
            q = prefix[q - 1];
        if (text[i] == pattern[q])
            q++;
        if (q == m)
        {
            matchPositions.push_back(i - m + 1);
            q = prefix[q - 1];
        }
    }
    return matchPositions;
}

int main()
{
    std::string text = "ABABDABACDABABCABAB";
    std::string pattern = "ABABCABAB";

    std::vector<int> matchPositions = kmpMatcher(text, pattern);

    std::cout << "Pattern found at positions: ";
    for (int pos : matchPositions)
    {
        std::cout << pos << " ";
    }
    std::cout << std::endl;

    return 0;
}