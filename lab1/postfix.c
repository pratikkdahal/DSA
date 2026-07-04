#include<stdio.h>
#include<ctype.h>
#define MAX 5

struct stack{
    int data[MAX];
    int TOP;
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
    char exp[20];
    char *e;
    int n1,n2,n3,num;
    struct stack s={-1}; //initialized top to -1
    printf("Enter the postfix expression: ");
    scanf("%s", exp);
    e = exp;
    while(*e != "\0")
    {
        if (isdigit(e)){
            num = *e -48;
            push(&s,num);
        }
        else{
            n1= pop(&s);
            n2= pop(&s);
            switch(*e){
                case '+':
                n3 = n1 + n2;
                break;


                case '-':
                n3 = n1 - n2;
                break;


                case '*':
                n3 = n1 * n2;
                break;


                case '/':
                n3 = n1 / n2;
                break;

                default:
                break;
            }
            push(&s,n3);
        }
        e++;
    }
    printf("\nThe result of expression %s  =  %d\n\n",exp,pop(&s));
    return 0;
}