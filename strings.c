
#include <stdio.h>

// Function to calculate string length
int strlength(char str[50]) {
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

// Function to compare two strings
int strcompare(char str1[50], char str2[50]) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return 1;// break;//return str1[i] - str2[i];
        }
        i++;
    }
    return 0;//return str1[i] - str2[i];
}

// Function to concatenate str2 to str1
void strconcat(char str1[50], char str2[50]) {
    int i = 0, j = 0;
    while (str1[i] != '\0') {
        i++;
    }
    while (str2[j] != '\0') {
        str1[i] = str2[j];
        i++;
        j++;
    }
    str1[i] = '\0';
}

int main() {
    char source1[50], source2[50];

    printf("Enter the first string: ");
    gets(source1);  // Use fgets in modern C

    printf("Enter the second string: ");
    gets(source2);  // Use fgets in modern C

    int len1 = strlength(source1);
    int len2 = strlength(source2);

    printf("Length of first string: %d\n", len1);
    printf("Length of second string: %d\n", len2);
	if (len1 != len2){
    	if (strcompare(source1, source2) == 0)
        	printf("Strings are equal\n");}
    else {
        printf("Strings are not equal\n");
        strconcat(source1, source2);
        printf("Concatenated string: %s\n", source1);
    }

    return 0;
}