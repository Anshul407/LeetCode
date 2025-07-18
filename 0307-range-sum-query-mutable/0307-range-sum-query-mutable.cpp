class NumArray {
public:
    vector<int>segt,num;
    void init(int n){
        segt.resize(4*n);
    }
    void build(int i,int l,int r){
        if(l==r){
            segt[i]=num[l];
            return ;
        }
        int mid=(l+r)/2;
        build(2*i+1,l,mid);
        build(2*i+2,mid+1,r);
        segt[i]=segt[2*i+1]+segt[2*i+2];
    }
    void anshulupdate(int val,int index,int l,int r,int i){
        if(l==r){
            segt[i]=val;
            return ;
        }
        int mid=(l+r)/2;
        if(index<=mid){
            anshulupdate(val,index,l,mid,2*i+1);
        }else anshulupdate(val,index,mid+1,r,2*i+2);
        segt[i]=segt[2*i+1]+segt[2*i+2];
    }
    int anshulquery(int st,int end,int l,int r,int i){
        if(l>end||r<st)return 0;
        if(l>=st&&r<=end)return segt[i];
        auto mid=(l+r)/2;
        int leftans=anshulquery(st,end,l,mid,2*i+1);
        int rightans=anshulquery(st,end,mid+1,r,2*i+2);
        return leftans+rightans;
    }
    NumArray(vector<int>& nums) {
        num=nums;
        init(nums.size());
        build(0,0,nums.size()-1);
    }
    
    void update(int index, int val) {
        anshulupdate(val,index,0,num.size()-1,0);
    }
    
    int sumRange(int left, int right) {
        return anshulquery(left,right,0,num.size()-1,0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */