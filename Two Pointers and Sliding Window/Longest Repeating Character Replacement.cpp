class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> map;
        int ans = 0;
        int count = 0;
        int n = s.length();

        for(int i=0; i<n; i++)
        {
            count = max(count, ++map[s[i]]);

            if(ans - count <k)
                ans++;
            else
                map[s[i-ans]]--;
        }

        return ans;
    }
};
