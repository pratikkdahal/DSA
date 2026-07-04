#include<stdio.h>
#include<stdlib.h>

struct sll
{
    int data;
    struct sll *next;
};
struct sll *first,*last = NULL;

struct sll *create_node(int element)
{
    struct sll *newNode;
    newNode = (struct sll*)malloc(sizeof(struct sll));
    if (newNode != NULL)
    {

        newNode->data = element;
        newNode->next = NULL;
    return newNode;
    }
    
    newNode->data=element;
    newNode->next=NULL;
}

void insert_at_beginning(int element)
{
    struct sll *newNode = create_node(element);

    if(first==NULL)
    {
        first=last=newNode;
        printf("List is empty!!\n");
    }
    else
    {
        newNode->next=first;
        first=newNode;
    }
    printf("%d is inserted at the beginning.\n",first->data);
}
void insert_at_ending(int element)
{
    struct sll *newNode= create_node(element);

    if(first==NULL){
        first=last=newNode; //list is empty
    }
    else{
        last->next = newNode;
        last=newNode;   
    }
    printf("%d is inserted at the ending.\n",last->data);
}

void insert_at_pos(int element, int pos)
{
    struct sll *newNode = create_node(element);
    if(newNode != NULL)
    {
        if(pos==1)
            insert_at_beginning(element);
        else
        {
            int i;
            struct sll *temp = first;
            for(i=1;i<pos-1 && temp->next != NULL;i++)
            {
                temp = temp->next;
            }
            if(temp->next == NULL)
                insert_at_ending(element);
            else
            {
                newNode->next = temp->next;
                temp->next = newNode;
                printf("%d INSERTED AT POSITION %d\n",element,pos);
            }
        }
    }
}

void delete_from_beginning()
{
    struct sll *temp;
    if(first == NULL)
        printf("EMPTY LIST\n");
    else if(first->next == NULL)
    {
        temp = first;
        first = last = NULL;
    }
    else
    {
        temp = first;
        first = first->next;
    }
    printf("%d DELETED FROM BEGINNING\n",temp->data);
    free(temp);
}
void delete_from_end()
{
    struct sll *temp;
    if(first == NULL)
        printf("EMPTY LIST\n");
    else if(first->next == NULL)
    {
        temp = first;
        first = last = NULL;
    }
    else
    {
        temp = first;
        while(temp->next != last)
            temp = temp->next;
        last = temp;
        temp = last->next;
        last->next = NULL;
    }
    printf("%d DELETED FROM END\n",temp->data);
    free(temp);
}

void traversal()
{
    struct sll *temp = first;
    if(first==NULL){
        printf("Empty List!!");
    }
    else{
        while (temp!=NULL)
        {
            printf("%d -> ",temp->data);
            temp=temp->next;
        }
        printf("NULL\n");
    }
}

void search(int key)
{
    struct sll *temp;
    int flag = 0;
    if(first == NULL)
        printf("EMPTY LIST\n");
    else
    {
        temp = first;
        while(temp != NULL)
        {
            if(temp->data == key)
            {
                printf("Element found is %d !\n",temp->data);
                flag = 1;
            }
            temp = temp->next;
        }
        if(flag == 0)
            printf("Search is unsuccessful \n");
    }
}

int main(){
    insert_at_beginning(200);
    traversal();
    insert_at_beginning(300);
    traversal();
    insert_at_beginning(900);
    traversal();
    insert_at_ending(500);
    traversal();
    insert_at_ending(1100);
    traversal();
    insert_at_ending(2000);
    traversal();
    insert_at_pos(400,2);
    traversal();
    delete_from_beginning();
    traversal();
    delete_from_end();
    traversal();
    search(1100);
    search(900);
    return 0;
}
