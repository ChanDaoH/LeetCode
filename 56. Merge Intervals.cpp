/*
56. Merge Intervals
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
*/

#include<stdio.h>
#include<stdlib.h>

struct Interval {
	int start;
    int end;
};

int cmpfunc(const void * a, const void * b);
struct Interval* merge(struct Interval* intervals, int intervalsSize, int* returnSize) {
    struct Interval* res;
    int size;
    bool isInclude;
    //按照start升序排序或按照end降序排序，为了确定一边的包括，避免乱序导致的一开始全部分散，最后一个区间包括所有 
    qsort(intervals,intervalsSize,sizeof(struct Interval),cmpfunc); 
    res = (struct Interval*)malloc(sizeof(struct Interval)*intervalsSize);	//申请结构体个数大小的结构体 
    size = 0;	//即returnSize 
    for( int i = 0; i < intervalsSize; i++ ){
		isInclude = false;	//当前判断的区间是否与现有的区间有重叠 
		for( int j = 0; j < size; j++ ){
			if( res[j].start <= intervals[i].end ){
				if( intervals[i].start <= res[j].end ){
					res[j].start = res[j].start<intervals[i].start?res[j].start:intervals[i].start;
					res[j].end = res[j].end>intervals[i].end?res[j].end:intervals[i].end;
					isInclude = true;
					break;
				}
			}
		}
		if( !isInclude ){
			res[size].start = intervals[i].start;
			res[size].end = intervals[i].end;
			size++;
		}
    }
    *returnSize = size;
    return res;
}
int cmpfunc(const void * a, const void * b)
{
	return ( (*(struct Interval*)a).start - (*(struct Interval*)b).start );
}


int main()
{
	struct Interval intervals[5] = {
		{2,3},
		{4,5},
		{6,7},
		{8,9},
		{1,10}
	};
	int intervalsSize = 5;
	int returnSize;
	struct Interval *res;
	res = merge(intervals,intervalsSize,&returnSize);
	for( int i = 0; i < returnSize; i++ ){
		printf("[%d,%d] ",res[i].start,res[i].end);
	}
}














