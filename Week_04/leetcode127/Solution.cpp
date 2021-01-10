
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (beginWord.empty() || endWord.empty() || wordList.empty())   return 0;
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.count(endWord) == 0)    return 0;
        wordSet.erase(beginWord);
        queue<string> q;
        q.push(beginWord);
        unordered_set<string> visited;
        visited.insert(beginWord);
        int count = 1;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                string cur = q.front();
                q.pop();
                for (int j =0; j < cur.length(); j++) {
                    char originalChar = cur[j];
                    for (char k = 'a'; k <= 'z'; k++) {
                        if (originalChar == k)  continue;
                        cur[j] = k;
                        if (wordSet.count(cur) && visited.count(cur) == 0) {
                            if (cur == endWord) return count + 1;
                            q.push(cur);
                            visited.insert(cur);
                        }
                    }
                    cur[j] = originalChar;
                }
            }
            count++;
        }
        return 0;
    }
};

