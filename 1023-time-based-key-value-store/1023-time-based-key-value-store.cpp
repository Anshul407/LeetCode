class TimeMap {
public:
    map<string,vector<pair<int,string>>>mp;
    string f(vector<pair<int,string>>&v,int x){
        if(v.empty()||v[0].first>x)return "";
        int i=0,j=v.size()-1;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(v[mid].first>x)j=mid-1;
            else i=mid+1;
        }
        return v[j].second;
    }
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        return f(mp[key],timestamp);
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */