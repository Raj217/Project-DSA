#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Node
{
    int tNo;
    struct Node *next;
};
struct Node *head = NULL;
struct Node *tail = NULL;

void enterGarage(int tNo)
{
    struct Node *newTruck = (struct Node *)malloc(sizeof(struct Node));
    newTruck->tNo = tNo;
    if (head == NULL)
    {
        newTruck->next = NULL;
    }
    else
    {
        head->next = newTruck;
    }
    head = newTruck;
    if (tail == NULL)
    {
        tail = newTruck;
    }
}

int exitGarage(int tNo)
{
    if (head != NULL)
    {
        if (head->tNo == tNo)
        {
            struct Node *currTruck = tail;
            while (currTruck->next != head)
            {
                currTruck = currTruck->next;
            }
            head = currTruck;
            currTruck = currTruck->next;
            free(currTruck);
            return 0;
        }
        else
        {
            printf("Truck %d is not near the garage door", tNo);
            return 1;
        }
    }
    return 1;
}

void showTrucks()
{
    if (tail != NULL)
    {
        struct Node *currTruck = tail;
        while (currTruck != head)
        {
            printf("%d ", currTruck->tNo);
            currTruck = currTruck->next;
        }
        if (head != NULL)
        {
            printf("%d ", currTruck->tNo);
        }
    }
}

bool onRoad(int tNo)
{
    struct Node *currTruck = tail;
    if (tail != NULL)
    {
        while (currTruck != head)
        {
            if (currTruck->tNo == tNo)
            {
                return false;
            }
            currTruck = currTruck->next;
        }
        if (currTruck->tNo == tNo)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    printf("How many trucks do you want to handle: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(sizeof(int) * n);
    printf("\nEnter the truck nos: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    bool cont = true;
    int option;
    while (cont)
    {
        printf("\n\nWhat operation do you want to perform?");
        printf("\n1.Enter Garage");
        printf("\n2.Exit Garage");
        printf("\n3.On Road");
        printf("\n4.Show Trucks");
        printf("\n5.Exit");
        printf("\n> ");
        scanf("%d", &option);
        int tNo;
        char choice;
        if (option == 1)
        {
            printf("\nEnter truck No.: ");
            scanf("%d", &tNo);
            if (onRoad(tNo))
            {
                enterGarage(tNo);
                printf("\nTruck %d entered the Garage", tNo);
            }
            else
            {
                printf("\nTruck %d is already in the Garage", tNo);
            }
        }
        else if (option == 2)
        {
            printf("\nEnter truck No.: ");
            scanf("%d", &tNo);
            if (exitGarage(tNo) == 0)
            {
                printf("\nTruck %d has exited the garage", tNo);
            }
            else
            {
                printf("\nTruck %d is not near the garage door", tNo);
            }
        }
        else if (option == 3)
        {
            printf("\nEnter truck No.: ");
            scanf("%d", &tNo);
            if (onRoad(tNo))
            {
                printf("\nTruck %d is on Road", tNo);
            }
            else
            {
                printf("\nTruck %d is not on Road", tNo);
            }
        }
        else if (option == 4)
        {
            printf("\nDo you want to see the trucks in garage(g) or road(r): ");
            scanf("%s", &choice);
            printf("\nThe following trucks are ");
            if (choice == 'g')
            {
                printf("in garage: ");
            }
            else if (choice == 'r')
            {
                printf("on road: ");
            }
            else
            {
                continue;
            }
            if (choice == 'g') {
                showTrucks();
            } else {
                for (int i = 0; i < n; i++)
            {
                if (choice == 'r' && onRoad(arr[i]))
                {
                    printf("%d ", arr[i]);
                }
            }
            }
        }
        else if (option == 5)
        {
            cont = false;
            break;
        }
    }
    return 0;
}