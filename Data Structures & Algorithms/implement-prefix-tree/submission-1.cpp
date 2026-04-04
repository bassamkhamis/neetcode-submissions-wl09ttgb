class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool endOfWord;

    TrieNode() {
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
            if (cur->children.count(c) == 0) 
                cur->children[c] = new TrieNode();
            
            cur = cur->children[c];
        }
        cur->endOfWord = true;
    }
    
    bool search(string word) {
        auto cur = root;
        for (char c : word) {
            if (cur->children.count(c) == 0) 
                return false;
            cur = cur->children[c];         
        }

        return cur->endOfWord;
    }
    
    bool startsWith(string prefix) {
        auto cur = root;
        for (char c : prefix) {
            if (cur->children.count(c) == 0) 
                return false;

            cur = cur->children[c];         
        }

        return true;
    }
};
