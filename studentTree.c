#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <search.h> // tsearch 및 twalk를 사용하기 위해 추가

struct student {
    char *name;
    int mid;
    int final;
};

struct student *root = NULL;

int compare(const void *cp1, const void *cp2) {
    return strcmp(((struct student *)cp1)->name, ((struct student *)cp2)->name);
}

void print_node(const void *nodeptr, VISIT order, int level) {
    if (order == preorder || order == leaf) {
        printf("이름=%-20s, 중간점수=%d, 기말점수=%d\n",
               (*(struct student **)nodeptr)->name,
               (*(struct student **)nodeptr)->mid,
               (*(struct student **)nodeptr)->final);
    }
}

// 학생을 찾는 함수
void find_student(char *name) {
    struct student key = {name, 0, 0}; // 비교를 위한 임시 키 생성
    struct student **result = (struct student **)tfind((void *)&key, (void **)&root, compare);

    if (result !=NULL) {
        printf("찾은 학생: 이름=%s, 중간점수=%d, 기말점수=%d\n",
               (*result)->name, (*result)->mid, (*result)->final);
    } else {
        printf("학생 \"%s\"을(를) 찾을 수 없습니다.\n", name);
    }
}

int main() {
    int n;
    struct student **nodeptr; // 학생 구조체의 포인터 배열
    struct student **ret;
    
    printf("학생 수를 입력하세요: ");
    scanf("%d", &n);
    
    // 학생 수만큼 동적으로 메모리 할당
    nodeptr = malloc(n * sizeof(struct student *));
    if (nodeptr == NULL) {
        fprintf(stderr, "메모리 할당 실패\n");
        return 1; // 오류가 발생했을 때 프로그램 종료
    }
    
    for (int i = 0; i < n; i++) {
        nodeptr[i] = malloc(sizeof(struct student)); // 각 학생 구조체에 메모리 할당
        if (nodeptr[i] == NULL) {
            fprintf(stderr, "메모리 할당 실패\n");
            return 1; // 오류가 발생했을 때 프로그램 종료
        }
        
        nodeptr[i]->name = malloc(20 * sizeof(char)); // 이름을 위한 메모리 할당
        if (nodeptr[i]->name == NULL) {
            fprintf(stderr, "메모리 할당 실패\n");
            return 1; // 오류가 발생했을 때 프로그램 종료
        }
    }

    for (int i = 0; i < n; i++) {
        printf("이름, 중간 점수, 기말 점수를 입력하세요: ");
        scanf("%s%d%d", nodeptr[i]->name, &nodeptr[i]->mid, &nodeptr[i]->final);

        ret = (struct student **)tsearch((void *)nodeptr[i], (void **)&root, compare);
        printf("\"%s\"님이 ", (*ret)->name);
        if (*ret == nodeptr[i]) {
            printf("트리에 추가되었습니다.\n");
        } else {
            printf("트리에 이미 존재합니다.\n");
        }
    }

    twalk((void *)root, print_node);

     // 학생을 찾기 위해 이름을 입력받음
    char search_name[20];
    printf("검색할 학생의 이름을 입력하세요: ");
    scanf("%s", search_name);
    find_student(search_name);

    // 동적으로 할당한 메모리 해제
    for (int i = 0; i < n; i++) {
        free(nodeptr[i]->name); // 이름 메모리 해제
        free(nodeptr[i]); // 학생 구조체 해제
    }

    return 0;
}

