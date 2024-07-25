#include <iostream>
#include <vector>
#include <string>

// 构建前缀表（next数组）
std::vector<int> computePrefixFunction(const std::string &pattern)
{
    int m = pattern.length();
    std::vector<int> prefix(m, 0);
    int k = 0;

    for (int q = 1; q < m; ++q)
    {
        while (k > 0 && pattern[k] != pattern[q])
        {
            k = prefix[k - 1];
        }
        if (pattern[k] == pattern[q])
        {
            ++k;
        }
        prefix[q] = k;
    }

    return prefix;
}

// KMP字符串匹配算法
std::vector<int> kmpMatcher(const std::string &text, const std::string &pattern)
{
    int n = text.length();
    int m = pattern.length();
    std::vector<int> prefix = computePrefixFunction(pattern);
    std::vector<int> matchPositions; // 用来存储匹配的起始位置
    int q = 0;                       // 用来记录模式字符串的当前匹配长度

    for (int i = 0; i < n; ++i)
    {
        // 内层循环处理字符不匹配的情况，通过前缀表来调整q的值
        while (q > 0 && pattern[q] != text[i])
        {
            q = prefix[q - 1];
        }
        // 如果当前字符匹配，则递增q。
        if (pattern[q] == text[i])
        {
            ++q;
        }
        // 如果q等于模式字符串的长度，找到了完整的匹配
        // 将起始位置添加到向量
        // 继续查找
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
