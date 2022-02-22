#include "headers.h"

class Solution
{
public:
    int romanToInt(string s)
    {
        int result = 0;

        int i = 0;
        while (i < s.size())
        {
            switch (s[i])
            {
            case 'V':
                if (i != 0 && s[i - 1] == 'I')
                    result += 3;
                else
                    result += 5;
                break;
            case 'X':
                if (i != 0 && s[i - 1] == 'I')
                    result += 8;
                else
                    result += 10;
                break;
            case 'L':
                if (i != 0 && s[i - 1] == 'X')
                    result += 30;
                else
                    result += 50;
                break;
            case 'C':
                if (i != 0 && s[i - 1] == 'X')
                    result += 80;
                else
                    result += 100;
                break;
            case 'D':
                if (i != 0 && s[i - 1] == 'C')
                    result += 300;
                else
                    result += 500;
                break;
            case 'M':
                if (i != 0 && s[i - 1] == 'C')
                    result += 800;
                else
                    result += 1000;
                break;

            default:
                result += 1;
                break;
            }
            i++;
        }

        return result;
    }
};

TEST(RomanToInt, RomanToInt_1)
{
    Solution s;
    string in = "MCMXCIV";
    int ans = 1994;
    EXPECT_EQ(s.romanToInt(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}