#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[20];
    int midterm;
    int final;
    struct Student *left;
    struct Student *right;
};

struct Student *insert(struct Student *node, char *name, int midterm, int final) {
    if (node == NULL) {
        struct Student *newNode = (struct Student *)malloc(sizeof(struct Student));
        strcpy(newNode->name, name);
        newNode->midterm = midterm;
        newNode->final = final;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    if (strcmp(name, node->name) < 0)
        node->left = insert(node->left, name, midterm, final);
    else
        node->right = insert(node->right, name, midterm, final);
    return node;
}

void inorder(struct Student *node) {
    if (node != NULL) {
        inorder(node->left);
        printf("이름: %s, 중간 점수: %d, 기말 점수: %d\n", node->name, node->midterm, node->final);
        inorder(node->right);
    }
}

int main() {
    int n;
    struct Student *root = NULL;

    printf("학생 수를 입력하세요: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char name[20];
        int midterm, final;
        printf("이름, 중간 점수, 기말 점수를 입력하세요: ");
        scanf("%s %d %d", name, &midterm, &final);
        root = insert(root, name, midterm, final);
    }

    printf("학생 목록:\n");
    inorder(root);

    return 0;
}

