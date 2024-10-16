class RLEIterator {
public:
    vector<pair<int,int>>mp;
    
    RLEIterator(vector<int>& encoding) {
        for(int i=0;i<encoding.size()-1;i+=2){
            if(encoding[i]>0)
            mp.push_back({encoding[i+1],encoding[i]});
        }
    }
    
    int next(int n) {
        // for(auto i:mp)cout<<i.first<<" "<<i.second<<" ";
        // cout<<endl;
        for(auto &i:mp){
            if(i.second==0)continue;
            if(i.second>=n){
                i.second-=n;
                return i.first;
            }
            else{
                n-=i.second;
                i.second=0;
            }
        }
        return -1;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */