#include<stdio.h>
#include<string.h>

void checkInfoQR() {
    /*
    Hint:
    
    - Look up for strstr() 
    - Look up for printf() using precision field
    */
    char cipher[100];
    char bank[99];
    char ID[99];
    char name[99];
    char Time[8];
    scanf("%s",cipher);
    if(strstr(cipher,"BKB")) {
        //00020101021BKB0271001142475TranMinhHoang22082021
        printf("%c\n",cipher[strlen(cipher)-1]);
        strcpy(bank, "BKB");
        strncpy(ID,&cipher[14],13);
        strncpy(name,&cipher[27],strlen(cipher)-35);
        strncpy(Time,&cipher[strlen(cipher)-8],8);
        char i = cipher[strlen(cipher)-8] ; 
        int cc = 0 ; 
        while (i != '\0' && cc < 10){
            printf("%c\n", cipher[strlen(cipher)-8 + i] )  ; 
            ++cc ; 
        }
        printf("thoi diem tao QR: %s\n",Time);
    }
    else if(strstr(cipher,"KHB")){
       // 0002010102108162021KHB012100002512112DangVu
        strcpy(bank, "QHB");
        strncpy(ID,&cipher[14],13);
        strncpy(name,&cipher[27],strlen(cipher)-35);
        strncpy(Time,&cipher[10],8);
    }
    else if(strstr(cipher,"HHB")) {
    
    }
    else printf("bank not found");
    printf("Ngan hang: %s\n", bank);
    printf("So tai khoan: %s\n",ID);
    printf("ten chu tai khoan: %s\n",name);
    printf("thoi diem tao QR: %s\n",Time);
}

void convertQR() {
    /*
    Hint: 
    - Look up for strcmp(), strlen(), strcpy(), strncpy()
    */ 
}

void encryptQR() {
    /*
    Hint: 
    - Look up for sprintf(), strcat(), strncat()
    */ 
}

int main(){

    int menu_code;
    scanf("%d", &menu_code);
    if(menu_code == 1) {
        checkInfoQR();
    } else if (menu_code == 2) {
        convertQR();
    } else {
        encryptQR();
    }
    return 0;
}