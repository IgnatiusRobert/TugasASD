#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int namaKartu(char kartu[]) {
    if (strcmp(kartu, "10") == 0) {
        return 10;
    } else if (strcmp(kartu, "J") == 0) {
        return 11;
    } else if (strcmp(kartu, "Q") == 0) {
        return 12;
    } else if (strcmp(kartu, "K") == 0) {
        return 13;
    } else {
        return atoi(kartu);
    }
}
void konversiTukar(int *kartu, int x, int langkah) {
    if (langkah != -1) {
        printf("Pertukaran %d: ", langkah);
    }
    for (int y = 0; y < x; y++) {
        if (kartu[y] == 11) {
            printf("J ");
        } else if (kartu[y] == 12) {
            printf("Q ");
        } else if (kartu[y] == 13) {
            printf("K ");
        } else {
            printf("%d ", kartu[y]);
        }
    }
    printf("\n");
}

void sortKartu(int kartu[], int x) {
    int counter = 0;
    for (int y = 0; y < x; y++){
        int min = y;
        for (int z = y + 1; z < x; z++){
            if(kartu[z] < kartu[min]){
                min = z;
            }
        }
        if (min != y){
            int temp = kartu[y];
            kartu[y] = kartu[min];
            kartu[min] = temp;
            counter++;
            konversiTukar(kartu, x, counter);
        }
    }
    printf("%d", counter);
}

int main() 
{
    int x;
    int counter = 0;
    scanf("%d", &x);
    int kartu[101];
    for (int y = 0; y < x; y++) {
        char nilai[3];
        scanf(" %s", nilai);
        kartu[y] = namaKartu(nilai);
    }
    sortKartu(kartu, x);
    return 0;
}
