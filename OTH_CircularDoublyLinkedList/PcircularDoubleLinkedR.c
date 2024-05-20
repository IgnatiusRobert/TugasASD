#include <stdio.h>
#include <stdlib.h>

// Mendefinisikan / deklarasi struct anggota Node
typedef struct Node {
    int isi;
    struct Node* next;
    struct Node* prev;
} Node;

// Fungsi membuat node baru
Node* createNode(int isi) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->isi = isi;
    newNode->next = newNode;
    newNode->prev = newNode;
    return newNode;
}

void insertLast(Node** head, int isi) {
    Node* newNode = createNode(isi);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* tail = (*head)->prev;
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = *head;
        (*head)->prev = newNode;
    }
}

void printList(Node* head) {
    if (head == NULL) return;
    Node* currentNode = head;
    do {
        printf("Address: %p, Data: %d\n", (void*)currentNode, currentNode->isi);
        currentNode = currentNode->next;
    } while (currentNode != head);
}
    
void swapNodes(Node** head, Node* node1, Node* node2) {
    if (node1 == node2) return;
    Node* prev1 = node1->prev;
    Node* next1 = node1->next;
    Node* prev2 = node2->prev;
    Node* next2 = node2->next;

    // Jika node1 dan node2 bersebalahan | tapi node1 sebelum node2
    if (next1 == node2) {
        node1->next = next2;
        node1->prev = node2;
        node2->next = node1;
        node2->prev = prev1;
        next2->prev = node1;
        prev1->next = node2;

    //Jika node2 dan node1 bersebalahan | tapi node2 sebelum node1
    } else if (next2 == node1) {
        node2->next = next1;
        node2->prev = node1;
        node1->next = node2;
        node1->prev = prev2;
        next1->prev = node2;
        prev2->next = node1;

    // Jika node1 dan node2 tidak bersebelahan
    } else {
        node1->next = next2;
        node1->prev = prev2;
        node2->next = next1;
        node2->prev = prev1;
        next1->prev = node2;
        prev1->next = node2;
        next2->prev = node1;
        prev2->next = node1;
    }

    if (*head == node1) {//Memperbarui node head
        *head = node2;
    } else if (*head == node2) {
        *head = node1;
    }
}

void sortList(Node** head) {
    if (*head == NULL || (*head)->next == *head) return;

    int tuker;
    Node* ptr1;
    Node* lastPtr = NULL;

    do {
        tuker = 0;
        ptr1 = *head;

        while (ptr1->next != lastPtr && ptr1->next != *head) {
            if (ptr1->isi > ptr1->next->isi) {
                swapNodes(head, ptr1, ptr1->next);
                tuker = 1;
            } else {
                ptr1 = ptr1->next;
            }
        }
        lastPtr = ptr1;
    } while (tuker);
}

int main() {
    int total, isi;
    Node* head = NULL;

    printf("Masukan Total Muatan Data: ");
    scanf("%d", &total);

    printf("Masukan Angka Untuk Isi Data Doubly Linked List:\n");
    for (int i = 0; i < total; i++) {
        scanf("%d", &isi);
        insertLast(&head, isi);
    }
    printf("List sebelum sorting:\n");
    printList(head);

    sortList(&head);

    printf("List setelah sorting:\n");
    printList(head);

    return 0;
}