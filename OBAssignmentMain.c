//I cant commit to github because of authentication problems
//Created remote repo with SSH as shown in the lecture

#include <stdio.h>
#include "task_select.h"

//#define FILENAME_1 "input.txt"
//#define FILENAME_2 "input.txt"
//#define FILENAME_3 "input.txt"
//#define FILENAME_4 "input.txt"

int key = 7;  
char str[] = "HAAHJR!!";
char key2[] = "QWERTYUIOPASDFGHJKLZXCVBNM";
char rotEncrypt();
char rotDecrypt();
char subsEncrypt();
char subsDecrypt();

int main(){
//    int key = 0;
    
    printf("The selected task = %d\n", TASK_NUMBER);
    
    if(TASK_NUMBER == 1){
        /* Read in from file*/
//        FILE * file_pointer;                                  
//        
//        file_pointer = fopen(FILENAME_1, "r");
//        
//        if (file_pointer == NULL) {
//            printf("Error opening file!\n");
//            return -1;
//        }
//        
//        fscanf(file_pointer, "%s %d", &str, &key);
        
        printf("Rotation Cipher Task.\n");
        printf("Message: %s\nKey: %d\n", str, key);
        printf("Cipher text: ");
        printf("%c", rotEncrypt(str));
        printf("\n");
//        fclose(file_pointer);
    } else if(TASK_NUMBER == 2){
         /* Read in from file*/
//        FILE * file_pointer;
//        
//        file_pointer = fopen(FILENAME_2, "r");
//        
//        if (file_pointer == NULL) {
//            printf("Error opening file!\n");
//            return -1;
//        }
//        
//        fscanf(file_pointer, "%s %s", &str, &key2);
        printf("Rotation Decipher Task.\n");  
        printf("Cipher text: %s\nKey: %d\n", str, key);
        printf("Message: ");
        printf("%c", rotDecrypt(str));
        printf("\n");
//        fclose(file_pointer);
    } else if(TASK_NUMBER == 3){
         /* Read in from file*/
//        FILE * file_pointer;
//        
//        file_pointer = fopen(FILENAME_3, "r");
//        
//        if (file_pointer == NULL) {
//            printf("Error opening file!\n");
//            return -1;
//        }
//        
//        fscanf(file_pointer, "%s %s", &str, &key2);
        
        printf("Substitution Cipher Task.\n");
        printf("Message: %s\nKey: %s\n", str, key2);
        printf("Cipher text: ");
        printf("%c", subsEncrypt(str));
        printf("\n");
//        fclose(file_pointer);
    } else if(TASK_NUMBER == 4){
         /* Read in from file*/
//        FILE * file_pointer;
//        
//        file_pointer = fopen(FILENAME_3, "r");
//        
//        if (file_pointer == NULL) {
//            printf("Error opening file!\n");
//            return -1;
//        }
//        
//        fscanf(file_pointer, "%s %s", &str, &key2);
        printf("Substitution Decipher Task.\n");  
        printf("Cipher text: %s\nKey: %s\n", str, key2);
        printf("Message: ");
        printf("%c", subsDecrypt(str));
        printf("\n");
//        fclose(file_pointer);
    } else
        printf("Task Number is not valid!");


return 0;   
}

/*This function is for rotationally ciphering a given message with a given key.*/
char rotEncrypt(){
    
    char c;    
    for(int i=0; str[i] != '\0'; i++){
        
        /*If the character is a lower case letter, this algorithm converts it to an upper case 
        by reducing its ascii value.*/
        if(str[i]>=97 && str[i]<=122){
            str[i] = str[i] - 32; 
        } 
        
        /*If the character is an upper case letter, this algorithm will encrypt it by 'rotating'
        the letter "key" amount of times in the alphabet.*/
        if(str[i]>=65 && str[i]<=90){
            c = (str[i] + key);
         
         /*If the newly encrypted upper case letter is encrypted to outside of the ascii value 
         range of upper case letters, it is then 'rotated' back to the other end of the alphabet.*/
            if(c<65){
                c = c + 26;
                printf("%c", c);
            } else if(c>90){
                c = c - 26;
                printf("%c", c);
            } else 
                printf("%c", c);
        } else
        /*If the character doesnt meet any of the above requirements (ie. its a punctuation mark 
        or a numeral): it is passed through the cipher and printed as is.*/
            printf("%c", str[i]); 
    }
    return 0;
}

/*This function is for rotationally deciphering an already ciphered message with a given key.*/
char rotDecrypt(){
    
    char c;    
    for(int i=0; str[i] != '\0'; i++){
        
        /*Even though the already ciphered message should be in upper case letters, just incase 
        there is a lower case letter in the text, this algorithm converts it to an upper case by 
        reducing its ascii value.*/
        if(str[i]>=97 && str[i]<=122){      
            str[i] = str[i] - 32; 
        } 
        
        /*If the character is an upper case letter, this algorithm will decrypt it by 'rotating'
        the letter "key" amount of times in the opposite direction to the above encryption task
        to bring it back to its original position in the alphabet.*/
        if(str[i]>=65 && str[i]<=90){       
            c = (str[i] - key);             
         
         /*If the new decrypted upper case letter is decrypted to outside of the ascii value 
         range of upper case letters, it is then 'rotated' back to the other end of the alphabet.*/
            if(c<65){                       
                c = c + 26;                 
                printf("%c", c);            
            } else if(c>90){
                c = c - 26;
                printf("%c", c);
            } else 
                printf("%c", c);
        } else
        /*If the character is not an upper case letter then it does not need to be decrypted*/
            printf("%c", str[i]);                                           
    }
    return 0;
}

/*This function is for substitutionally ciphering a given message with a given key.*/
char subsEncrypt(){
    for(int i=0; str[i] != '\0'; i++){
        
        /*If the character is a lower case letter, this algorithm converts it to an upper case 
        by reducing its ascii value.*/
        if(str[i]>=97 && str[i]<=122){
            str[i] = str[i] - 32; 
        } 
        
        /*If the character is an upper case letter, this algorithm will encrypt it by 'substituting'
        the letter with its corresponding letter in the key string.*/
        if(str[i]>=65 && str[i]<=90){
            str[i] = key2[(str[i] - 65)];
            printf("%c", str[i]);
        } else 
        /*If the character doesnt meet any of the above requirements (ie. its a punctuation mark 
        or a numeral): it is passed through the cipher and printed as is.*/
            printf("%c", str[i]); 
    }
    return 0;
}

/*This function is for substitutionally deciphering an already ciphered message with a given key.*/
char subsDecrypt(){
    for(int i=0; str[i] != '\0'; i++){
        
        /*Even though the already ciphered message should be in upper case letters, just incase 
        there is a lower case letter in the text, this algorithm converts it to an upper case by 
        reducing its ascii value.*/
        if(str[i]>=97 && str[i]<=122){
            str[i] = str[i] - 32; 
        } 
        
        /*If the character is an upper case letter, this algorithm will decrypt it by 'substituting'
        the ciphered letter with its corresponding letter in the key string. It does this by counting 
        how many characters it takes to reach the equivelant ascii value and then count the same amount
        of steps in the alphabet, which leads to the correct letter.*/
        if(str[i]>=65 && str[i]<=90){
            int n = 0;
            while(key2[n] != str[i]){
            n++;
        }
            str[i] = 65 + n;
            printf("%c", str[i]);
        } else 
        /*If the character is not an upper case letter then it does not need to be decrypted*/
            printf("%c", str[i]);
    }
    return 0;
}