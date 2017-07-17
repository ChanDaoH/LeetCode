#include<stdio.h>

bool isequalpastchar( char nowchar, char*s, int num )
{
    for ( int i = 0; i < num; i++ )
    {
        if ( nowchar == s[i] )
            return true;
    }
    return false;
}

int lengthOfLongestSubstring(char* s) {
    int length = 0;
    int maxLength = 0;
    char nowchar = '\0';
    int i = 0;
    char *str = s;
    while ( *str )
    {
		nowchar = *str;
        if (  !isequalpastchar(nowchar, s, i))
        {
            length++;
        }
        else
        {
            if ( maxLength < length )
                maxLength = length;
            length = 1;
        }
        str++;
        i++;
    }
    return maxLength;
}

int main()
{
	int length;
	char *s = "c";
	length = lengthOfLongestSubstring(s);
	printf("%d", length);
}
