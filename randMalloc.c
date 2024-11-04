#include <stdlib.h>
#include <stdio.h>
int main(){
	int arrSize=0;
	printf("배열 원소 개수를 입력해주세요: ");
	scanf("%d", &arrSize);

	int *arr1, *arr2;
	arr1 = (int*)malloc(arrSize*sizeof(int)); //입력받은 사이즈로 동적할당함.
	arr2 = (int*)malloc(arrSize*sizeof(int));

	if(arr1==NULL || arr2==NULL){
	       	printf("메모리를 할당하지 못했습니다.");
		exit(-1);
	}

	for(int i=0; i<arrSize; i++){
		arr1[i] = rand()%100;
		arr2[i] = rand()%100;
	}
	
	for(int i=0; i<arrSize; i++){
		int sum=0;
		sum =arr1[i]+arr2[i];
		printf("%d\n", sum);
	}
	free(arr1);
	free(arr2);
}
	
