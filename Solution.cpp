class Solution {
public:
    vector<TreeNode*> vec;

    // Recursive helper function to process node deletions
    TreeNode* hlo(TreeNode*& root, unordered_set<int>& st) {
        if (!root)
            return NULL;

        // Recursively process left and right subtrees
        root->left = hlo(root->left, st);
        root->right = hlo(root->right, st);

        // If current node needs to be deleted
        if (st.find(root->val) != st.end()) {
            if (root->left)
                vec.push_back(root->left);  // Add left child to result forest
            if (root->right)
                vec.push_back(root->right);  // Add right child to result forest
            return NULL;  // Delete current node
        }

        return root;
    }

    // Main function
    vector<TreeNode*> delNodes(TreeNode*& root, vector<int>& to_delete) {
        unordered_set<int> st(to_delete.begin(), to_delete.end());
        TreeNode* ans = hlo(root, st);

        // If root isn't deleted, add it to the forest
        if (ans)
            vec.push_back(root);

        return vec;
    }
};
