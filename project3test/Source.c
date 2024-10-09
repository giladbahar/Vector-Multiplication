#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct vectorItem {
    int data;
    struct vectorItem* next;
} vectorItem;

vectorItem* createvector() {
    int i, count, Data;
    vectorItem* new_item = NULL;
    vectorItem* head = NULL, * ptr = NULL;
    printf("Enter how many numbers in the vector: ");
    scanf("%d", &count);
    for (i = 0; i < count; i++) {
        printf("Enter the %d num: ", i);
        scanf("%d", &Data);
        new_item = (vectorItem*)malloc(sizeof(vectorItem));
        new_item->data = Data;
        new_item->next = NULL;
        if (head == NULL)
            head = ptr = new_item;
        else {
            ptr->next = new_item;
            ptr = ptr->next;
        }
    }
    return head;
}

vectorItem* multiplvector(vectorItem* a, vectorItem* b) {
    vectorItem* newitem = NULL, * head = NULL, * ptr = NULL;
    while (a != NULL && b != NULL) {
        newitem = (vectorItem*)malloc(sizeof(vectorItem));
        newitem->data = (a->data) * (b->data);
        newitem->next = NULL;
        if (head == NULL)
            head = ptr = newitem;
        else {
            ptr->next = newitem;
            ptr = ptr->next;
        }
        a = a->next;
        b = b->next;
    }
    while (a == NULL && b != NULL) {
        newitem = (vectorItem*)malloc(sizeof(vectorItem));
        newitem->data = 0;
        newitem->next = NULL;
        if (head == NULL)
            head = ptr = newitem;
        else {
            ptr->next = newitem;
            ptr = ptr->next;
        }
        b = b->next;
    }
    while (b == NULL && a != NULL) {
        newitem = (vectorItem*)malloc(sizeof(vectorItem));
        newitem->data = 0;
        newitem->next = NULL;
        if (head == NULL)
            head = ptr = newitem;
        else {
            ptr->next = newitem;
            ptr = ptr->next;
        }
        a = a->next;
    }
    return head;
}

void printVector(vectorItem* vector) {
    vectorItem* temp = vector;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    vectorItem* a = createvector();
    vectorItem* b = createvector();

    printf("Vector a:\n");
    printVector(a);
    printf("Vector b:\n");
    printVector(b);

    vectorItem* result = multiplvector(a, b);

    printf("Result:\n");
    printVector(result);

    // Free allocated memory
    vectorItem* temp;
    while (a != NULL) {
        temp = a;
        a = a->next;
        free(temp);
    }

    while (b != NULL) {
        temp = b;
        b = b->next;
        free(temp);
    }

    while (result != NULL) {
        temp = result;
        result = result->next;
        free(temp);
    }

    return 0;
}
