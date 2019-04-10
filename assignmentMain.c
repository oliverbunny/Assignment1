#include <stdio.h>
#include <math.h>
int main(){

    int k = 1;  
    char str[] = "abcDEFghiJklMNopqRstuVwxyz";
    scanf("%s", str);
  
  
    int j;
    for(j=0; str[j] != '\0'; j++){
        
        if(str[j]>=97 && str[j]<=122){
            str[j] = str[j] - 32; 
        } 
        
        if(str[j]>=65 && str[j]<=90){
            str[j] = (str[j] + k);
            printf("%c", str[j]);
        } else 
        
        printf("%c", str[j]);
    }

return 0;
}