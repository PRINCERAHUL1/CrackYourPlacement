class Solution {
public:
    int calculate(string s) {
        int c = 0;
        char op = '+';
        int sum = 0;
        int last = 0;
        int n = s.length();

        for (int i = 0; i < n; ++i) {
            if (isdigit(s[i])) {
                c = c * 10 + (s[i] - '0');
            }

            if ((!isdigit(s[i]) && s[i] != ' ') || i == n - 1) {
                switch (op) {
                    case '+':
                        sum += last;
                        last = c;
                        break;
                    case '-':
                        sum += last;
                        last = -c;
                        break;
                    case '*':
                        last = last * c;
                        break;
                    case '/':
                        last = last / c;
                        break;
                }
                op = s[i];
                c = 0;
            }
        }
        sum += last;

        return sum;
    }
};
