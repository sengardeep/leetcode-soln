class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //We'll apply BFS as we'll start from beginWord and go for every position and go for every word and check if it exists in wordList

        if(find(wordList.begin(),wordList.end(),endWord)==wordList.end()) return 0;
        int ans=1;
        queue<string> q;
        set<string> list;
        //We'll use set instead of visited array or map because in set we'll see a word and delete it 
        for(auto it : wordList) list.insert(it);
        q.push(beginWord);
        while(!q.empty())
        {
            int size=q.size();
            ans++;
            while(size--)
            {
            string word=q.front();
            q.pop();
            // visited[word]=true;
            for(int i=0;i<word.length();i++)
            {
                string copy=word;
                for(int j=0;j<26;j++)
                {
                    copy[i]=(char)('a'+j);

                    if(copy==endWord) return ans;
                    if(list.contains(copy))
                    {
                        q.push(copy);
                        list.erase(copy);
                    }
                }
            }
            }
        }

        return 0;

    }
};