//////using array concept reverse link
#include<stdio.h>
#include<malloc.h>
typedef struct st
{
	int n;
	struct st *next;
}ST;
void add(ST **);
void traverse(ST *);
void reverse(ST *);
main()
{
	ST * hptr=0;
	char ch;
	do{
		add(&hptr);
		printf("Do u want to add one more node?(Y/N)\n");
		scanf(" %c",&ch);
	}while((ch=='Y')||(ch=='y'));
	traverse(hptr);
	printf("\n");
	printf("You want to reverse it..(Y/N)\n");
	scanf(" %c",&ch);
	if((ch=='Y')||(ch=='y'))
		reverse(hptr);
	else
	printf("Data not reverse...\n");
	traverse(hptr);
	printf("AFTER...\n");

}
void add(ST **ptr)
{
	ST *new=(ST *)malloc(sizeof(ST));
	static ST *last;
	printf("Enter the number::");
	scanf("%d",&new->n);
	if(*ptr==0)
	{
		new->next=*ptr;
		*ptr=new;
		last=new;
	}
	else
	{
		new->next=last->next;
		last->next=new;
		last=new;
	}
}
void reverse(ST *ptr)
{
	ST *q,*p,**temp,dummy;
	int i,j,c=1,t;
	q=p=ptr;
	while(q->next)
	{
		c++;
		q=q->next;
	}
//	printf("%d\n",c);
	temp=malloc(sizeof(ST *)*c);
	i=0;
	while(i<c)
	{
	temp[i]=p;
	p=p->next;
//	printf("%d:::::%u\n",i,temp[i]);
i++;	}
	for(i=0,j=c-1;i<j;i++,j--)
	{
		dummy=*temp[i];
		*temp[i]=*temp[j];
		*temp[j]=dummy;
		
		q=temp[i]->next;
		temp[i]->next=temp[j]->next;
		temp[j]->next=q;
	}
}
void traverse(ST *ptr)
{
	while(ptr)
	{
		printf("%d   ",ptr->n);	
		ptr=ptr->next;
	}
}
