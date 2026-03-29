class Node {
    public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr){}
};

class LRUCache {
private:
    int cap{};
    unordered_map<int, Node*> cache; // key, *node
    Node *left, *right;

    void remove(Node* node) {
        auto prev = node->prev;
        auto next = node->next;

        prev->next = next; 
        next->prev = prev;
    }

    void insert(Node* node) {
        auto prev = right->prev;
        prev->next = node;
        node->prev = prev;

        right->prev = node;
        node->next = right;
    }
public:
    LRUCache(int capacity) {
        this->cap = capacity;
        cache.clear();
        
        this->left = new Node(0, 0);
        this->right = new Node(0, 0);

        left->next = right;
        right->prev = left;
    }

    int get(int key) {
        if (cache.find(key) == cache.end()) 
            return -1;

        auto node = cache[key];

        remove(node);
        insert(node);

        return node->val; 
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) 
        {
            auto node = cache[key];
            node->val = value;

            remove(node);
            insert(node);
        }
        else
        {
            auto node = new Node(key, value);
            cache[key] = node;
            insert(node);

            if (cache.size() > cap)
            {
                auto lru = left->next;
                remove(lru);
                cache.erase(lru->key);
                delete lru;
            }
        }
    }
};
// class Node {
// public:
//     int key;
//     int val;
//     Node* prev;
//     Node* next;

//     Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
// };

// class LRUCache {
// private:
//     int cap;
//     unordered_map<int, Node*> cache;
//     Node* left;
//     Node* right;

//     void remove(Node* node) {
//         Node* prev = node->prev;
//         Node* nxt = node->next;
//         prev->next = nxt;
//         nxt->prev = prev;
//     }

//     void insert(Node* node) {
//         Node* prev = right->prev;
//         prev->next = node;
//         node->prev = prev;
//         node->next = right;
//         right->prev = node;
//     }

// public:
//     LRUCache(int capacity) {
//         cap = capacity;
//         cache.clear();
//         left = new Node(0, 0);
//         right = new Node(0, 0);
//         left->next = right;
//         right->prev = left;
//     }

//     int get(int key) {
//         if (cache.find(key) != cache.end()) {
//             Node* node = cache[key];
//             remove(node);
//             insert(node);
//             return node->val;
//         }
//         return -1;
//     }

//     void put(int key, int value) {
//         if (cache.find(key) != cache.end()) {
//             remove(cache[key]);
//             insert(cache[key]);
//             cache[key]->val = value;
//             return;
//         }
//         Node* newNode = new Node(key, value);
//         cache[key] = newNode;
//         insert(newNode);

//         if (cache.size() > cap) {
//             Node* lru = left->next;
//             remove(lru);
//             cache.erase(lru->key);
//             delete lru;
//         }
//     }
// };
// class LRUCache {
// vector<pair<int,int>> list;
// int cap{};
// public:
//     LRUCache(int capacity) : cap(capacity){
//         list.reserve(cap);
//     }
    
//     int get(int key) {
//         int res = -1;
//         for (int i=0; i < list.size(); i++)
//         {
//             if (list[i].first == key)
//             {
//                 res = list[i].second;
//                 list.erase(list.begin() + i);
//                 list.push_back({key, res});
//                 break;
//             }
//         }
//         return res;     
//     }
    
//     void put(int key, int value) {
//         for (int i=0; i < list.size(); i++)
//         {
//             if (list[i].first == key)
//             {
//                 list.erase(list.begin() + i);
//                 list.push_back({key, value});
//                 return;
//             }
//         }

//         if (list.size() == cap)
//             list.erase(list.begin());

//         list.push_back({key, value});    
//     }
// };
