#include <stdio.h>
#include <stdlib.h>

struct Node 
{
	int data;
	struct Node* next;
};

struct Node *front = NULL, *rear = NULL;

void enqueue(int value)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    //if it is the first node
    if(front == NULL && rear == NULL)
        //make both front and rear points to the new node
        front = rear = newNode;
    else
    {
        //add newnode in rear->next
        rear->next = newNode;

        //make the new node as the rear node
        rear = newNode;
    }
}

void dequeue()
{
    //used to freeing the first node after dequeue
    struct Node *temp;

    if(front == NULL)
         printf("Queue is Empty. Unable to perform dequeue\n");
    else
    {
        //take backup
        temp = front;

        //make the front node points to the next node
        //logically removing the front element
        front = front->next;

        //if front == NULL, set rear = NULL
        if(front == NULL)
            rear = NULL;

       //free the first node
       free(temp);
    }

}

void showTrucks()
{
    struct Node *temp = front;

    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
        if(temp->next == NULL)
        {
            printf("\n");
        }
    }
}




int main() 
{
    int n;
    printf("Enter how many trucks : ");
    scanf("%d", &n);
    int  *trucks= (int *)malloc(sizeof(int)*n);
    printf("\nEnter trucks : ");
    for(int i=0;i<n;i++) 
    {
        scanf("%d", &trucks[i]);
    }

    int choice;
    while(1)
    {
        printf("1. Show the trucks\n");
        printf("2. Enter a truck\n");
        printf("3. Exit a truck\n");
        printf("4. Show whether the truck is in the garage or not\n");
        printf("5. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            showTrucks();
        }
        else if (choice == 2)
        {
            // int tNo;
            // printf("\nEnter truck number : ");
            // scanf("%d", &tNo);
            // int check = 0;
            // for(int i=0;i<n;i++) 
            // {
            //     if(tNo == trucks[i])
            //     {
            //         check = 1;
            //         break;
            //     }
            // }
            // if(check == 1)
            // {
            //     enterGarage(tNo);
            //     printf("Truck is Entered\n\n");
            // }
            // else
            // {
            //     printf("truck %d is not on Road", tNo);
            // }
        }
        else if(choice == 3)
        {
            // int tNo;
            // printf("\nEnter truck number : ");
            // scanf("%d", &tNo);
            // exitGarage(tNo);
        }
        else if(choice == 4)
        {
            // int tNo;
            // printf("\nEnter truck number : ");
            // scanf("%d", &tNo);
            // int check = 0;
            // for(int i=0;i<n;i++) 
            // {
            //     if(tNo == trucks[i])
            //     {
            //         check = 1;
            //         break;
            //     }
            // }
            // if(check == 1)
            // {
            //     printf("Truck %d is on Road\n\n", tNo);
            // }
            // else
            // {
            //     printf("Truck %d is not on Road\n", tNo);
            // }
        }
        else if(choice == 5)
        {
            // break;
        }
        else
        {
            // printf("\nInvalid Input... Try Again");
        }
        
    }

    return 0;
}