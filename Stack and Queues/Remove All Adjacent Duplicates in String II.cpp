class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.size();
        if(n<k)
            return s;
        
        stack<pair<char, int> >  s1;

        for(int i=0; i<n; i++)
        {
            if(s1.empty() || s1.top().first != s[i])
                s1.push({s[i], 1});
            else
            {
                auto pre = s1.top();
                s1.pop();
                s1.push({s[i], pre.second+1});
            }

            if(s1.top().second == k)
                s1.pop();
        }

        string res = "";

        while(!s1.empty())
        {
            auto cur = s1.top();
            s1.pop();

            while(cur.second--)
                res.push_back(cur.first);
        }

        reverse(res.begin(), res.end());

        return res;
    }
};
