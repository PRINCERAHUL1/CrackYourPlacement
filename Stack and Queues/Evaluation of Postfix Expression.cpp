class Solution
{
    public:
    int evaluatePostfix(string S)
    {
        stack<int> stack;
        int n = S.size();
        int ans =0;
        
        for(int i=0; i<n;i++)
        {
            if(S[i] >= '0' && S[i] <= '9')
            {
                stack.push(S[i] - '0');
            }
            else
            {
                int a = stack.top();
                stack.pop();
                int b = stack.top();
                stack.pop();
                
                if(S[i] == '+')
                    ans = b + a;
                else if(S[i] == '-')
                    ans = b - a;
                else if(S[i] == '*')
                    ans = b * a;
                else
                    ans = b / a;
                    
                stack.push(ans);
            }
        }
        return ans;
    }
};
