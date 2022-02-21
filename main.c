#include <stdio.h>
#include <stdlib.h>
//function returns the token size of the str
int tokenizerSize(char * str,char deli){
    int count = 2;
    int i = 0;
    while(str[i] != NULL){
        if(str[i] == deli) count++;
        ++i;
    }
    return count;
}

//function is for finding the array size
int array_size(char* str){
    for(int i = 0; i< 256;++i){
        if(str[i] == NULL){
            return i;
        }
    }
    return 256;
}
//function splits a string by start to end position
char* split_str(char*str,int start,int end){
    char * new_str = malloc((end-start + 1) *sizeof(char));
    int i = start;
    while(i < end){
        new_str[i-start] = str[i];
        ++i;
    }
    new_str[i] = NULL;
    return new_str;
}
/* Returns a freshly allocated zero-terminated vector of freshly allocated
   delimiter-separated tokens from zero-terminated str.
   For example, tokenize("hello world string"), with a character delimiter
   of a space " " would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string"
     tokens[3] = 0
*/
char** tokenize(char* str, char deli){
    int token_size = tokenizerSize(str,deli);
    char ** tokens= malloc(token_size * sizeof(char *));
    tokens[0] = malloc(6);
    tokens[1] = malloc(6);
    int k = 0;
    int temp = 0;
    int i = 0;
    while(str[k] != NULL)
    {
        if(str[k] == deli)
        {
            tokens[i] = split_str(str,temp,k);
            temp = k;
            ++i;
        }
        ++k;
    }
    tokens[i] = split_str(str,temp+1,k+1);
    tokens[i+1] = NULL;
    return tokens;
}

void print_all_tokens(char** tokens){
    int i = 0;
    while(tokens[i] != NULL){
        printf("Token [%d]: %s\n",i,tokens[i]);
        ++i;
    }
    printf("Token[%d]: NULL\n",i);
}
int main() {
    printf("Please enter a string:");
    char *str = malloc(256);
    for(int i = 0; i < 256;++i){
        str[i] = NULL;
    }
    fgets(str,100,stdin);
    printf("Please enter a delimiter:");
    str = realloc(str,sizeof(char) * array_size(str)+1);//frees unnecessary memory
    char deli;
    //char str[] = {'H','e','l','l','o',',','W','o','r','l','d',NULL};
    //char deli = ',';
    scanf(" %c",&deli);
    printf("\nHere is your string: %s\n",str);
    printf("Here is your delimiter: %c\n",deli);
    char ** token = tokenize(str,deli);
    print_all_tokens(token);
    return 0;
}
