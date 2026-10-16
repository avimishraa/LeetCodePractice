class Node {
public:
    long long sum = 0;
    long long sumOfSquares = 0;
    long long lazy = 0;
};

class LazySegmentTree {
    int n;
    vector<Node> tree;

    void push(int node, int l, int r) {
        if (tree[node].lazy == 0) return;
        long long val = tree[node].lazy;
        int mid = l + (r - l) / 2;
        
        // Left child
        apply(2 * node, l, mid, val);
        // Right child
        apply(2 * node + 1, mid + 1, r, val);
        
        tree[node].lazy = 0;
    }

    void apply(int node, int l, int r, long long val) {
        long long len = (r - l + 1);
        tree[node].sumOfSquares = (tree[node].sumOfSquares + 2 * val * tree[node].sum + val * val % 1000000007 * len) % 1000000007;
        tree[node].sum = (tree[node].sum + val * len) % 1000000007;
        tree[node].lazy = (tree[node].lazy + val) % 1000000007;
    }

    void update(int node, int l, int r, int ql, int qr, long long val) {
        if (ql > r || qr < l) return;
        if (ql <= l && r <= qr) {
            apply(node, l, r, val);
            return;
        }
        push(node, l, r);
        int mid = l + (r - l) / 2;
        update(2 * node, l, mid, ql, qr, val);
        update(2 * node + 1, mid + 1, r, ql, qr, val);
        tree[node].sum = (tree[2 * node].sum + tree[2 * node + 1].sum) % 1000000007;
        tree[node].sumOfSquares = (tree[2 * node].sumOfSquares + tree[2 * node + 1].sumOfSquares) % 1000000007;
    }

public:
    LazySegmentTree(int size) {
        n = size;
        tree.resize(4 * n);
    }

    void updateRange(int ql, int qr, long long val) {
        if (ql > qr) return;
        update(1, 0, n - 1, ql, qr, val);
    }

    long long getTotalSumOfSquares() {
        return tree[1].sumOfSquares;
    }
};

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        long long mod = 1e9 + 7;
        LazySegmentTree tree(n);
        unordered_map<int, int> lastSeen;
        
        long long totalSum = 0;
        
        for (int r = 0; r < n; ++r) {
            int l = lastSeen.count(nums[r]) ? lastSeen[nums[r]] + 1 : 0;
            tree.updateRange(l, r, 1);
            lastSeen[nums[r]] = r;
            totalSum = (totalSum + tree.getTotalSumOfSquares()) % mod;
        }
        
        return totalSum;
    }
};