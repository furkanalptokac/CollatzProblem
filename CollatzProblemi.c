#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// 1711012011 Furkan Alp Tokaç 3. Sınıf 1. Öğretim

int main(){
    int sayi = 0;
    pid_t islemID;
 
    printf("Sayiyi giriniz: ");
    scanf("%d", &sayi);
 
    if(sayi < 0){
        printf("0'dan buyuk bir sayi giriniz: ");
        scanf("%d", &sayi);
    }
 
    islemID = fork();
 
    if(islemID < 0){
      printf("Child gorev olusturma basarisiz.");
      exit(-1);
    }
 
    else if(islemID == 0){
        do{
        if(sayi % 2 != 0)
          sayi = (sayi * 3) + 1;
         
        else if(sayi % 2 == 0)
          sayi = sayi / 2;
 
        printf("%d\n", sayi);
        }
        while(sayi != 1);
    }
 
    else{
        printf("pid %d \n", islemID);
        printf("Child gorev bekleniyor.\n");
        wait(NULL);
    }
    
    return EXIT_SUCCESS;   
}