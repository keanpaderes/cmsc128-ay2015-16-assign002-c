/*
    Functions that does simple bioinformatics work.
    Created by: Irvin Kean Paulus T. Paderes
    Section: AB-3L
*/

int getHammingDistance(char *str1, char *str2){
    /*
        Counts the number of different characters at each index in both strings.
    */
    int len1, len2, index, count = 0;
    
    //Gets the length of both strings.
    len1 = strlen(str1);
    len2 = strlen(str2);
    
    //Catcher if both strings are not of equal length or one of them has size 0.
    if(len1 != len2 || len1 == 0 || len2 == 0) return -1;
    
    //Counts all of the characters not equal to each other at that index.
    for(index = 0; index < len1; index++){
        if(str1[index] != str2[index]) count++;
    }
    
    return count;
}

int countSubstrPattern(char *original, char *pattern){
    /*
        Counts the number of the pattern in the given original string.
    */
    int len1, len2, x, origIndex, patIndex, count = 0;
    int checkSub;
    
    //Gets the sizes of both strings.
    len1 = strlen(original);
    len2 = strlen(pattern);
    
    //Traverses through the original and checks for the pattern's occurrence.
    for(x = 0; x < len1; x++){
        //If the current character matches the pattern's first index...
        if(original[x] == pattern[0]){
            checkSub = 1;
            //...checks if the whole substring exist.
            for(origIndex = x, patIndex = 0; patIndex < len2; origIndex++, patIndex++){
                if(original[origIndex] != pattern[patIndex]) checkSub = 0;
            }
            //If it is found in the original string, adds 1 to the counter.
            if(checkSub == 1){
                count++;
            }   
        }
    }
    //Returns the number of count of the pattern.
    return count;
}

int isValidString(char *string, char *alphabet){
    /*
        Checks if the string is based on the letters of a given alphabet.
    */
    int len1, len2, alphabetIndex, stringIndex, charCount;
    //Gets the sizes of both strings.
    len1 = strlen(string);
    len2 = strlen(alphabet);
    
    //Checks each letter of the string if it exist in the alphabet.
    for(stringIndex = 0; stringIndex < len1; stringIndex++){
        charCount = 0; //Counts the current character
        //Traverses the alphabet.
        for(alphabetIndex = 0; alphabetIndex < len2; alphabetIndex++){
            if(string[stringIndex] == alphabet[alphabetIndex]) charCount++;
        }
        //If the character is not found in the string,
        if(charCount == 0) return 0;
    }
    //Returns 1 if all chars in the alphabet is found in the string.
    return 1;
}

int getSkew(char *genome, int nthNucleotide){
    /*
        Computes the G-C skew of the given genome.
        NOTE: It is assumed that parameters are error proof at this point.
    */
    int lengthGenome, genomeIndex, gcount = 0, ccount = 0, gcSkew;
    //Gets the size of the genome.

    //Checks each letter of the string if it exist in the alphabet.
    for(genomeIndex = 0; genomeIndex < nthNucleotide; genomeIndex++){
        if(genome[genomeIndex] == 'G') gcount++;
        else if(genome[genomeIndex] == 'C') ccount++;
    }
    
    gcSkew = gcount - ccount;
    return gcSkew;
}

int getMaxSkew(char *genome, int nthNucleotide){
    /*
        Gets the maximum G-C skew from the n nucleotides.
        NOTE: It is assumed that parameters are error proof at this point.
    */
    int genomeIndex, currSkewVal, maxSkewVal;
    
    //Gets the first skew and assigns it as the initial maximum skew value.
    maxSkewVal = getSkew(genome, 1);
    
    //Gets the skew values at each nucleotide.
    for(genomeIndex = 0; genomeIndex < nthNucleotide; genomeIndex++){
        currSkewVal = getSkew(genome, genomeIndex+1);
        if(currSkewVal > maxSkewVal) maxSkewVal = currSkewVal;
    }

    return maxSkewVal;
}

int getMinSkew(char *genome, int nthNucleotide){
    /*
        Gets the minimum G-C skew from the n nucleotides.
        NOTE: It is assumed that parameters are error proof at this point.
    */
    int genomeIndex, currSkewVal, minSkewVal;
    
    //Gets the first skew and assigns it as the initial minimum skew value.
    minSkewVal = getSkew(genome, 1);
    
    //Gets the skew values at each nucleotide.
    for(genomeIndex = 0; genomeIndex < nthNucleotide; genomeIndex++){
        currSkewVal = getSkew(genome, genomeIndex+1);
        if(currSkewVal < minSkewVal) minSkewVal = currSkewVal;
    }

    return minSkewVal;
}