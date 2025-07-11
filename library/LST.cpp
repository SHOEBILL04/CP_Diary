class SegmentTree
{
public:
    int n;
    vector<int>a,lazy,tree;
    SegmentTree(vector<int>arr){
        a=arr;
        n = arr.size();
        lazy.assign(4*n,0);
        tree.assign(4*n,0);
        build(1,0,n-1);
    }
    void update(int l,int r,int val){update(1,0,n-1,l,r,val);}
    int query(int l,int r){return query(1,0,n-1,l,r);}
    void print(){for(auto it : tree)cout << it << endl;}
private:
    void propagate(int node,int start,int end){
        if(start==end)tree[node] += lazy[node];
        else{
            tree[node] += (end-start+1)*lazy[node]; /*if you need sum use it else for other
                                                      things remove (end-start+1) part*/     
            lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node];
        }
        lazy[node]=0;
    }
    void build(int node,int start,int end){
        if(start==end)tree[node] = a[start];
        else {
            int mid = (start+end)/2;
            build(2*node,start,mid);
            build(2*node+1,mid+1,end);
            tree[node] = tree[2*node] + tree[2*node+1];
        }
    }
    void update(int node,int start,int end,int l,int r,int val){
        propagate(node,start,end);
        if(end<l or start>r)return;
        if(start==end)tree[node]+=val;
        else if(l<=start and end<=r){
            lazy[node] += val;
            propagate(node,start,end);
        }
        else {
            int mid = (start+end)/2;
            update(2*node,start,mid,l,r,val);
            update(2*node+1,mid+1,end,l,r,val);
            tree[node] = tree[2*node] + tree[2*node+1];
        }
    }
    int query(int node,int start,int end,int l,int r){
        if(end<l or start>r)return 0;
        propagate(node,start,end);
        if(start==end){
            return tree[node];
        }
        else if(l<=start and end<=r)return tree[node];
        else {
            int mid = (start+end)/2;
            int left = query(2*node,start,mid,l,r);
            int right = query(2*node+1,mid+1,end,l,r);
            return left+right;
        }
    }
};
