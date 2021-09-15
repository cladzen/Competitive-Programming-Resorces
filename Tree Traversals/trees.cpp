#include "bits/stdc++.h"
#define nline "\n"
#define debug(x) { cout << #x << " " << x << "\n"; }
#define MOD 1000000007

using namespace std;

// @author: cladzen

struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;
};

vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root == NULL) return ans;
        stack<TreeNode*> st;
        st.push(root);
        // we are basically inacting the resursion
        // using a while loop
        while (!st.empty()) {
                TreeNode* node = st.top();
                st.pop();
                ans.push_back(node->val);

                if (node->right != NULL) {
                        st.push(node->right);
                }

                if (node->left != NULL) {
                        st.push(node->left);
                }
        }

        return ans;
}

vector<int> postorderTraversal_2stack(TreeNode* root) {
        // using 2 stacks
        // here we basically reverse the preorder traversal output
        // but with little changes
        // preorder = root left right
        // reverse preorder = right left root
        // postorder = left right root
        // so just put left before right in the stack and then reverse the result
        vector<int> ans;
        if (root == NULL) return ans;
        stack<TreeNode*> st;
        stack<TreeNode*> st2;
        st.push(root);
        while (!st.empty()) {
                TreeNode* node = st.top();
                st.pop();
                st2.push(node);

                if (node->left != NULL) {
                        st.push(node->left);
                }

                if (node->right != NULL) {
                        st.push(node->right);
                }
        }

        while (!st2.empty()) {
                ans.push_back(st2.top()->val);
                st2.pop();
        }

        return ans;
}

vector<int> postorderTraversal_1stack(TreeNode* root) {
        vector<int> ans;
        if (root == NULL) return ans;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while (cur != NULL or !st.empty()) {
                if (cur != NULL) {
                        st.push(cur);
                        cur = cur->left;
                }
                else {
                        TreeNode* node = st.top();
                        node = node->right;
                        if (node == NULL) {
                                node = st.top();
                                st.pop();
                                ans.push_back(node->val);
                                while (st.top()->right == node and !st.empty()) {
                                        node = st.top();
                                        st.pop();
                                        ans.push_back(node->val);
                                }
                        }
                        else cur = node;
                }
        }

        return ans;
}

vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root == NULL) return ans;
        stack<TreeNode*> st;
        TreeNode* node = root;

        while (true) {
                if (node != NULL) {
                        st.push(node);
                        node = node->left;
                }
                else {
                        if (st.empty()) break;
                        node = st.top();
                        st.pop();
                        ans.push_back(node->val);
                        node = node->right;
                }
        }

        return ans;
}

void test_case() {
        return;
}

int main(int argc, char **argv) {
#ifndef ONLINE_JUDGE
        freopen("Input.txt", "r", stdin);
        freopen("Output.txt", "w", stdout);
#endif
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        int64_t T;
        cin >> T;

        while (T--) {
                test_case();
        }

        return 0;
}
