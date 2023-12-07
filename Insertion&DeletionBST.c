#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

int isPrime(int num) {
    if (num <= 1)
        return 0; // Not prime

    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0)
            return 0; // Not prime
    }

    return 1; // Prime
}

struct Node* deletePrimes(struct Node* root) {
    if (root == NULL)
        return NULL;

    root->left = deletePrimes(root->left);
    root->right = deletePrimes(root->right);

    if (isPrime(root->data)) {
        free(root);
        return NULL;
    }

    return root;
}

void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    struct Node* root = NULL;

    for (int i = 0; i < 5; ++i) {
        root = insert(root, rand() % 20 * 5 + 5);
    }

    printf("BST before deleting prime numbers: ");
    inorderTraversal(root);
    printf("\n");

    root = deletePrimes(root);

    printf("BST after deleting prime numbers: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
