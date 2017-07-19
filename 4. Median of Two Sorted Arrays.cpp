#include<stdio.h>
#include<stdlib.h>
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size);

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int len;	//两个数组的总长度
	int k;	//所要求的第k个数(中位数) 
	int t;
	int mid1,mid2; 
	int max1,max2;
	int min1,min2;
	int tag;	//标志是否返回两个数的平均 
	int x1,x2;
	len = nums1Size + nums2Size;
	if (len%2 == 0){
		k = len/2;
		tag = 1;
	}else{
		k = len/2+1;
		tag = 0;
	}
	min1=min2=mid1=mid2=0;
	max1=nums1Size-1;
	max2=nums2Size-1;
	
	while(k > 1 && min1 <= max1 && min2 <= max2){
		t = k/2;//要丢弃的数的个数 
		if ( nums1Size < t || nums2Size < t ){
			//要丢弃的数的个数大于任一数组大小,直接丢弃小数组大小数量的数 
			t = nums1Size<nums2Size? nums1Size:nums2Size;
		}
		mid1 = min1+t-1;
		mid2 = min2+t-1;
		x1 = nums1[mid1];
		x2 = nums2[mid2];
		if (x1 < x2) min1 = mid1 + 1;	//舍去 
		else min2 = mid2 + 1;
		k = k - t;	//找剩下的第k个数 
	}
	//一个数组丢弃完毕 
	if (  min1 > max1 ){
		if (tag) return (1.0*(nums2[min2+k-1] + nums2[min2+k])/2.0);
		else return nums2[min2 + k-1];
	}else if ( min2 > max2 ){
		if (tag) return (1.0*(nums1[min1+k-1] + nums1[min1+k])/2.0);
		else return nums1[min1 + k-1];	
	}else{	//两个数组都剩余 
		if (tag){ //两个数组当中的最小两个数，有可能分布在一个数组中 
			int p1 = nums1[min1]<nums2[min2]?nums1[min1]:nums2[min2];
			int p2;
			if(p1==nums1[min1]){
				p2=((min1==max1)||(nums2[min2]<nums1[min1+1]))?nums2[min2]:nums1[min1+1];
			}else{
				p2=((min2==max2)||(nums1[min1]<nums2[min2+1]))?nums1[min1]:nums2[min2+1];
			}
			return (1.0*(p1 + p2)/2.0);
		}else{	//两个数组中最小的数 
			return nums1[min1]<nums2[min2]?nums1[min1]:nums2[min2];
		}
	}
}

int main()
{
	int nums1[2] = {1,2};
	int nums2[2] = {3,4};
	double result;
	result = findMedianSortedArrays(nums1,2,nums2,2);
	printf("%f",result);
}
