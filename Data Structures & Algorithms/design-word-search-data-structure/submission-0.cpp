class TrieNode{
public:
    unordered_map<char, TrieNode*> children;
    bool endOfWord;
};
class WordDictionary {
    TrieNode* root;
    bool dfs(TrieNode* root, string word, int j) {
        auto cur = root;
       for (int i = j; i < word.size(); i++) {
            char c = word[i];
            if (c == '.') {
                for (auto [_, child] : cur->children) {
                    if (child && dfs(child, word, i + 1))
                        return true;
                }
                return false;
            }
            else {
                if (cur->children.find(c) == cur->children.end()) 
                    cur->children[c] = new TrieNode();
                
                cur = cur->children[c]; 
            }   
       }

       return cur->endOfWord;    
    }
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
       auto cur = root;
       for (char c : word) {
            if (cur->children.find(c) == cur->children.end()) 
                cur->children[c] = new TrieNode();

            cur = cur->children[c];    
       } 

       cur->endOfWord = true;
    }
    
    bool search(string word) {
        return dfs(root, word, 0);
    }
};
