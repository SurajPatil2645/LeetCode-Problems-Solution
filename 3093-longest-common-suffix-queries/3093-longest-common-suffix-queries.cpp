struct TrieNode {
    TrieNode* ch[26];
    int bestIndex;

    TrieNode() {
        for (int i = 0; i < 26; ++i) {
            ch[i] = nullptr;
        }
        bestIndex = -1;
    }
    
    ~TrieNode() {
        for (int i = 0; i < 26; ++i) {
            if (ch[i] != nullptr) {
                delete ch[i];
            }
        }
    }
};

class Solution {
private:
    bool isBetter(int i, int j, const vector<string>& wordsContainer) {
        if (j == -1) return true;
        if (wordsContainer[i].length() < wordsContainer[j].length()) return true;
        if (wordsContainer[i].length() == wordsContainer[j].length()) return i < j;
        return false;
    }

public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        TrieNode* root = new TrieNode();
        
        int globalBestIndex = 0; 
        for (int i = 1; i < wordsContainer.size(); ++i) {
            if (isBetter(i, globalBestIndex, wordsContainer)) {
                globalBestIndex = i;
            }
        }
        root->bestIndex = globalBestIndex;

        for (int i = 0; i < wordsContainer.size(); ++i) {
            string word = wordsContainer[i];
            TrieNode* curr = root;
            
            for (int j = word.length() - 1; j >= 0; --j) {
                int idx = word[j] - 'a';
                if (curr->ch[idx] == nullptr) {
                    curr->ch[idx] = new TrieNode();
                }
                curr = curr->ch[idx];
                
                if (isBetter(i, curr->bestIndex, wordsContainer)) {
                    curr->bestIndex = i;
                }
            }
        }

        vector<int> ans;
        for (const string& query : wordsQuery) {
            TrieNode* curr = root;
            int lastValidBest = root->bestIndex;
            
            for (int j = query.length() - 1; j >= 0; --j) {
                int idx = query[j] - 'a';
                if (curr->ch[idx] == nullptr) {
                    break;
                }
                curr = curr->ch[idx];
                lastValidBest = curr->bestIndex;
            }
            ans.push_back(lastValidBest);
        }

        delete root; 
        return ans;
    }
};