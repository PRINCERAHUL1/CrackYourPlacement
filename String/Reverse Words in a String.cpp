class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string r = "";
        string w = "";
        for(int i=0;i<n;i++)
        {
            if(s[i] != ' ')
            {
                w = w + s[i];
            }
            else
            {
                if(!w.empty())
                {
                    if(r.length()==0)
                        r=w;
                    else
                    {
                        r = w + " " + r;
                    }
                    w ="";
                }
            }
        }

         if (!w.empty()) {
            if (!r.empty()) {
                r = w + " " + r;
            } else {
                r = w;
            }
        }

        return r;
    }
};
