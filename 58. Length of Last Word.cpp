/*
58. Length of Last Word
*/


int lengthOfLastWord(char* s) {
    int len = 0,lenp = 0;
    for( int i = 0; s[i] != '\0';  ){
		if( s[i] == ' ' ){
			while( s[i] != '\0' && s[i] == ' ' ) i++;
			lenp = len;
			len = 0;
		}else{
			len++;
			i++;
		}
    }
    return len==0?lenp:len;
}
