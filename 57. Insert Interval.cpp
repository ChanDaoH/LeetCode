/*
57. Insert Interval
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
*/

#include<stdio.h>
#include<stdlib.h>


struct Interval {
	int start;
    int end;
};


struct Interval* insert(struct Interval* intervals, int intervalsSize, struct Interval newInterval, int* returnSize) {
    struct Interval* res;
    int size;
    int front,rear;		//合并的头尾指针 
    int i;
    front = 0; rear = intervalsSize;
    res = (struct Interval*)malloc(sizeof(struct Interval)*(intervalsSize+1));
    size = 0;
    for( i = 0; i < intervalsSize; i++ ){	//寻找第一个start比新区间start大的区间 
		if( newInterval.start <  intervals[i].start ){	
			front = i - 1;	//队首为第一个比新区间start小的下标 
			break;
		}
    }
    if( front < 0 ) front = 0;
    for( i = front; i < intervalsSize; i++ ){
		if( newInterval.end <= intervals[i].end ){	//寻找第一个end比新区间end大的区间 
			rear = i+1;
			break;
		}
    }
    //if( rear > intervalsSize ) rear = intervalsSize;
    for( i = 0; i < front; i++ ){	//将无影响的区间赋值 
		res[size].start = intervals[i].start;
		res[size].end = intervals[i].end;
		size++;
    }
    for( i = front; i < rear; i++ ){	//将有影响的区间合并 
		if( newInterval.start > intervals[i].end ){
			res[size].start = intervals[i].start;
			res[size].end = intervals[i].end;
			size++;
		}else if( newInterval.end < intervals[i].start ){	//修改end，跳出，为了按顺序递增存储 
			rear = i;
			break;
		}else{						//合并区间 
			newInterval.start = intervals[i].start < newInterval.start?intervals[i].start:newInterval.start;
			newInterval.end = newInterval.end > intervals[i].end?newInterval.end:intervals[i].end;
		}
    }
    res[size].start = newInterval.start;	//将合并区间合并到结果中 
    res[size].end = newInterval.end;
    size++;
    for( i = rear; i < intervalsSize; i++ ){	//将剩下的合并到结果集中 
		res[size].start = intervals[i].start;
		res[size].end = intervals[i].end;
		size++;
    }
    *returnSize = size;
    return res;
}

int main()
{
	struct Interval newInterval = {
		2,5
	};
	struct Interval intervals[3] ={
		{1,3},
		{6,9}
	}; 
	int intervalsSize = 2;
	int returnSize;
	struct Interval* res;
	res = insert(intervals,intervalsSize,newInterval,&returnSize);
	for( int i = 0; i < returnSize; i++ ){
		printf("[%d,%d] ",res[i].start,res[i].end);
	}
}





















