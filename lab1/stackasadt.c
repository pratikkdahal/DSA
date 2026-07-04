#include<stdio.h>
#define MAX 5
struct stack{
    int TOP;
    int data[MAX];
};

void push(struct stack *s, int element)
{
    if (s->TOP == MAX-1)
    {
        printf("Stack overflow.\n");
    }
    else{
        s->TOP++;
        s->data[s->TOP]=element;
        printf("%d was pushed.\n",element);
    }
}
int pop(struct stack *s)
{
    int element = 1;
    if(s->TOP == -1)
    {
        printf("Stack Underflow.\n");
    }
    else{
        element = s -> data[s->TOP];
        s->TOP--;
    }
    return element;
}

int main(){
    int choice, element;
    struct stack s={-1}; //initialized top to -1 which means stack is empty
    do{
        printf("1.PUSH\n 2.POP\n 3.EXIT\n Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("Enter a element:");
            scanf("%d", &element);
            push(&s,element);
            break;

            case 2:
            element = pop(&s);
            if(element!= -1){
                printf("%d was popped.\n", element);
            }
            break;

            case 3:
            printf("BYEEEE BYEEE\n");
            break;
        }
    }while(choice!=3);
    return 0;
}