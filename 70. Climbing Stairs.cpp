/*
70. Climbing Stairs
*/

int climbStairs(int n) {
    int *a;
    a = (int*)malloc(sizeof(int)*(n+1));
    a[0] = 1;
    a[1] = 1;
    for( int i = 2; i <= n; i++ ){
		a[i] = a[i-1]+a[i-2];
    }
    return a[n];
}
int main()
{
	
}
