class Solution {
public:
    vector<int> ans;

    void dfs(Node* root) {
        if (root == nullptr) return;

        for (Node* child : root->children) {
            dfs(child);
        }

        ans.push_back(root->val);
    }

    vector<int> postorder(Node* root) {
        dfs(root);
        return ans;
    }
};