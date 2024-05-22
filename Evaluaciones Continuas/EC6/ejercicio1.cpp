#include "iostream"
#include "vector"
#include "stack"
#include "queue"
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int value){
        this->data = value;
        this->left = nullptr;
        this->right = nullptr;
    }

};

class Solution{
public:
    Solution(){};

    Node* generateBinaryTree(vector<int> vec_nums) {
        Node *root = new Node(vec_nums[0]);
        queue<Node *> Stack;
        Stack.push(root);

        int i = 1;

        while (i < vec_nums.size()){
            auto temp = Stack.front();
            Stack.pop();

            if(i < vec_nums.size()){
                temp->left = new Node(vec_nums[i]);
                Stack.push(temp->left);
                i++;
            }

            if(i < vec_nums.size()){
                temp->right = new Node(vec_nums[i]);
                Stack.push(temp->right);
                i++;
            }
        }

        return root;

    }

    vector<int> sol(vector<int> root) {
        Node* rootNode = generateBinaryTree(root);
        vector<int> resultNums;
        if (!rootNode) return resultNums;

        queue<Node*> Queue;
        Queue.push(rootNode);
        bool reverse = false;

        while (!Queue.empty()) {
            int levelSize = Queue.size();

            vector<int> levelNodes;
            for (int i = 0; i < levelSize; i++) {
                auto temp = Queue.front();
                Queue.pop();

                levelNodes.push_back(temp->data);

                if (temp->left) Queue.push(temp->left);
                if (temp->right) Queue.push(temp->right);
            }

            if (reverse) {
                for (int i = 0; i < levelNodes.size() / 2; i++) {
                    swap(levelNodes[i], levelNodes[levelNodes.size() - i - 1]);
                }
            }

            for (auto i : levelNodes) {
                resultNums.push_back(i);
            }

            reverse = !reverse;
        }

        for (auto i : resultNums) {
            cout << i << " ";
        }

        return resultNums;
    }

};

int main(){
    Solution s1;

    s1.sol({2,3,5,8,13,21,34});

}