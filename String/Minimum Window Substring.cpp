class Solution {
public:
    string minWindow(string s, string t) {
        int m=s.size();
        int n= t.size();
        vector<int>v1(256,0);
        vector<int>v2(256,0);

        int count = 0;
        int start=-1;
        int len=INT_MAX;

        for(auto k:t)
            v1[k]++;
        
        int i=0;
        int j=0;

        while(j<m)
        {
            v2[s[j]]++;

            if(v2[s[j]] <= v1[s[j]])
                count++;
            
            if(count == n)
            {
                while(v2[s[i]] > v1[s[i]] || v1[s[i]] == 0)
                {
                    if(v2[s[i]] > v1[s[i]])
                        v2[s[i]]--;
                    
                    i++;
                }

                if(len > j-i+1)
                {
                    len = j-i+1;
                    start = i;
                }
            }

            j++;
        }
    
    if(start == -1)
        return "";
    
    return s.substr(start,len);
    }
};
