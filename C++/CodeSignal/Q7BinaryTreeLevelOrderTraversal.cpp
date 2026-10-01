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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) //empty tree 
            return {}; 
        queue<TreeNode*> levels; //Track each level 
        vector<vector<int>> answer; 

        levels.push(root); //Start with the root 

        while(!levels.empty()){
            int size = levels.size(); //Keep track of how many nodes are in this level 
            vector<int> level; //New vector for the level 
            for(int i = 0; i < size; i++){ //Go through the entire level 
                level.push_back(levels.front()->val); 
                //Add the nodes on the next level 
                if(levels.front()->left) 
                    levels.push(levels.front()->left); 
                if(levels.front()->right)
                    levels.push(levels.front()->right); 
                levels.pop();  
            }
            answer.push_back(level); 
        }
        return answer; 
    }
};