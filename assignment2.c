#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Max 5
#define true 1
#define false 0

struct Queue {
    int Front, Rear;
    char Data[Max][50];
};

int isFull(struct Queue *QQ) {
    return (QQ->Rear + 1) % Max == QQ->Front;
}

int isEmpty(struct Queue *QQ) {
    return QQ->Front == QQ->Rear;
}

void push(struct Queue *QQ, const char *element) {
    if (isFull(QQ)) {
        printf("Queue full\n");
        return;
    }
    strcpy(QQ->Data[(QQ->Rear + 1) % Max], element);
    QQ->Rear = (QQ->Rear + 1) % Max;
    printf("%s Enqueued\n", element);
}

char pop(struct Queue *QQ) {
    if (isEmpty(QQ)) {
        printf("Queue Empty\n");
        return -1;
    }
    char element[50];
    strcpy(element, QQ->Data[QQ->Front]);
    QQ->Front = (QQ->Front + 1) % Max;
    return element[0];
}

void display(struct Queue *QQ) {
    if (isEmpty(QQ)) {
        printf("Queue Empty\n");
        return;
    }
    printf("Queue Contents:\n");
    for (int i = QQ->Front; i != QQ->Rear; i = (i + 1) % Max) {
        printf("%s\n", QQ->Data[i]);
    }
    printf("%s\n", QQ->Data[QQ->Rear]);
}

int main() {
    struct Queue Q;
    Q.Front = Q.Rear = 0;
    int choice;
    char element[50];

    while (true) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Choice? ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Enter element? ");
                fgets(element, sizeof(element), stdin);
                element[strcspn(element, "\n")] = '\0';
                push(&Q, element);
                break;
            case 2:
                element[0] = pop(&Q);
                if (element[0] != -1) {
                    printf("%c Dequeued\n", element[0]);
                }
                break;
            case 3:
                display(&Q);
                break;
            case 4:
                printf("bye...\n");
                break;
            default:
                printf("Enter a valid option\n");
                break;
        }

        if (choice == 4) {
            break;
        }
    }

    return 0;
}

