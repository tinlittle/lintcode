#include <string>
#include <deque>
#include <vector>
#include <numeric>

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : left(nullptr), right(nullptr) {
      this->val = val;
    }
    TreeNode(int val, TreeNode *_left, TreeNode *_right) : left(_left), right(_right) {
      this->val = val;
    }
};

class Solution {
public:
    void traverse(TreeNode * root, std::vector<int> &list) {
      if (root->left != nullptr)
        traverse(root->left, list);
      list.push_back(root->val);
      if (root->right != nullptr)
        traverse(root->right, list);
    }

    void traverseBounded(TreeNode * root, std::vector<int> &list, int k1, int k2) {
      if (root->left != nullptr && root->val >= k1) // no need to go down further since all left decendents would be less
        traverseBounded(root->left, list, k1, k2);
      if (root->val >= k1 && root->val <= k2)
        list.push_back(root->val);
      if (root->right != nullptr && root->val <= k2)
        traverseBounded(root->right, list, k1, k2);
    }

    std::vector<int> searchRange(TreeNode * root, int k1, int k2) {
      std::vector<int> list;
      
      if (root != nullptr)
        traverseBounded(root, list, k1, k2);

      return list;
    }

    std::string serialize(TreeNode * root) {
      std::string output;
      std::deque<TreeNode*> queue;
      queue.push_back(root);
      do {
        TreeNode *node = queue.front();
        if (node == nullptr) {
          output.push_back('#');
          output.push_back(',');
        }
        else {
          output += std::to_string(node->val);
          output.push_back(',');
          queue.push_back(node->left);
          queue.push_back(node->right);
        }  
        queue.pop_front();
      } while (!queue.empty());
      while (output.back() == '#' || output.back() == ',')
        output.pop_back(); // get rid of trailing '#' and ','

      return output;

    }

    void tokenize(const std::string source, char delimiter, std::vector<std::string> &token_q) {
      std::size_t start = source.find_first_not_of(delimiter);
      std::size_t end = start;
      while (start != std::string::npos) {
        end = source.find(delimiter, start);
        token_q.push_back(source.substr(start, end - start));
        start = source.find_first_not_of(delimiter, end);
      }
    }

    TreeNode * deserialize(std::string &data) {
        std::vector<std::string> token_q;
        tokenize(data, ',', token_q);
        if (token_q.empty())
          return nullptr;
        TreeNode *root = nullptr;
        std::vector<TreeNode*> node_q;
        for (std::string token : token_q) {
          TreeNode *node = nullptr;
          if (token == "#") {
            node_q.push_back(nullptr);
          }
          else {
            int val = std::stoi(token);
            node = new TreeNode(val);
            node_q.push_back(node);
          }
        }
        std::vector<TreeNode*>::iterator parent = node_q.begin();
        std::vector<TreeNode*>::const_iterator child = node_q.cbegin() + 1;
        if (root == nullptr)
          root = *parent;
        while (parent != node_q.end() && child != node_q.cend()) {
          if (*parent == nullptr) {
            ++parent;
            continue;
          }
          TreeNode *left = nullptr, *right = nullptr;
          if (child != node_q.cend()) {
            left = *child++;
            if (child != node_q.cend()) {
              right = *child++;
            }
          }
          (*parent)->left = left; (*parent)->right = right;
          ++parent;
        }

        return root;
    }
};