#include<stdio.h>
#include<stdlib.h>

struct box
{
    int il;
    box*next;
}*head,*tail;

box*makebox(int il)
{
    box*newbox = (box*)malloc(sizeof(box));
    newbox->next = NULL;
    newbox-> il = il;

    return newbox;
}

void pushead(int il)
{
    box*temp = makebox(il);
    if(!head)
    {
        head = temp;
    }
    else
    {
        box*take  = head;
        while(take->next&&take->next!=head)
        {
            // printf("%d\n",take->il);
            take=take-> next;

        }

        take->next = temp;
        temp->next = head;
    }
}

bool cycle (box*check)
{
    box*ck1 = head;//as a start point and nedd to in the same spot
    box*ck2 = head;

    int a = 0;
    while((ck1&&ck2)&&(ck1->next)&&(ck2->next->next))//cek apakah 
    {
        ck1 = ck1->next;
        ck2 = ck2->next->next;
        if(ck2==ck1)
        {
            a = 1;
            break;
        }
    }
    if(a==1)
    {
        return true;
    }
    else if(a==0)
    {
        return false;
    }

}
void print() {
    box* temp = head;
    do {
        printf("%d\n", temp->next->il);
        temp = temp->next;
    } while (temp != head);
}
int main ()
{
    pushead(10);
    pushead(20);
    pushead(30);
    pushead(40);

    print();
    if(cycle(head)==true)
    {
        printf("It's loop\n");
    }
    else
    {
        printf("Not cycle\n");
    }
    
    return 0;
}
