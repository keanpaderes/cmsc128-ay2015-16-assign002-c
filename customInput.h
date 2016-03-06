char *getLine(FILE* fp, size_t size){
/*
    Gets string of unknown size.
    Reference: http://stackoverflow.com/questions/16870485/how-can-i-read-an-input-string-of-unknown-length
*/
    char *str;
    int ch;
    size_t len = 0;

    str = realloc(NULL, sizeof(char)*size);
    if(!str) return str;
    while(EOF!=(ch=fgetc(fp)) && ch != '\n'){
        str[len++]=ch;
        if(len==size){
            str = realloc(str, sizeof(char)*(size+=16));
            if(!str)return str;
        }
    }
    str[len++]='\0';

    return realloc(str, sizeof(char)*len);
}

void hammingDistance(){
/*
    Caller function for the getHammingDistance() function.
*/
    char *str1, *str2;
    int hd;
    
    getchar(); 
    printf("\nEnter string 1: ");
    str1 = getLine(stdin, 10);
    printf("\nEnter string 2: ");
    str2 = getLine(stdin, 10);
    
    hd = getHammingDistance(str1, str2);
    if(hd == -1) printf("Error! Strings are not equal!");
    else printf("\nThe hamming distance of %s and %s is %i.", str1, str2, hd);
    
    free(str1);
    free(str2);
}