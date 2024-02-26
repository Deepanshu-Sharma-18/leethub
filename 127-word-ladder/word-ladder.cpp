class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        queue<pair<string,int>> q;

        q.push({beginWord,1});
        st.erase(beginWord);

        while(!q.empty()){
            auto s = q.front();
            q.pop();
        
            string word = s.first;
            if(word == endWord) return s.second;

            for(int i = 0;i<word.size();i++){
                char og = word[i];
                for(char ch='a' ; ch <= 'z' ; ch++){
                    word[i] = ch;
                    if(st.find(word) != st.end()){
                        st.erase({word});
                        q.push({word , s.second + 1});
                    }
                }
                word[i] = og;
            }
        }

        return 0;
    }
};