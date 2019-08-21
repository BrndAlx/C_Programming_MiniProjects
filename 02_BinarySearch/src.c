//To use a Binary Search on an array the array must be sorted.

#include <stdio.h>


int recursiveBinarySearch(int arr[],int zero, int max , int number){
	if (max>=0){
		int mid = zero+(max-zero)/2;
		//If element is at middle
		if(arr[mid]==number){
			return mid;
		}
		//If element is smaller then middle then it can be only found in the left subarray
		if(arr[mid]>number){
			return recursiveBinarySearch(arr,zero,mid-1,number);
		}
		//If the element is bigger then middle then it can be only found in the right subarray
		return recursiveBinarySearch(arr,mid+1,max,number);
	}

	return -1;
}

int iterativeBinarySearch(int arr[],int lower, int upper ,int number){
	while(lower<=upper){
		int mid=lower+(upper-lower)/2;
		if(arr[mid]==number){
			return mid;
		}
		//If element is smaller then middle then it can be only found in the left sub-array
		if(arr[mid]<number){
			lower=mid+1;
		}else{
		//If element is bigger then middle then it can be only found in the right sub-array
			upper=mid-1;
		}
	}
	return -1;

}

int main(void){
	int arr[]={2 ,3 ,5, 8 ,10 ,20 ,50 ,70 ,80};
	int n=sizeof(arr)/sizeof(arr[0]);
	int nr_to_find;

	printf("Please insert the number you wish to find: ");
	scanf("%d",&nr_to_find);

	int result=recursiveBinarySearch(arr,0,n-1,nr_to_find);
//	int result=iterativeBinarySearch(arr,0,n-1,nr_to_find);


	(result==-1) ? printf("Element is not present in the array.\n")
				  :printf("Element is present at index %d",result);

	return 0;
}
