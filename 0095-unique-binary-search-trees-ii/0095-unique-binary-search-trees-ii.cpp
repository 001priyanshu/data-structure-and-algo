/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
vector<TreeNode*> solve(int low ,int high){
    if(low>high) return {NULL};
    vector<TreeNode*>ans;
    for(int i=low;i<=high;i++){
        vector<TreeNode*>lt = solve(low,i-1);
        vector<TreeNode*>rt = solve(i+1,high);
        for(auto &l:lt){
            for(auto &r:rt){
                TreeNode* temp  = new TreeNode(i);
                temp->left = l;
                temp->right = r;
                ans.push_back(temp);
            }
        } 
    }
    return ans;
}
    vector<TreeNode*> generateTrees(int n) {
        
        return solve(1,n);
    }
};
