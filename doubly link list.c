#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int info;
    struct Node *prv,*next;
};
struct Node *START=NULL;
void InsertAsFirstNode()
{
    struct Node *n;
    n=(struct Node*)malloc(sizeof(struct Node));
    printf("Enter data : ");
    scanf("%d",&n->info);
    n->prv=NULL;
    n->next=NULL;
    if(START==NULL)
        START=n;
    else{
        START->prv=n;
        n->next=START;
        START=n;
    }
}
void InsertAsLastNode()
{
    struct Node *n,*t;
    n=(struct Node*)malloc(sizeof(struct Node));
    printf("Enter data : ");
    scanf("%d",&n->info);
    n->prv=NULL;
    n->next=NULL;
    if(START==NULL)
        START=n;
    else{
        t=START;
        while(t->next!=NULL)
            t=t->next;
        t->next=n;
        n->prv=t;
    }
}
void InsertAfterGivenNode(int X)
{
    int flag=1;
    struct Node *n,*t;
    n=(struct Node*)malloc(sizeof(struct Node));
    printf("Enter new Data : ");
    scanf("%d",&n->info);
    n->prv=NULL;
    n->next=NULL;
    if(START == NULL)
        printf("List is Empty");
    else{
        t=START;
        while(t->next != NULL){
            if(t->info == X){
                n->next=t->next;
                n->prv=t->next->prv;
                t->next=n;                   // t->next=n;
                n->next->prv=n;              // n->next->prv=n;
                flag=0;
                break;
            }
            t=t->next;
        }
        if(t->info == X){
            t->next=n;
            n->prv=t;
            flag=0;
        }
        if(flag)
            printf("%d is not in the list",X);
    }
}
void InsertBeforeGivenNode(int X)
{
    int flag=1;
    struct Node *t,*n;
    n=(struct Node*)malloc(sizeof(struct Node));
    printf("Enter data : ");
    scanf("%d",&n->info);
    n->prv=NULL;
    n->next=NULL;
    if(START == NULL)
        printf("List is empty");
    else if(START->info == X){
            n->next=START;
            START->prv=n;
            START=n;
    }
    else{
        t=START;
        while(t!=NULL){
            if(t->info == X){
                    n->next=t->prv->next;
                    n->prv=t->prv;
                    t->prv->next=n;
                    t->prv=n;
                    flag=0;
                    break;
            }
            t=t->next;
        }
        if(flag)
            printf("%d is not in the list",X);
    }
}
void DeleteFirstNode()
{
    struct Node *r;
    if(START==NULL)
        printf("List is empty");
    else if(START->next == NULL){
        r=START;
        START=NULL;
        free(r);
    }
    else{
        r=START;
        if(START->next == NULL){
            START=NULL;
            free(r);
        }
        START=START->next;
        START->prv=NULL;
        free(r);
    }
}
void DeleteLastNode()
{
    struct Node *r,*t;
    if(START==NULL)
        printf("Cant delete last node");
    else if(START->next == NULL){
        r=START;
        START=NULL;
        free(r);
    }
    /*else{
        r=START;
        while(r->next!=NULL)
            r=r->next;
        r->prv->next=NULL;
        free(r);
    }*/
    else{
        t=START;
        while(t->next->next!=NULL)
            t=t->next;
        r=t->next;
        t->next=NULL;
        free(r);
    }
}
void DeleteAfterGivenNode(int X)
{
    int flag=1;
    struct Node *t,*r;
    if(START == NULL)
        printf("List is empty");
    else{
        t=START;
        while(t->next->next != NULL){
            if(t->info == X){
                r=t->next;
                t->next=r->next;
                r->next->prv=r->prv;
                flag=0;
                free(r);
                break;
            }
            t=t->next;
        }
        if(t->info == X && flag){
            r=t->next;
            t->next=NULL;
            flag=0;
            free(r);
        }
        else if(t->next->info == X)
            flag=0;
        if(flag)
            printf("%d is not in the list",X);

    }
}
void DeleteBeforeGivenNode(int X)
{
    int flag=1;
    struct Node *t,*r;
    if(START == NULL)
        printf("List is Empty");
    else if(START->info == X)
        flag=0;
    else if(START->next->info == X){
        r=START;
        START->next->prv=NULL;
        START=START->next;
        flag=0;
        free(r);
    }
    else{
        t=START;
        while(t != NULL){
            if(t->info == X){
                r=t->prv;
                t->prv=r->prv;
                r->prv->next=r->next;
                flag=0;
                free(r);
                break;
            }
            t=t->next;
        }
    }
    if(flag)
        printf("%d is not in the list",X);
}
void ViewList()
{
    struct Node *t;
    if(START==NULL)
        printf("Cant Traverse List is Empty");
    else{
        t=START;
        while(t!=NULL){
            printf("%d ",t->info);
            t=t->next;
        }
    }
}
int menu()
{
    int choice;
    printf("1. Insert As a First Node\n");
    printf("2. Insert As a Last Node\n");
    printf("3. Insert After Given Node\n");
    printf("4. Insert Before Given Node\n");
    printf("5. Delete First Node\n");
    printf("6. Delete Last Node\n");
    printf("7. Delete After Given Node\n");
    printf("8. Delete Before Given Node\n");
    printf("9. View List\n");
    printf("11. Exit\n");
    printf("Enter your choice : ");
    scanf("%d",&choice);
    return(choice);
}
int main()
{
    int data;
    while(1){
        system("cls");
        switch(menu())
        {
        case 1:
            InsertAsFirstNode();
            break;
        case 2:
            InsertAsLastNode();
            break;
        case 3:
            printf("Enter data after which you want to add new data : ");
            scanf("%d",&data);
            InsertAfterGivenNode(data);
            break;
        case 4:
            printf("Enter data before which you want to add new data : ");
            scanf("%d",&data);
            InsertBeforeGivenNode(data);
            break;
        case 5:
            DeleteFirstNode();
            break;
        case 6:
            DeleteLastNode();
            break;
        case 7:
            printf("Enter data after that data is to be deleted : ");
            scanf("%d",&data);
            DeleteAfterGivenNode(data);
            break;
        case 8:
            printf("Enter data before that data is to be deleted : ");
            scanf("%d",&data);
            DeleteBeforeGivenNode(data);
            break;
        case 9:
            ViewList();
            break;
        case 11:
            printf("\nThank You for using this Application\n");
            exit(1);
        default:
            printf("Invalid choice");
        }
        getch();
    }
}
