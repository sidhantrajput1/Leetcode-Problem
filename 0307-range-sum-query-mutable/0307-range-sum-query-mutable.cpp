class NumArray {
public:
    int n;
    vector<int> segmentTree;

    void buildSegmentTree(int i, int l, int r, vector<int>& nums) {
        if (l == r) {
            segmentTree[i] = nums[r];
            return;
        }

        int mid = l + (r - l) / 2;
        buildSegmentTree(2*i + 1, l, mid, nums);
        buildSegmentTree(2*i + 2, mid + 1, r, nums);

        segmentTree[i] = segmentTree[2*i + 1] + segmentTree[2*i + 2];
    }

    void updateSegmentTree(int index, int val, int i, int l, int r) {
        if ( l == r) {
            segmentTree[i] = val;
            return;
        }

        int mid = l + (r - l) / 2;
        if (index <= mid) {
            updateSegmentTree(index, val, 2 * i + 1, l, mid);
        } else {
            updateSegmentTree(index, val, 2 * i + 2, mid + 1, r);
        }

        segmentTree[i] = segmentTree[2*i + 1] + segmentTree[2*i + 2];
    }

    int querySegmentTree(int start, int end, int i, int l, int r) {
        // No overlap
        if (r < start || l > end) return 0;

        // complete overlap
        if (l >= start && r <= end) return segmentTree[i];

        // partial overlap
        int mid = l + (r-l)/2;
        int left = querySegmentTree(start, end, 2 * i + 1, l, mid);
        int right = querySegmentTree(start, end, 2 * i + 2, mid + 1, r);

        return left + right;

    }

    NumArray(vector<int>& nums) {
        n = nums.size();
        segmentTree.resize(4 * n);

        // int i = 0, int left = 0, int right = 0, vector<int>& nums
        buildSegmentTree(0, 0, n - 1, nums);
    }
    
    void update(int index, int val) {
        updateSegmentTree(index, val, 0, 0, n - 1);
    }
    
    int sumRange(int start, int end) {
        return querySegmentTree(start, end, 0, 0, n - 1);
    }
};
