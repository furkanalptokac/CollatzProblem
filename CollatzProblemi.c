#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// 1711012011 Furkan Alp Tokaç 3. Sınıf 1. Öğretim

int main(){
    int n = 0;
    int islemID, durum;
 
    printf("n sayisini giriniz: ");
    scanf("%d", &n);
 
    if(n < 0){
        printf("0'dan buyuk bir n sayisi giriniz: ");
        scanf("%d", &n);
    }
 
    islemID = fork();
 
    if(islemID < 0){
      printf("Child gorev olusturma basarisiz.");
      exit(-1);
    }
 
    else if(islemID == 0){
        do{
        if(n % 2 != 0){
          n = (n * 3) + 1;
        }
         
        else if(n % 2 == 0){
          n = n / 2;
        }
 
        printf("%d\n", n);
        }
        while(n != 1);
    }
 
    else{
        printf("pid %d \n", islemID);
        printf("Child gorev bekleniyor.\n");
        wait(&durum);
    }
    
    return EXIT_SUCCESS;   
}