#include<stdio.h>

int main(){
    char *s, a[6] = "hello";
    s = a;
    if(s != NULL){
        printf("%s", s);
    }
    
    return 0;
}