/*
74. Search a 2D Matrix
*/

bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    int min,max;
    int midi,midj,mid;
    if( matrixRowSize < 1 || matrixColSize < 1 ) return false;
    min = 0;
    max = matrixRowSize*matrixColSize-1;
    while( min <= max ){
		mid = (min+max)/2;
		midi = mid/matrixColSize;
		midj = mid - midi*matrixColSize;
		if ( matrix[midi][midj] < target ){
			min = mid+1;
		}else if( matrix[midi][midj] > target ){
			max = mid-1;
		}else{
			return true;
		}
    }
    return false;
}
