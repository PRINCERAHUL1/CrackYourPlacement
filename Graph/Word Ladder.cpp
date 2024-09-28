class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> set(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;

        q.push({beginWord, 1});

        while(!q.empty())
        {
            pair<string, int> p= q.front();
            string word = p.first;
            int ladder= p.second;
            q.pop();

            if(word == endWord)
                return ladder;
            
            set.erase(word);

            for(int i=0; i<word.size(); i++)
            {
                char c= word[i];
                for(int j=0; j<26; j++)
                {
                    word[i] = 'a' + j;

                    if(set.find(word) != set.end())
                        q.push({word, ladder+1});
                }

                word[i] = c;
            }
        }

        return 0;
    }
};
