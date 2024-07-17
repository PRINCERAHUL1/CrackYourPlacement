class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.length();
        int n = needle.length();
        for(int i=0; i<m;i++)
        {
            int k=i;
            int c=0;
            for(int j=0; j<n; j++)
            {

                if(haystack[k] == needle[j])
                {
                    ++c;
                    k++;
                }
            }
            if(c == n)
                return i;
        }
        return -1;
    }
};
