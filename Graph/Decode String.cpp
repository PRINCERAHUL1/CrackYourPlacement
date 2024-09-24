class Solution {
public:
    string decodeString(string s) {
        stack<int> num;
        stack<string> st;
        string res = "";
        string temp = "";
        int m = 0;

        for(int i=0; i<s.size(); i++)
        {
            if(s[i] >= '0' && s[i] <= '9')
                m = m*10 + (s[i] - '0');
            else if(s[i] == '[')
            {
                st.push(res);
                num.push(m);
                m=0;
                res = "";
            }
            else if(s[i] == ']')
            {
                temp = res;
                
                for(int j=1; j<num.top(); j++)
                    res = res + temp;
                
                num.pop();
                res = st.top() + res;
                st.pop();
            }
            else
                res.push_back(s[i]);
        }

        return res;
    }
};
