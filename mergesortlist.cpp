#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct box
{
    char nik[290];
    box*next;
}*head,*tail;

box*listm(const char*nik)
{
    box*makebox = (box*)malloc(sizeof(box));
    strcpy(makebox->nik,nik);
    makebox->next = NULL;

    return makebox;
}

void pushhead(const char*nik,box**readaddress)//digunakan untukpengambilan alamat dari cal tersebut
{
    box*temp = listm(nik);//buat 
    if(head==NULL)
    {
        head = *readaddress; //assign string sebagai 
        tail = *readaddress;//assign nilai ke tail
    }
    else
    {
        temp->next = *readaddress;// buat posisi setelah temp adalah head
        *readaddress = temp; //ganti label temp sebagaii head karena sekarang posisinya berada di ujung 
    } 

}
void printlist(box*readaddres)
{
    while(readaddres)
    {
        if(readaddres->next==NULL)
        {
            printf("%s\n",readaddres->nik);
        }

        else
        {
            printf("%s -> ",readaddres->nik);
        
        }
        readaddres = readaddres->next;
    }
}
box*merge(box*cal1,box*cal2) // pakai node/box in this case karena perlu return hasil berupa list nya
{
    box*newest=NULL;

    if(cal1==NULL)
        return cal2;
    if(cal2==NULL)
        return cal1;
    if(cal1&&cal2)//cal1 and cal2 not NULL value
    {
        if(strcmp(cal1->nik,cal2->nik)>=0)
        {
            newest = cal2;
            merge(cal1,cal2->next);//memanggil cal2 nilai selanjutnyadari cal2
        }
        else
        {
            newest = cal1;//
            merge(cal1->next,cal2);//memanggil 1 value selanjutnya dari cal1
        }
        
    }
    return newest;
}

int main ()
{
    int a;
    scanf("%d",&a);
    box*ca1=NULL;
    box*ca2=NULL;
    box*newest = NULL;
    for(int y = 0;y<a;y++)
    {
        char n[290];
        scanf("%s",n);
        pushhead(n,&ca1);
    }

    for(int u = 0;u<a;u++)
    {
        char ol[290];
        scanf("%s",ol);
        pushhead(ol,&ca2);
    }   
    printlist(newest);
    return 0;
}