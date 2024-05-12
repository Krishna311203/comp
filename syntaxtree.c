#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    char data;
    struct Node *left;
    struct Node *right;
}Node;

Node* createNode(char data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right= NULL;
    return newNode;
}

int evaluate(Node* root){
    if (root==NULL) return 0;

    if(root->data >= '0' && root->data<='9'){
        return root->data -'0';
    }

    int leftValue = evaluate(root->left);
    int rightValue = evaluate(root->right);

    switch (root->data) {
    case '+':
    return leftValue + rightValue;
    case '-':
    return leftValue - rightValue;
    case '*':
    return leftValue * rightValue;
    case '/':
    if (rightValue != 0) {
    return leftValue / rightValue;
    }
    else{
        printf("error");
        exit(EXIT_FAILURE);
    }
    default:
    printf("error");
    }
}

int main(){
    Node* root = createNode('+');
    root->left = createNode('*');
    root->right = createNode('/');
    root->left->left = createNode('3');
    root->left->right = createNode('2');
    root->right->left = createNode('8');
    root->right->right = createNode('2');
    int result = evaluate(root);
    printf("result: %d",result);
    return 0;
}