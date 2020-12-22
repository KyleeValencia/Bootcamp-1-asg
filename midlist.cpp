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

void push(int il)
{
    box*take =  makebox(il);
    if(!head)
    {
        head = take;
    }
    else
    {
        take->next = head;
        head = take;
    }
}

void mids()
{
    box*ck = head;
    if(!head)
    {
        return;
    }
    int length = 1;
    while(ck->next)
    {
        ck = ck->next;
        length++;
        
    }
    int b;
    box*get = head;
    box*get1 = head;
    int b = length/2;
        int u = 1;
        while(u<b)
        {
            get->next;
            u++;
        }
    if(length%2==0)
    {
        printf("Middle element is: %d\n",get->il);
    }
    else
    {
        while(u<=b)
        {
            get1->next;
            u++;
        }
        printf("Middle element is: %d\n",((get1->il)+(get->il))/2);
    }
    

}
int main ()
{
    push(3);
    push(1);
    push(4);
    push(5);
    push(8);
    mids();

    return 0;
}