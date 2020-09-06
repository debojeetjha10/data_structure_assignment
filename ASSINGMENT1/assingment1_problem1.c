#include <stdio.h>
int SIZE = 25;	
int largestindex(int arr[],int size){
	int value = 0;
	int max = arr[0];
	for( int i = 1;i<size;i++){
		if(arr[i]>max){
			value = i;
			max = arr[i];
		}
	}
	return value;
}
int thirdlargestnumber(int arr[],int size){
	for(int i = 0;i<2;i++){
		arr[largestindex(arr,size)] = -100000;
	}
	return arr[largestindex(arr,size)];
}
int main(){
	int arr[25];
	int size = 0;
	printf("Enter the size of the array: ");
	scanf("%d",&size);
	printf("Enter the array: ");
	for(int i = 0;i<size;i++){
		scanf("%d",&arr[i]);
	}
	printf("The third largest number of the array is %d\n",thirdlargestnumber(arr,size));
	return 0;
}
/* output: 
Enter the size of the array: 6
Enter the array: 54 4 65  465 8 21 
The third largest number of the array is 54
 */