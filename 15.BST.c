#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node *createNode(int key) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node *insert(struct Node *root, int key) {
    if (root == NULL) {
        return createNode(key);
    }

    if (key < root->data) {
        root->left = insert(root->left, key);
    } else if (key > root->data) {
        root->right = insert(root->right, key);
    }

    return root;
}

void preorderTraversal(struct Node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void inorderTraversal(struct Node *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

void postorderTraversal(struct Node *root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

struct Node *findSmallest(struct Node *root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

struct Node *findLargest(struct Node *root) {
    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}

struct Node *deleteNode(struct Node *root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            struct Node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        struct Node *temp = findSmallest(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

int countNodes(struct Node *root) {
    if (root == NULL) {
        return 0;
    }

    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main() {
    struct Node *root = NULL;
    int choice, element;

    do {
        printf("\n1. Insert an element\n");
        printf("2. Preorder traversal\n");
        printf("3. Inorder traversal\n");
        printf("4. Postorder traversal\n");
        printf("5. Find smallest element\n");
        printf("6. Find largest element\n");
        printf("7. Delete an element\n");
        printf("8. Count the total number of nodes\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                root = insert(root, element);
                break;
            case 2:
                printf("Preorder Traversal: ");
                preorderTraversal(root);
                printf("\n");
                break;
            case 3:
                printf("Inorder Traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder Traversal: ");
                postorderTraversal(root);
                printf("\n");
                break;
            case 5:
                if (root != NULL) {
                    printf("Smallest Element: %d\n", findSmallest(root)->data);
                } else {
                    printf("Tree is empty\n");
                }
                break;
            case 6:
                if (root != NULL) {
                    printf("Largest Element: %d\n", findLargest(root)->data);
                } else {
                    printf("Tree is empty\n");
                }
                break;
            case 7:
                printf("Enter the element to delete: ");
                scanf("%d", &element);
                root = deleteNode(root, element);
                break;
            case 8:
                printf("Total Number of Nodes: %d\n", countNodes(root));
                break;
            case 9:
                printf("Exiting the program\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 9);

    return 0;
}
