#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include "Tree.h"
using namespace std;

// Time Complexity: O(N).
// Space Complexity: O(N).
vector<int> GetBottomView(TreeNode* root){
    if(root==NULL)
        return {};

    // will store each line no. and corresponding last element of it.
    map<int, int> m;    // map will store results in ordered manner.
    queue<pair<TreeNode*, int>> q;

    q.push({root, 0});

    // Level Order traversal.
    while(!q.empty()){
        pair<TreeNode*, int> tmp = q.front();
        q.pop();

        TreeNode* curr = tmp.first;
        int line = tmp.second;

        // updating last element of current line.
        m[line] = curr->data;

        // left will be on line-1.
        if(curr->left)
            q.push({curr->left, line-1});
        
        // right will be on line+1.
        if(curr->right)
            q.push({curr->right, line+1});
    }

    // getting final results -- last nodes from each line.
    vector<int> bottomView;
    for(auto p: m){
        bottomView.push_back(p.second);
    }

    return bottomView;
}

int main(){
    TreeNode *root;
    vector<int> nodes = {1, 2, 4, -1, 7, -1, -1, -1, 3, 5, -1, -1, 6, -1, -1};
    int i = 0;
    root = BuildTree(root, nodes, i, nodes.size());

    vector<int> Bottom = GetBottomView(root);

    for(int i: Bottom){
        cout << i << " ";
    }
    return 0;
}