class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    
        set<string> words;
        for(auto & word : wordList){
            words.insert(word);
        }

        if(!words.count(endWord)) return 0;


        int cnt=1;
        queue<string> q;
        q.push(beginWord);

        while(!q.empty()){
            int size= q.size();
            for(int a=0; a<size; a++){

                auto curr=q.front();
                q.pop();

                for(int i=0; i<curr.size(); i++){
                    for(char ch='a'; ch<='z'; ch++){

                        if(ch==curr[i]) continue;

                        string newword=curr;
                        newword[i]=ch;

                        if (newword==endWord) return cnt+1;

                        if (words.count(newword)){
                            q.push(newword);
                            words.erase(newword);
                        }
                    }
                }
            }
            cnt++;
        }
        return 0;
    }
};