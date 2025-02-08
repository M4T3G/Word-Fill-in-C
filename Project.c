#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_WORD_LENGTH 50

char** kelimeAl(int kelimeSayisi) {
    char **kelimeler;
    int i,j,uzunluk,max = 0;
    kelimeler=(char **)malloc(kelimeSayisi*sizeof(char *));
    if (kelimeler == NULL) {
        printf("Bellek tahsis edilemedi.\n");
        exit(-1);
    }
    for (i=0;i< kelimeSayisi;i++) {
        kelimeler[i] = (char *)malloc((MAX_WORD_LENGTH + 1) * sizeof(char));
        if (kelimeler[i]==NULL) {
            printf("Bellek tahsis edilemedi.\n");
            exit(-1);
        }
        printf("Kelime %d: ", i + 1);
        scanf("%s", kelimeler[i]);
        uzunluk=strlen(kelimeler[i]);
        if (uzunluk>max) {
            max=uzunluk;
        }
    }
    for (i=0;i<kelimeSayisi; i++) {
        uzunluk=strlen(kelimeler[i]);
        if (uzunluk<max) {
            for (j=uzunluk;j<max;j++) {
                kelimeler[i][j]='*';
            }
            kelimeler[i][max]='\0'; 
        }
    }
    return kelimeler;
}

void printMatrix(char **kelimeler, int kelimeSayisi) {
    int i,j,uzunluk;
    for (i=0;i<kelimeSayisi;i++) {
        uzunluk = strlen(kelimeler[i]);
        printf("%s\n",kelimeler[i]);
    }
}

void free_mat(char **kelimeler, int kelimeSayisi) {
    int i;
    for (i = 0; i < kelimeSayisi; i++) {
        free(kelimeler[i]);
    }
    free(kelimeler);
}

int main() {
    char **kelimeler;
    int kelimeSayisi;
    printf("Kac kelime gireceksiniz? ");
    scanf("%d",&kelimeSayisi);
    kelimeler=kelimeAl(kelimeSayisi);
    printf("\nKelimeler:\n");
    printMatrix(kelimeler, kelimeSayisi);
    free_mat(kelimeler, kelimeSayisi);
    return 0;
}
