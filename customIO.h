/*
    Functions required by the CL interface to use the bioinfoc-lib.h library.
*/

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
    if(hd == -1) printf("Error! Strings are not equal or one of the strings is empty!");
    else printf("\nThe hamming distance of %s and %s is %i.", str1, str2, hd);
    
    free(str1);
    free(str2);
}

void subPattern(){
/*
    Caller function for the countSubstrPattern() function.
*/
    char *str1, *str2;
    int occurence;
    
    getchar(); 
    printf("\nEnter original string: ");
    str1 = getLine(stdin, 10);
    printf("\nEnter pattern to be counted: ");
    str2 = getLine(stdin, 10);
    
    occurence = countSubstrPattern(str1, str2);
    printf("\nThe number of occurence of %s in %s is %i.", str2, str1, occurence);
    
    free(str1);
    free(str2);
}

void validString(){
/*
    Caller function for the isValidString() function.
*/
    char *str1, *str2;
    int boolean;
    
    getchar(); 
    printf("\nEnter string: ");
    str1 = getLine(stdin, 10);
    printf("\nEnter alphabet: ");
    str2 = getLine(stdin, 10);
    
    if(isValidString(str1, str2)) printf("\nThe string %s is valid in the alphabet %s.", str1, str2);
    else printf("\nThe string %s is NOT valid in the alphabet %s.", str1, str2);
    
    free(str1);
    free(str2);
}

void gcSkew(){
/*
    Caller function for the getSkew() function.
*/
    char *str;
    int index;
    int skew;
    
    getchar(); 
    printf("\n\nEnter genome: ");
    str = getLine(stdin, 10);
    printf("\nEnter the position of the ending nucleotide (Does not use zero-indexing): ");
    fscanf(stdin, "%i", &index);
    
    //Error-catching before calling the function.
    if(strlen(str) == 0){
        //Checks if input genome has length of zero.
        printf("\nGenome's length must be greater than 0!");
        gcSkew();
        goto end;
    } else if (index <= 0){
        //Checks if input index is not zero or less.
        printf("\nIndex given must not be zero or lower!");
        gcSkew();
        goto end;
    } else if (index-1 >= strlen(str)){
        //Checks if index given is out of bounds.
        printf("\nIndex out of bounds!");
        gcSkew();
        goto end;
    } else{
        skew = getSkew(str, index);    
    }
    
    printf("\nThe G-C Skew of genome %s is %i.", str, skew);
    end:
        free(str);
}

void maxSkew(){
/*
    Caller function for the getMaxSkew() function.
*/
    char *str;
    int index;
    int max;
    
    getchar(); 
    printf("\n\nEnter genome: ");
    str = getLine(stdin, 10);
    printf("\nEnter the position of the ending nucleotide (Does not use zero-indexing): ");
    fscanf(stdin, "%i", &index);
    
    //Error-catching before calling the function.
    if(strlen(str) == 0){
        //Checks if input genome has length of zero.
        printf("\nGenome's length must be greater than 0!");
        maxSkew();
        goto end;
    } else if (index <= 0){
        //Checks if input index is not zero or less.
        printf("\nIndex given must not be zero or lower!");
        maxSkew();
        goto end;
    } else if (index-1 >= strlen(str)){
        //Checks if index given is out of bounds.
        printf("\nIndex out of bounds!");
        maxSkew();
        goto end;
    } else{
        max = getMaxSkew(str, index);    
    }
    
    printf("\nThe Maximum G-C Skew of genome %s is %i.", str, max);
    end:
        free(str);
}

void minSkew(){
/*
    Caller function for the getMinSkew() function.
*/
    char *str;
    int index;
    int min;
    
    getchar(); 
    printf("\n\nEnter genome: ");
    str = getLine(stdin, 10);
    printf("\nEnter the position of the ending nucleotide (Does not use zero-indexing): ");
    fscanf(stdin, "%i", &index);
    
    //Error-catching before calling the function.
    if(strlen(str) == 0){
        //Checks if input genome has length of zero.
        printf("\nGenome's length must be greater than 0!");
        minSkew();
        goto end;
    } else if (index <= 0){
        //Checks if input index is not zero or less.
        printf("\nIndex given must not be zero or lower!");
        minSkew();
        goto end;
    } else if (index-1 >= strlen(str)){
        //Checks if index given is out of bounds.
        printf("\nIndex out of bounds!");
        minSkew();
        goto end;
    } else{
        min = getMinSkew(str, index);    
    }
    
    printf("\nThe Minimum G-C Skew of genome %s from the first to nucleotide #%i is %i.", str, index, min);
    end:
        free(str);
}