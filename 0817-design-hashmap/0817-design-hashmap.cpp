class MyHashMap {
public:
    vector<int>h;
    MyHashMap() {
        h.resize(1000001,INT_MAX);
    }
    
    void put(int key, int value) {
        h[key]=value;
    }
    
    int get(int key) {
        if(h[key]==INT_MAX)return -1;
        return h[key];
    }
    
    void remove(int key) {
        h[key]=INT_MAX;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */