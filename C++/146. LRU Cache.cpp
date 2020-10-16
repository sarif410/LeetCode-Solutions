class LRUCache {
public:
    list<pair<int,int>> dq;
    unordered_map<int,list<pair<int,int>>::iterator> mp;
    int size;
    LRUCache(int capacity) {
        size=capacity;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;
        else{
            pair<int,int> p=*mp[key];
            dq.erase(mp[key]);
            dq.push_front(p);
            mp[key]=dq.begin();
            return p.second;
        }
    }
    
    void put(int key, int value) {
        if(mp.find(key)==mp.end()){
            if(size==dq.size()){
                pair<int,int> p=dq.back();
                dq.pop_back();
                mp.erase(p.first);
            }
        }
        else{
            dq.erase(mp[key]);
        }
        dq.push_front(make_pair(key,value));
        mp[key]=dq.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
