#include <stdio.h>

void koboImaginaryChess(int i, int j, int size, int *chessBoard) {
    int gerak[8][2] = {{2, 1}, {1, 2}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};
    
    for (int kuda = 0; kuda < 8; kuda++) {
        int iBesar = i + gerak[kuda][0];
        int jBesar = j + gerak[kuda][1];
        if (iBesar >= 0 && iBesar < size && jBesar >= 0 && jBesar < size) {
            *(chessBoard + iBesar * size + jBesar) = 1;
        }
    }
}
int main() {
    int i, j;
    scanf("%d %d", &i, &j);
    int chessBoard[8][8] = {0};

    koboImaginaryChess(i, j, 8, (int *)chessBoard);

    for (int baris = 0; baris < 8; baris++) {
        for (int kolom = 0; kolom < 8; kolom++) {
            printf("%d ", chessBoard[baris][kolom]);
        }
        printf("\n");
    }
    return 0;
}