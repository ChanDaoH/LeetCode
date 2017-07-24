#include<stdio.h>
#include<stdlib.h>

int cmpfunc(const void * a, const void * b)
{
	return ( *(int*)a - *(int*)b );
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize) {
 	   int m,n,i,j;
 	   int **p;
 	   int size;
 	   int sum;
 	   p = (int **)malloc(sizeof(int *)*100);
 	   qsort(nums,numsSize,sizeof(int),cmpfunc);
 	   size = 0;
 	   *returnSize = 0;
 	   for(m=0;m<numsSize - 3;m++ ){
			if(nums[m]+nums[m+1]+nums[m+2]+nums[m+3] > target) break;	//最小比target大 
			if(nums[m]+nums[numsSize-1]+nums[numsSize-2]+nums[numsSize-3] < target) continue; 
			
			for(n=m+1;n<numsSize-2;n++ ){	//3Sum 
				if(nums[m]+nums[n]+nums[n+1]+nums[n+2] > target) break;	//最小比target大 
				if(nums[m]+nums[n]+nums[numsSize-1]+nums[numsSize-2] < target) continue; 
				i = n+1;
				j = numsSize-1;
				while( i < j ){
					sum = nums[m]+nums[n]+nums[i]+nums[j];
					if(sum==target){
						*(p+size) = (int*)malloc(sizeof(int)*4);
						p[size][0] = nums[m]; p[size][1] = nums[n];
						p[size][2] = nums[i]; p[size][3] = nums[j];
						size++;
						while( nums[i]==nums[i+1]) i++;
						i++;
						while( nums[j]==nums[j-1]) j--;
						j--;
					}else if(sum<target){
						while( nums[i]==nums[i+1]) i++;
						i++;
					}else{
						while( nums[j]==nums[j-1]) j--;
						j--;
					}
				}
				while(nums[n]==nums[n+1]) n++;
			}
			while(nums[m] == nums[m+1]) m++;
 	   }
 	   *returnSize = size;
 	   return p;
}


int main()
{
	int s[6] = {1,0,-1,0,-2,2};
	int returnSize;
	int **p;
	p = fourSum(s,6,0,&returnSize);
	for( int i = 0; i < returnSize; i++ ){
		printf("[%d,%d,%d,%d]\n",p[i][0],p[i][1],p[i][2],p[i][3]);
	}
}
