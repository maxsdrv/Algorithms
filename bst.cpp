//BST algorithm

#include <iostream>
#include <map>
#include <string>
#include <queue>

struct Person {
    std::string name;
    int age;
};

void printData(const std::map<int, Person> &employees) {
    for (const auto& [key, value] : employees) {
        std::cout << "Number= " << key << " Name: " << value.name << " Age: " << 
        value.age << std::endl;
    }
}

void reverseBinary(int n) {
    if (n == 0) {
        return;
    }
    std::cout << n % 2;
    reverseBinary(n / 2);
}

struct TreeNode {
    double data;
    TreeNode *left;
    TreeNode *right;
};

void levelOrderPrint(TreeNode *root) {
    if (root == nullptr) {
        return;
    }
    std::queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();
        std::cout << temp->data;

        if (temp->left != nullptr)
            q.push(temp->left);

        if (temp->right != nullptr)
            q.push(temp->right);
    }
}

void printBinTree(TreeNode *root) {
    if (root) {
        std::cout << root->data;
        if (root->left || root->right) {
            std::cout << "(";
        }
        if (root->left) {
            printBinTree(root->left);
        }
        else {
            std::cout << "NULL" << ",";
        }
        if (root->right) {
            printBinTree(root->right);
        }
        else {
            std::cout << "NULL";
        }
        std::cout << ")";
    }
}

int main() {

    std::map<int, Person> employees {{1, {"Haas", 20}}, {2, {"Gsk", 30}}};
    // printData(employees);

    
    TreeNode *node = new TreeNode;
    levelOrderPrint(node);


    printBinTree(node);

    delete node;

    return 0;
}