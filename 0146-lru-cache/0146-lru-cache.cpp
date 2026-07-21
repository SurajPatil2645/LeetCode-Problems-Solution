class LRUCache {
private:
    int cap;
    list<pair<int, int>> cache;
    
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> map;

public:
    LRUCache(int capacity) : cap(capacity) {}

    int get(int key) {
        auto it = map.find(key);
        if (it == map.end()) {
            return -1;
        }
        cache.splice(cache.begin(), cache, it->second);
        return it->second->second;
    }

    void put(int key, int value) {
        auto it = map.find(key);
        
        if (it != map.end()) {
            it->second->second = value;
            cache.splice(cache.begin(), cache, it->second);
            return;
        }

        if (cache.size() == cap) {
            int lru_key = cache.back().first;
            cache.pop_back();
            map.erase(lru_key);
        }

        cache.push_front({key, value});
        map[key] = cache.begin();
    }
};