#include <stdio.h>
#include <stdlib.h>

typedef struct term
{
    void *data;
    struct term *next;
} term;

struct node
{
    char name[20];
    int roll;
};

struct term *front = NULL;
struct term *rear = NULL;

void ins()
{
    struct term *newNode = malloc(sizeof(struct term));
    struct node *newData = malloc(sizeof(struct node));

    printf("Enter name: ");
    scanf("%s", newData->name);
    printf("Enter roll: ");
    scanf("%d", &newData->roll);

    newNode->data = newData;
    newNode->next = rear;

    if (front == NULL && rear == NULL)
    {
        front = newNode;
        rear = newNode;
        rear->next = front;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
        newNode->next = front;
    }
}

void print()
{
    struct term *temp = front;

    do
    {
        struct node *tempData = temp->data;
        printf("Name: %s, Roll: %d\n", &tempData->name, tempData->roll);
        temp = temp->next;
    } while (temp != front);
}

void deletefirst()
{

    struct term *temp;
    if (front == NULL && rear == NULL)
        printf("No node to delete\n");
    else if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        struct node *tempData = front->data;
        printf("Deleted node: name: %s, roll: %d\n", tempData->name, tempData->roll);
        front = front->next;
        rear->next = front;
    }
}

void deletelast()
{

    struct term *temp;
    if (front == NULL && rear == NULL)
        printf("No node to delete\n");
    else if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        struct term *tempData = front;
        while (tempData->next != rear)
        {
            tempData = tempData->next;
        }
        rear = tempData;
        tempData = tempData->next;
        struct node *data = tempData->data;

        printf("Deleted node: name: %s, roll: %d\n", data->name, data->roll);
        free(tempData);
        rear->next = front;
    }
}

void deletekey(int key)
{
    if (key == 0 ) {

        deletefirst();
        return ;
    }
    int i = 0;
    struct term *temp = front;
    while (i++ != key-1)
    {
        temp = temp->next;
    }
    struct term *temp2 = temp->next;
    temp->next = temp2->next;
    struct node *data = temp2->data;
    printf("Deleted node: name: %s, roll: %d\n", data->name, data->roll);
    free(temp2);

}

void insertfirst()
{
    struct term *newNode = malloc(sizeof(struct term));
    struct node *newData = malloc(sizeof(struct node));
    printf("Enter name: ");
    scanf("%s", newData->name);
    printf("Enter roll: ");
    scanf("%d", &newData->roll);

    newNode->data = newData;
    newNode->next = front;
    if (front == NULL && rear == NULL)
    {
        front = newNode;
        rear = newNode;
        rear->next = front;
    }
    else
    {
        front = newNode;
        rear->next = front;
    }
}

void insertlast()
{
    struct term *newNode = malloc(sizeof(struct term));
    struct node *newData = malloc(sizeof(struct node));

    printf("Enter name: ");
    scanf("%s", newData->name);
    printf("Enter roll: ");
    scanf("%d", &newData->roll);

    newNode->data = newData;
    newNode->next = rear;

    if (front == NULL && rear == NULL)
    {
        front = newNode;
        rear = newNode;
        rear->next = front;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
        newNode->next = front;
    }
}

int main()
{
    int c = 1;
    while (c)
    {
        printf("\n1.create\t\t2.del(key)\n3.dFirst\t\t4.dLast\n5.ins(data)\t\t6.iFirst(data)\n7.iLast(data)\t\t8.print\n0.exit\n");
        int op, key;
        printf("Enter your choice : ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            front = NULL;
            rear = NULL;
            printf("A new List has been created\n");
            break;
        case 2:
            printf("Enter key: ");
            scanf("%d", &key);
            deletekey(key);
            break;
        case 3:
            deletefirst();
            break;
        case 4:
            deletelast();
            break;
        case 5:
            ins();
            break;
        case 6:
            insertfirst();
            break;
        case 7:
            insertlast();
            break;
        case 8:
            print();
            break;
        case 0:
            c = 0;
            break;
        default:
            printf("Invalid option\n");
            break;
        }
    }
}
