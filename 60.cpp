//
//  main.cpp
//  60
//
//  Created by 小尹 on 2019/6/25.
//  Copyright © 2019 小尹. All rights reserved.
//
//  剑指offer60
// 从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。
// 思路：bfs 时记录该层节点。只是，现在是用树，指针表示。


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};


class Solution {
public:
    vector<vector<int> > Print(TreeNode *pRoot) {
        vector<vector<int> > ans;
        vector<int> tmp;
        if (pRoot==NULL) return ans;
        
        queue<TreeNode*> q;
        
        q.push(pRoot);
        int now_level = 1;
        int next_level = 0;
        while (!q.empty()) {
            TreeNode* fr = q.front();
            q.pop();
            
            tmp.push_back(fr->val);
            
            if(fr->left != NULL) {
                q.push(fr->left);
                next_level += 1;
            }
            
            if(fr->right!= NULL) {
                q.push(fr->right);
                next_level += 1;
            }
            --now_level;
            
            if(now_level==0){
                now_level = next_level;
                next_level = 0;
                ans.push_back(tmp);
                for(int i = 0; i < (int)tmp.size(); i++) {
                    printf("%d ", tmp[i]);
                }
                puts("");
                tmp.clear();
            }
            
        }
        
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    TreeNode a = TreeNode(1);
    TreeNode b = TreeNode(2);
    TreeNode c = TreeNode(3);
    TreeNode d = TreeNode(4);
    TreeNode e = TreeNode(5);
    TreeNode f = TreeNode(6);
    TreeNode g = TreeNode(7);
    TreeNode h = TreeNode(8);
    
    
    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.left = &f;
    e.left = &g;
    e.right = &h;
    Solution solu = Solution();
    solu.Print(&a);
    
    return 0;
}
