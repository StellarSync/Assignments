#include<stdio.h>
#include<stdlib.h>

// self referential structure
struct SLL
{
  int data;
  struct SLL *next;
};

struct SLL *first, *last; // global variables
void insertAtfront(int element)
{
  struct SLL *newNode;
  newNode=(struct SLL*)malloc(sizeof(struct SLL));
  if (newNode==NULL)
  
    printf("Memory allocation failed\n");
     else
     {
     newNode->data=element;
     newNode->next=NULL;
     
     if(first == NULL)
     {
       first = last = newNode;
     }
     else
     {
       newNode->next=first;
       first=newNode;
     }
     printf("%d was inserted at the front\n",element);
  }
void displayList()
{
  struct SLL *temp=first;
  if(first=NULL)
  {
    printf("List is empty\n");
    return;
  }
  while(temp->next!=NULL)
  {
    printf("%d-->",temp->data);
    temp=temp->next;
  }
  printf("%d -> NULL\n",temp->data);
}
int main()
{
  first = NULL;
  last = NULL;
  insertAtfront(5);
  displayList();
  insertAtfront(10);
  displayList();
  insertAtfront(11);
  displayList();
  insertAtfront(1000);
  displayList();
}
}
void Deletion(int element)
{
  struct SLL *newNode;
  newNode=(struct SLL*)malloc(sizeof(struct SLL));
  if (first==NULL)
  {
    printf("List is empty, void deletion and exit\n");
  }
  else
  {
    newNode->data=element;
    newNode->next=NULL;
    if(first==last)
    {
      first=last=NULL;
      printf("%d was deleted\n",element);
      free(newNode);
      return;
    }
    else
    {
      struct SLL *temp=first;
      while(temp->next!=NULL)
      {
        if(temp->next->data==element)
        {
          struct SLL *temp1=temp->next;
          temp->next=temp->next->next;
          printf("%d was deleted\n",element);
          free(temp1);
          return;
        }
        temp=temp->next;
      }
      printf("%d was not found in the list\n",element);
      free(newNode);
    }
  }
}
