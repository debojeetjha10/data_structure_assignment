#include <stdio.h>
int SIZE = 25;
void swap(int *a, int *b){
	*a = *a - *b;
	*b = *a + *b;
	*a = *b - *a;
}
void reverse_array(int arr[],int size){
	for(int i = 0;i<size/2;i++){
		swap(&arr[i],&arr[size-i-1]);
	}
}
int main(){
	int arr[25];
	int size;
	printf("Enter the size of the array: ");
	scanf("%d",&size);
	printf("\nEnter the array: ");
	for(int i = 0;i<size;i++){
		scanf("%d",&arr[i]);
	}
	reverse_array(arr,size);
	printf("The reversed array is : ");
	for(int i = 0;i<size;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	return 0;
}
/*output:
Enter the size of the array: 5 

Enter the array:  654 6 14 96 1 
The reversed array is : 1 96 14 6 654 
*/