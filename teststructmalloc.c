#include <stdio.h>
#include <stdlib.h>
struct student {
	int id;
	char name[20];
};

int main(){
	int max,i;
	struct student *ptr;

	printf("입력할 학생의 수는?");
	scanf("%d", &max);

	/*사용자가 입력한 수만큼 메모리 할당*/
	ptr = (struct student *) malloc(max *sizeof(struct student));

	/*메모리 할당에 실패한 경우*/
	if(ptr==NULL){
                printf("메모리를 할당하지 못했습니다.");
                exit(-1);
        }

	printf("%d 학생의 학번과 이름을 입력하세요.\n", max);
	for(int i=0; i<max; i++){
		scanf("%d %s", &ptr[i].id, ptr[i].name);
	}

	printf("학생리스트: \n");
	for(int i=0; i<max; i++)
		printf("%d %s\n", ptr[i].id,ptr[i].name);
	printf("\n");
	free(ptr);
}

