#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structure for a tree node
struct Node {
    char data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to construct the parse tree
struct Node* constructParseTree(char* input, int* index) {
    if (input[*index] == '\0') {
        return NULL;
    }

    struct Node* newNode = createNode(input[*index]);
    (*index)++;

    if (input[*index] == 'a') {
        (*index)++;
        newNode->left = constructParseTree(input, index);
    }

    if (input[*index] == 'A') {
        (*index)++;
        newNode->right = constructParseTree(input, index);
    }

    return newNode;
}

// Function to print the parse tree in pre-order traversal
void printParseTree(struct Node* root) {
    if (root == NULL) {
        return;
    }

    printf("%c ", root->data);
    printParseTree(root->left);
    printParseTree(root->right);
}

int main() {
    char input[100];

    printf("Enter the input string: ");
    scanf("%s", input);

    int index = 0;
    struct Node* root = constructParseTree(input, &index);

    printf("Parse Tree (Pre-order traversal):\n");
    printParseTree(root);
    printf("\n");

    return 0;
}
