#include <stdio.h>
#include <stdlib.h>

/* Creating a Node*/
struct node
{
    int data;
    struct node *link;
};

struct node *root=NULL;

/* Inserting a Node at the end of Linked List*/
void Append()
{
    int item;
    printf("\nEnter Item to add :");
    scanf("%d",&item);
    struct node *temp;
    temp =(struct node*)malloc(sizeof(struct node));
    temp->data = item;
    temp->link = NULL;
    if(root==NULL)
    {
        root=temp;
    }
    
    else
    {
        struct node *point;
        point = root;
        while(point->link!=NULL)
        {
            point = point->link;
        }
        
        point->link = temp;
    }
}

/* Inserting a Node at the Beginning of Linked List*/
void InsertAtBegin()
{
    int item;
    printf("\nEnter Item to add :");
    scanf("%d",&item);
    struct node *temp;
    temp =(struct node*)malloc(sizeof(struct node));
    temp->data = item;
    temp->link = NULL;
    if(root==NULL)
    {
        root=temp;
    }
    else
    {
        temp->link=root;
        root=temp;
    }
}

/* Inserting a Node anywhere in Linked List*/
void InsertAtAnywhere()
{
    int item,position;
    printf("\nEnter Item to be inserted : ");
    scanf("%d",&item);
    printf("\nEnter Item to be inserted : ");
    scanf("%d",&position);
    struct node *temp;
    temp =(struct node*)malloc(sizeof(struct node));
    temp->data = item;
    temp->link = NULL;
    if (root==NULL)
    {
        root=temp;
    }
    else
    {
        struct node *p;
        p=root;
        while(position>2)
        {
            p=p->link;
        }
        temp->link=p->link;
        p->link = temp;
    }
}

/*Deleting a Node from Beginning*/
void DeleteFromBegin()
{
    int item;
    if(root == NULL)
    {
        printf("\nLinked List is Empty");
        exit(0);
    }
    item = root->data;
    struct node *temp;
    temp = root;
    root = root->link;
    free(temp);
    temp = NULL;
    printf("\nDeleted Element is %d",item);
}

/*Deleting a Node from End*/
void DeleteFromEnd()
{
    int item;
    if(root == NULL)
    {
        printf("\nLinked List is Empty");
        exit(0);
    }
    else
    {
        struct node *temp,*previos;
        temp = root;
        while(temp->link != NULL)
        {
            previos = temp;
            temp = temp->link;
        }
        previos->link = NULL;
        item = temp->data;
        printf("\nDeleted Element is %d",item);
        free(temp);
        temp = NULL;
    }
    
}

/*Deleting a Node from Anywhere*/
void DeleteFromAnywhere()
{
    int item,position;
    if(root == NULL)
    {
        printf("\nLinked List is Empty");
        exit(0);
    }
    else
    {
        printf("\nEnter position to delete Element : ");
        scanf("%d",&position);
        struct node *temp,*previos;
        temp = root;
        while(position>2)
        {
            previos = temp;
            temp = temp->link;
        }
        previos->link=temp->link;
        item = temp->data;
        printf("\nDeleted Element is %d",item);
        free(temp);
        temp = NULL;
    }
    
}

/*Traversing In Linked List*/
void Traversing()
{
    int i=0;
    struct node *temp;
    if(root==NULL)
    {
        printf("\nLinked List is Empty");
        exit(0);
    }
    else
    {
        temp=root;
        while(temp->link != NULL)
        {
            printf("\nElement on %d position is %d\n",i,temp->data);
            i++;
            temp=temp->link;
        }
        printf("\nElement on %d position is %d\n",i+1,temp->data);
    }
}

/*Sum of Elements In Linked List*/
void Sum()
{
    int i=0,sum=0;
    struct node *temp;
    if(root==NULL)
    {
        printf("\nLinked List is Empty");
        exit(0);
    }
    else
    {
        temp=root;
        while(temp->link != NULL)
        {
            sum = sum + temp->data;
            temp=temp->link;
        }
        printf("Sum is %d",sum+temp->data);
    }
}

/*Counting Nodes in Linled list*/
void Count()
{
    int Count=0;
    struct node *temp;
    if(root==NULL)
    {
        printf("\nLinked List is Empty");
        exit(0);
    }
    else
    {
        temp=root;
        while(temp->link != NULL)
        {
            Count = Count + 1;
            temp=temp->link;
        }
        printf("Count is %d",Count + 1);
    }
}

int main()
{
    int choice;
    while(1)
    {   
        printf("Enter choice 1:Insert,2:Delete,3:Other Function,4:Exit : ");
        scanf("%d",&choice);
        if (choice==1)
        {
            int insideChoice;
            printf("Enter 1:Append,2:Insert At beginning,3:Insert Anywhere : ");
            scanf("%d",&insideChoice);
            
            if (insideChoice==1)
            {
                Append();
            }
            
            else if(insideChoice==2)
            {
                 InsertAtBegin();   
            }
            
            else if(insideChoice==3)
            {
                InsertAtAnywhere();
            }
            
            else
            {
                printf("Wrong Choice");
            }
        }
        
      
        else if (choice==2)
        {
            int insideChoice;
            printf("\nEnter 1:Delet from end,2:Delete At beginning,3:Delete Anywhere : ");
            scanf("%d",&insideChoice);
            
            if (insideChoice==1)
            {
                DeleteFromEnd();
            }
            
            else if(insideChoice==2)
            {
                 DeleteFromBegin();
            }
            
            else if(insideChoice==3)
            {
                DeleteFromAnywhere();
            }
            
            else
            {
                printf("Wrong Choice");
            }
        }
        
        else if (choice==3)
        {
            int insideChoice;
            printf("Enter 1:Traversing,2:Sum,3:Count Nodes : ");
            scanf("%d",&insideChoice);
            
            if (insideChoice==1)
            {
               Traversing();
            }
            
            else if(insideChoice==2)
            {
                 Sum();
            }
            
            else if(insideChoice==3)
            {
                Count();
            }
            
            else
            {
                printf("Wrong Choice");
            }
        }
        
        else if(choice==4)
        {
            exit(0);
        }
        
        else
        {
            printf("Wrong Choice");
        }
    }
    return 0;
}
