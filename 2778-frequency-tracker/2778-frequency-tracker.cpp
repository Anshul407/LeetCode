class FrequencyTracker {
public:
    unordered_map<int,int>mp;
    unordered_map<int,int>mp2;
    FrequencyTracker() {
        
    }
    
    void add(int number) {
        if(mp[number]>0){
        mp2[mp[number]]--;
        if(mp2[mp[number]]==0)mp2.erase(mp[number]);}
        mp[number]++;
        mp2[mp[number]]++;
        
    }
    
    void deleteOne(int number) {
        if(mp.find(number)!=mp.end()&&mp[number]>0){
        mp2[mp[number]]--;
        if(mp2[mp[number]]==0)mp2.erase(mp[number]);
        
        mp[number]--;
        if(mp[number]==0)mp.erase(number);
        else  mp2[mp[number]]++;}
        
        return ;
    }
    
    bool hasFrequency(int frequency) {
        return mp2.find(frequency)!=mp2.end()&&mp2[frequency]>0;
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */