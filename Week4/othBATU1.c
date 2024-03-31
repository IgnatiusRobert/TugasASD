#include <stdio.h>

struct BatuHolmes {
    struct BatuHolmes* link;
    char alphabet;
};
int main() {
    // Deklarasi/Inisialisasi Batu
    struct BatuHolmes l1, l2, l3, l4, l5, l6, l7, l8, l9;
    l1.link = NULL;
    l1.alphabet = 'F';

    l2.link = NULL;
    l2.alphabet = 'M';

    l3.link = NULL;
    l3.alphabet = 'A';

    l4.link = NULL;
    l4.alphabet = 'I';

    l5.link = NULL;
    l5.alphabet = 'K';

    l6.link = NULL;
    l6.alphabet = 'T';

    l7.link = NULL;
    l7.alphabet = 'N';

    l8.link = NULL;
    l8.alphabet = 'O';

    l9.link = NULL;
    l9.alphabet = 'R';

    // Menyambungkan link batu 
    l7.link = &l1; //N ke F
    l1.link = &l8; //F ke O
    l8.link = &l2; //O ke M
    l2.link = &l5; //M ke K
    l5.link = &l3; //K ke A
    l3.link = &l6; //A ke T
    l6.link = &l9; //T ke R
    l9.link = &l4; //R ke i
    l4.link = &l7; //i ke N

    // Akses data huruf
    printf("%c", l3.link->link->link->alphabet); //I
    printf("%c", l3.link->link->link->link->alphabet);//N
    printf("%c", l3.link->link->link->link->link->alphabet);//F
    printf("%c", l3.link->link->link->link->link->link->alphabet);//O
    printf("%c", l3.link->link->alphabet);//R
    printf("%c", l3.link->link->link->link->link->link->link->alphabet); //M
    printf("%c", l3.alphabet); //A
    printf("%c", l3.link->alphabet); //T
    printf("%c", l3.link->link->link->alphabet); //I
    printf("%c", l3.link->link->link->link->link->link->link->link->alphabet); //K
    printf("%c", l3.alphabet); //A

    return 0;
}