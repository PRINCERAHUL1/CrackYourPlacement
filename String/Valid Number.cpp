class Solution {
public:
    bool isNumber(string s) {
        int n = s.length();
        bool num = false;
        bool exp = false;
        bool dot = false;
        
        for (int i = 0; i < n; i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
                num = true;
            else if (s[i] == 'e' || s[i] == 'E')
            {
                if (exp || !num)
                    return false;
                exp = true;
                num = false;    
                dot = true;
            }
            else if (s[i] == '.')
            {
                if (dot || exp)
                    return false;
                dot = true;
            }
            else if (s[i] == '+' || s[i] == '-')
            {
                if (i != 0 && s[i - 1] != 'e' && s[i - 1] != 'E')
                    return false;
                if (i == n - 1)
                    return false;
            }
            else 
                return false;
        }

        return num;
    }
};

