#include <stdio.h>

int linearSearch(int arr[],int size, int number){
	for (int i=0;i<size;i++){
		if(arr[i]==number){
			return i;
		}
	}
	return -1;
}

int main(){
	int arr[]={1,2,3,10,50,100,111,200};
	int number_to_find,result;

	printf("Please input the number you want to find: ");
	scanf("%d",&number_to_find);
	result=linearSearch(arr,sizeof(arr),number_to_find);
	(result == -1)?printf("Element is not in the array")
				  :printf("Element is present at index %d",result);
	return 0;
}

//Time complexity is O(n).
