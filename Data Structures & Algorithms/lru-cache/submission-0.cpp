class LRUCache {
vector<pair<int,int>> list;
int cap{};
public:
    LRUCache(int capacity) : cap(capacity){
        list.reserve(cap);
    }
    
    int get(int key) {
        int res = -1;
        for (int i=0; i < list.size(); i++)
        {
            if (list[i].first == key)
            {
                res = list[i].second;
                list.erase(list.begin() + i);
                list.push_back({key, res});
                break;
            }
        }
        return res;     
    }
    
    void put(int key, int value) {
        for (int i=0; i < list.size(); i++)
        {
            if (list[i].first == key)
            {
                list.erase(list.begin() + i);
                list.push_back({key, value});
                return;
            }
        }

        if (list.size() == cap)
            list.erase(list.begin());

        list.push_back({key, value});    
    }
};
