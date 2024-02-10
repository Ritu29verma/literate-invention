#include <iostream>
#include <vector>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST {
private:
    TreeNode* root;

    TreeNode* insert(TreeNode* node, int data) {
        if (node == nullptr) {
            return new TreeNode(data);
        }

        if (data < node->data) {
            node->left = insert(node->left, data);
        } else if (data > node->data) {
            node->right = insert(node->right, data);
        }

        return node;
    }

    TreeNode* search(TreeNode* node, int key) {
        if (node == nullptr || node->data == key) {
            return node;
        }

        if (key < node->data) {
            return search(node->left, key);
        } else {
            return search(node->right, key);
        }
    }

    void inorderTraversal(TreeNode* node, std::vector<int>& result) {
        if (node != nullptr) {
            inorderTraversal(node->left, result);
            result.push_back(node->data);
            inorderTraversal(node->right, result);
        }
    }

    void preorderTraversal(TreeNode* node, std::vector<int>& result) {
        if (node != nullptr) {
            result.push_back(node->data);
            preorderTraversal(node->left, result);
            preorderTraversal(node->right, result);
        }
    }

    void postorderTraversal(TreeNode* node, std::vector<int>& result) {
        if (node != nullptr) {
            postorderTraversal(node->left, result);
            postorderTraversal(node->right, result);
            result.push_back(node->data);
        }
    }

    TreeNode* findMin(TreeNode* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    TreeNode* deleteNode(TreeNode* node, int key) {
        if (node == nullptr) {
            return nullptr;
        }

        if (key < node->data) {
            node->left = deleteNode(node->left, key);
        } else if (key > node->data) {
            node->right = deleteNode(node->right, key);
        } else {
            if (node->left == nullptr) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }

            TreeNode* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
        return node;
    }

public:
    BST() : root(nullptr) {}

    void insert(int data) {
        root = insert(root, data);
    }

    bool search(int key) {
        return search(root, key) != nullptr;
    }

    std::vector<int> inorderTraversal() {
        std::vector<int> result;
        inorderTraversal(root, result);
        return result;
    }

    std::vector<int> preorderTraversal() {
        std::vector<int> result;
        preorderTraversal(root, result);
        return result;
    }

    std::vector<int> postorderTraversal() {
        std::vector<int> result;
        postorderTraversal(root, result);
        return result;
    }

    void deleteNode(int key) {
        root = deleteNode(root, key);
    }
};

int main() {
    BST bst;

    // Insert nodes
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    // Inorder traversal
    std::cout << "Inorder Traversal: ";
    for (int num : bst.inorderTraversal()) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Preorder traversal
    std::cout << "Preorder Traversal: ";
    for (int num : bst.preorderTraversal()) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Postorder traversal
    std::cout << "Postorder Traversal: ";
    for (int num : bst.postorderTraversal()) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Search for a key
    int key = 40;
    std::cout << "Search for " << key << ": " << (bst.search(key) ? "Found" : "Not found") << std::endl;

    // Delete a node
    bst.deleteNode(30);

    // Inorder traversal after deletion
    std::cout << "Inorder Traversal after deletion: ";
    for (int num : bst.inorderTraversal()) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
