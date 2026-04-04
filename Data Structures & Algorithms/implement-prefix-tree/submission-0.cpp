class TrieNode {
public:
    TrieNode* children[26];
    bool endOfWord;

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        endOfWord = false;
    }
};

class PrefixTree {
    TrieNode* root;
public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        auto cur = root;
        for (char c : word) {
            int idx = c - 'a';
            if (cur->children[idx] == nullptr) 
                cur->children[idx] = new TrieNode();
            
            cur = cur->children[idx];
        }
        cur->endOfWord = true;
    }
    
    bool search(string word) {
        auto cur = root;
        for (char c : word) {
            int idx = c - 'a';
            if (cur->children[idx] == nullptr) 
                return false;
            cur = cur->children[idx];         
        }

        return cur->endOfWord;
    }
    
    bool startsWith(string prefix) {
        auto cur = root;
        for (char c : prefix) {
            int idx = c - 'a';
            if (cur->children[idx] == nullptr) 
                return false;

            cur = cur->children[idx];         
        }

        return true;
    }
};
