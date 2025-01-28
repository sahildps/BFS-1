/*
 * TC : O(N)
 * SC : O(N) where n is the number of the nodes on the same level
 */
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
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (root == nullptr)
        {
            return {};
        }

        vector<vector<int>> result;
        queue<TreeNode *> store;
        // insert the root element in the queue
        store.push(root);

        // keep traversing until the queue is empty
        while (!store.empty())
        {
            // traverse on the queue for the same level
            int storeSize = store.size();
            vector<int> temp;
            for (int i = 0; i < storeSize; i++)
            {
                TreeNode *curRoot = store.front();
                // store the elements on the same level
                // present in the queue
                temp.push_back(curRoot->val);

                if (curRoot->left)
                {
                    store.push(curRoot->left);
                }

                if (curRoot->right)
                {
                    store.push(curRoot->right);
                }
                store.pop();
            }
            // push the elements in the same level to the result
            result.push_back(temp);
        }
        return result;
    }
};