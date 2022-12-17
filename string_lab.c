#include "string_lab.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *_strremove(char *str, const char ch){
    if(str == NULL){
        return NULL;
    }
    char *ptr = str;
    while(*ptr){
        if(*ptr == ch){
            memmove(ptr, ptr + 1, strlen(ptr));
        }
        else{
            ptr++;
        }
    }
    return str;
}

int _strcountchar(const char *str, const char ch){
    if(str == NULL){
        return -1;
    }
    char *flag = strchr(str, (int) ch);
    if(flag == NULL){
	return -1;
    }
    int count = 0;
    while(flag != NULL){
        count++;
        flag = strchr(flag + 1, (int) ch);
    }
    return count;
}

char *_strdelspaces(char *str){
    if(str == NULL){
	return NULL;
    }
    int len = strlen(str);
    for(int i = 0; i < len; i++){
        if(str[i] == ' '){
	    while(str[i + 1] == ' ' && str[i + 1] != '\0'){
            	memmove(&str[i], &str[i + 1], len - i);
	    }
        }
    }
    return str;
}

char *_strtolower(char *str){
    if(str == NULL){
        return NULL;
    }
    for(int i = 0; i < strlen(str); i++){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            str[i] += 32;
        }
    }
    return str;
}

char *_strtoupper(char *str){
    if(str == NULL){
        return NULL;
    }
    for(int i = 0; i < strlen(str); i++){
        if(str[i] >= 'a' && str[i] <= 'z'){
            str[i] -= 32;
        }
    }
    return str;
}

int _strcmp(const char *str1, const char *str2){
    int len = (strlen(str1) > strlen(str2)) ? strlen(str1) : strlen(str2);
    for(int i = 0; i < len; i++){
        if(str1[i] != str2[i]){
            return str1[i] - str2[i];
        }
    }
    return 0;
}

char *_strreverse(const char *str1){
    if(str1 == NULL){
        return NULL;
    }
    int len1 = strlen(str1);
    char *str2 = (char*)malloc((len1 + 1) * (sizeof(char)));
    for(int i = 0; i < len1; i++) {
        str2[i] = str1[len1 - i - 1];
    }
    str2[len1] = '\0';
    return str2;
}

int _atoi(const char *str){
    int sp_index = 0;
    while(str[sp_index] == ' '){
	sp_index++;
    }
    int sgn = 1;
    int result = 0;
    for(int i = sp_index; i < strlen(str); i++){
	if(str[i] == '-'){
	    sgn = -1;
	    continue;
	}
	if(str[i] == ' '){
	    break;
	}
	if(str[i] >= '0' && str[i] <= '9'){
	    result = result * 10 + (str[i] - '0');
	}
    }
    return result * sgn;
    
}

char *_strchr(char *str, int ch){
    if(str == NULL){
        return NULL;
    }
    for(int i = 0; i < strlen(str); i++){
        if(str[i] == ch){
            return &str[i];
        }
    }
    return NULL;
}

char *_strstr(const char *str, const char *substr){
    if(str == NULL || substr == NULL){
        return NULL;
    }
    for(int i = 0; i < strlen(str); i++){
        if(str[i] == substr[0]){
            int j = 0;
            while(str[i + j] == substr[j] && j < strlen(substr)){
                j++;
            }
            if(j == strlen(substr)){
                return (char*) &str[i];
            }
        }
    }
    return NULL;
}
