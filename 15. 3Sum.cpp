#include<stdio.h>
#include<stdlib.h>

int cmpfunc(const void * a, const void * b);

int** threeSum(int* nums, int numsSize, int* returnSize) {
	int L,R;
	int min,mid,max;
	int **p;
	int sum,tmp;
	int lt,rt;
	int i = 0;
	p = (int**)malloc(sizeof(int*)*10);
	L = min = 0;
	R = max = numsSize - 1;
	mid = (min+max)/2;
	*returnSize = 0;
    qsort(nums,numsSize,sizeof(int),cmpfunc);
    while( L < R ){
		sum = nums[L]+nums[R];
		min = L;
		max = R;
		mid = (min+max)/2;
		while(min<=max){
			tmp = sum + nums[mid];
			if( tmp == 0 ){
				if( mid!=L&&mid!=R ){
					*(p+i) = (int*)malloc(sizeof(int)*3);
					p[i][0] = nums[L];
					p[i][1] = nums[mid];
					p[i][2] = nums[R];
					i++;
					break;
				}else{
					min++;
				}
			}else if( tmp < 0 ){
				min = mid+1;
			}else{
				max = mid-1;
			}
			mid = (min+max)/2;
		}
		if(sum > 0){
			rt = R;
			while(nums[R]==nums[rt])
				R--;
		}else{
			lt = L;
			while(nums[L]==nums[lt])
				L++;
		}
    }
    *returnSize = i;
    return p;
}



int cmpfunc(const void * a, const void * b)
{
	return ( *(int*)a - *(int*)b );
}

int main()
{
	int nums[15] = {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
	int **p;
	int a;
	p = threeSum(nums,15,&a);
}
