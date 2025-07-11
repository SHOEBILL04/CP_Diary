class BIT {
    //1 Based
    //initialize using update(index,val)
private:
    vector<int> tree;  // This will store the BIT
    int n;             // Size of the array/tree
public:
    // Constructor: initialize the BIT with size n
    BIT(int size) {
        n = size;
        tree.assign(n + 1, 0);// Initialize the tree with zeros, 1-based index
    }
    // Function to update the BIT at index `idx` with value `val`
    void update(int idx, int val) {
        while (idx <= n) {
            tree[idx] += val;
            idx += (idx & -idx);
        }
    }
    // Function to get the prefix sum from 1 to idx
    int query(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += tree[idx];
            idx -= (idx & -idx);  // Move to the parent node
        }
        return sum;
    }
    // Function to get the sum in the range [l, r]
    int rangeQuery(int l, int r) {
        return query(r) - query(l - 1);
    }
    // Optional: function to update an element to a new value directly
    void updateToValue(int idx, int newVal) {
        int currentVal = rangeQuery(idx, idx);  // Get the current value at idx
        update(idx, newVal - currentVal);       // Update with the difference
    }
	int search(int x)
	{
		// lower bound index of prefix sum
		int l = 0;
		for(int i = 25; i>=0; i--)
		{
			int sz = (1<<i);
			if(l+sz>=n)continue;
			if(tree[l+sz]<x)
			{
				x-=tree[l+sz];
				l+=sz;
			}
		}
		return l+1;
	}

};
