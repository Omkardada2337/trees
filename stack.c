#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct stack
{
    int size;
    int top;
    struct node **s;
};

void create(struct stack *st)
{
    printf("Enter size : ");
    scanf("%d", &(st->size));
    st->top = -1;
    st->s = (struct node **)malloc(sizeof(struct node *));
}
void push(struct stack *st, struct node *t)
{
    if (st->top == st->size - 1)
    {
        printf("Overflow");
    }
    else
    {
        st->top++;
        st->s[st->top] = t;
    }
}

struct node *pop(struct stack *st)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = -1;
    if (st->top == -1)
    {
        printf(" Empty");
    }
    else
    {
        temp = st->s[st->top];
        st->top--;
    }
    return temp;
}

void display(struct stack st)
{
    for (int i = st.top; i >= 0; i--)
    {
        printf("%d ", st.s[i]);
    }
}

void preorder(struct node *t)
{
    struct stack st;
    while (t != NULL || st.top != -1)
    {
        if (t != NULL)
        {
            printf("%d ", t->data);
            push(&st, t);
            t = t->left;
        }
        else
        {
            t = pop(&st);
            t = t->right;
        }
    }
}

struct node *createt()
{
    int x;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data : (else enter -1 for null) : ");
    scanf("%d", &x);
    if (x == -1)
    {
        return 0;
    }
    newnode->data = x;
    printf("\nEnter the data of left child of %d : ", x);
    newnode->left = createt();
    printf("\nEnter the data of right child of %d : ", x);
    newnode->right = createt();
    return newnode;
}

int main()
{
    int i;
    struct stack st;
    system("cls");
    create(&st);
    struct node *root;
    root = createt();
    preorder(root);
    // push(&st, 5);
    // push(&st, 6);
    // push(&st, 7);
    // display(st);
    printf("  ");
    free(root);
    getch();
    return 0;
}
// void preorder(struct node *t)
// {
//     struct stack st;
//     while (t != NULL || st.top != -1)
//     {
//         if (t != NULL)
//         {
//             printf("%d ", t->data);
//             push(&st, t);
//             t = t->left;
//         }
//         else
//         {
//             t = pop(&st);
//             t = t->right;
//         }
//     }
// }

// struct node *createt()
// {
//     int x;
//     struct node *newnode = (struct node *)malloc(sizeof(struct node));
//     printf("Enter the data : (else enter -1 for null) : ");
//     scanf("%d", &x);
//     if (x == -1)
//     {
//         return 0;
//     }
//     newnode->data = x;
//     printf("\nEnter the data of left child of %d : ", x);
//     newnode->left = create();
//     printf("\nEnter the data of right child of %d : ", x);
//     newnode->right = create();
//     return newnode;
// }