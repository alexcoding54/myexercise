/*
 * 注意, 此为树的示范代码！
 * 实际使用中, 还需要前, 后序遍历, 删除节点等等
 * 这些暂时都还没实现(我还没学到:D)
 * 
 * 此代码中， Node结构体表示树的一个节点，包含数据和指向左右子节点的指针。
 * createNode函数用于创建一个新的节点，并初始化数据和指针。
 * insertNode函数用于插入一个节点到树中，根据节点的值进行比较，将节点插入到合适的位置。
 * inorderTraversal函数用于中序遍历树，并打印每个节点的数据。
 * 在main函数中，我们创建了一个树，并插入一些节点，然后调用inorderTraversal函数打印树的中序遍历结果。
 *
 */

#include <stdio.h>
#include <stdlib.h>

// 树的节点定义
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// 创建一个新节点
Node* createNode(int data) 
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("内存分配失败！\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 插入节点
Node* insertNode(Node* root, int data) 
{
    if (root == NULL) {
        root = createNode(data);
    } else if (data <= root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// 遍历树并打印节点
void inorderTraversal(Node* root) 
{
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

int main() 
{
    Node* root = NULL;
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 70);
    root = insertNode(root, 60);
    root = insertNode(root, 80);

    printf("树的中序遍历：");
    inorderTraversal(root);

    return 0;
}

