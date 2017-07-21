#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int cmpfunc(const void * a, const void * b);

int threeSumClosest(int* nums, int numsSize, int target) {
    int result;
	int k;	//�̶�һ��ֵ 
	int min,max;
	int tmp;
	int marginr;	//result��target�Ĳ� 
	int margint;	//result��tmp�Ĳ� 
	qsort(nums,numsSize,sizeof(int),cmpfunc);
	for ( k = 0; k < numsSize-2; k++ ){
		min = k+1;
		max = numsSize-1;
		if( k == 0 )
			result = nums[k]+nums[min]+nums[max];
		marginr = abs(result-target);
		while(min<max){
			tmp = nums[k]+nums[min]+nums[max]; //��ǰ3sum 
			margint = abs(tmp-target);
			if( margint == 0 ){
				return target;
			}else if( tmp < target ){
				if( margint < marginr ){ //��ǰ��ֵ��С����¼result 
					result = tmp;
					marginr = abs(result-target); //���¼�¼��ֵ 
				}
				while( nums[min] == nums[min+1] ) min++;
				min++;
			}else{
				if ( margint < marginr ){
					result = tmp;
					marginr = abs(result-target); //���¼�¼��ֵ 
				}
				while( nums[max] == nums[max-1] ) max--;
				max--;
			}
		}
		while(nums[k]==nums[k+1]) k++;
	}
	return result;
}



int cmpfunc(const void * a, const void * b)
{
	return ( *(int*)a - *(int*)b );
}

int main()
{
	int target;
	int nums[4] = {-1,2,1,-4};
	int result;
	result = threeSumClosest(nums,4,1);
	printf("%d\n",result);
}
