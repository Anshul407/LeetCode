class NumArray {
public:
    vector<int>temp;
    vector<int>temp2;
    void init(){
        for(int i=1;i<temp.size();i++){
            temp[i]=temp[i]+temp[i-1];
        }
    }
    NumArray(vector<int>& nums) {
        temp=nums;
        temp2=nums;
        init();
    }
    
    void update(int index, int val) {
        int diff=val-temp2[index];
        temp2[index]=val;
        for(int i=index;i<temp.size();i++) {
            temp[i]+=diff;
        }
        
    }
    
    int sumRange(int left, int right) {
        if(left>0){
            return temp[right]-temp[left-1];
        }else return temp[right];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */