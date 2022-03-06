#include <stdio.h>
#include <stdlib.h>
struct node {
	int info;
	struct node *link;
};
struct node *create(struct node *start);
void display(struct node *start);
void isempty(struct node *start);
void size(struct node *start);
void search(struct node *start, int item);
struct node *addatbeg(struct node *start,int data);
struct node *addatend(struct node *start,int data);
struct node *addaft(struct node *start,int data,int item);
struct node *addbf(struct node *start,int data,int item);
struct node *addpos(struct node *start,int data,int pos);
struct node *del(struct node *start,int data);
struct node *rev(struct node *start);
void main() {
	
	struct node *start = NULL;
	int ch=0,data,item,pos;
	while(ch!=12){
	    printf("\n---------------------------------------------------------");
	printf("\n1.Create list\n2.Traverse\n3.Search\n4.add at beg\n5.Add to end\n6.Add after node\n7.Add before node\n8.Add at postion\n 9.delete\n10.reverse\n11.to check list is empty\n12.size of list\n13.Exit\n");			           
		printf("Enetr your choice : ");
		scanf("%d",&ch);
		switch(ch){
			case 1: start = create(start);
			break;
		    case 2: display(start);
		    break;
		    case 3: printf("enter element to search: ");
		    scanf("%d", &data);
		    search(start, data);
		    display(start);
		    break;
		    case 4 : printf("enter element to insert : ");
			scanf("%d",&data);
			start = addatbeg(start,data);
			display(start);
			break;
			case 5: printf("enter element to insert : ");
			scanf("%d",&data);
			start = addatend(start,data);
			display(start);
			break;
			case 6:printf("enter element to insert : ");
			scanf("%d",&data);
			printf("enter element  after which to insert : ");
			scanf("%d",&item);
			start = addaft(start,data,item);
			display(start);
			break;
			case 7 :printf("enter element to insert : ");
			scanf("%d",&data);
			printf("enter element  before which to insert : ");
			scanf("%d",&item);
			start = addbf(start,data,item);
			display(start);
			break;
			case 8: printf("enter element to insert : ");
			scanf("%d",&data);
			printf("enter element  position which to insert : ");
			scanf("%d",&pos);
			start = addpos(start,data,pos);
			display(start);
			break;
			case 9: printf("enetr element to delete :");
			scanf("%d", &data);
			start = del(start, data);
			display(start);
			break;
			case 10: start = rev(start);
			display(start);
			break;
            case 11: isempty(start);
            break;
            case 12 : size(start);
            break;
		    case 13: exit(1);
		    break;
			default: printf("wrong choice\n");
			break;
			
		}
	}
}
struct node *create(struct node *start){
	int i,n,data;
	printf("enter no of nodes :");
	scanf("%d",&n);
	start = NULL;
	if(n==0)
	  return start;
	else
	{
		printf("enter element to insert :");
		scanf("%d", &data);
		 start = addatbeg(start,data);
		for(i=2;i<=n;i++){
			printf("enter element to insert :");
			scanf("%d",&data);
			start = addatend(start,data);
		}
		display(start);
		return start;
		}
}
void display(struct node *start){
	struct node *p;
	if(start==NULL){
		printf("list is empty\n");
		return;
	}
	else{
		p=start;
		printf("list: ");
		while(p!=NULL){
			printf("%d ",p->info);
			p = p->link;
		}
	}
}
void search(struct node *start, int item){
	struct node *p = start;
	int pos = 1;
	while(p!=NULL){
		if(p->info == item){
			printf("item found at position :%d\n", pos);
			return;
		}
		p=p->link;
		pos++;
	}
	printf("item not found\n");
}
struct node *addatbeg(struct node *start,int data){
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->info = data;
	temp->link = start;
	start = temp;
	return start;
}
struct node *addatend(struct node *start,int data){
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	struct node *p;
	temp->info = data;
	p=start;
	while(p->link!=NULL){
		p  = p->link;
	}
	p->link = temp;
	temp->link = NULL;
	return start;
}
struct node *addaft(struct node *start,int data,int item){
		struct node *temp,*p;
		p=start;
			while(p!=NULL){
			    if(p->info==item){
			    	temp =  (struct node*)malloc(sizeof(struct node));
			    		temp->info = data;
			    		temp->link = p->link;
			    		p->link = temp;
			    		return start;
				}
				p = p->link;	
			}
			printf("element not present in list to insert after that\n");
			return start;
}
struct node *addbf(struct node *start,int data,int item){
	struct node *tp,*p;
	if(start == NULL){
		printf("list is empty\n");
		return start;
	}
	if(item == start->info){
		tp = (struct node*)malloc(sizeof(struct node));
		tp->info = data;
		tp->link = start;
		start = tp;
		return start;
	}
	p= start;
	while(p->link!=NULL){
		if(p->link->info == item){
			tp = (struct node*)malloc(sizeof(struct node));
			tp->info = data;
			tp->link = p->link;
			p->link = tp;
			return start;
		}
		p = p->link;
		
	}
	printf("element not present in list to insert after that\n");
	return start;

}
 struct node *addpos(struct node *start,int data,int pos){
	struct node *tp,*p;
	int i;
	tp = (struct node*)malloc(sizeof(struct node));
	tp->info = data;
	if(pos == 1){
		tp->link = start;
		start = tp;
		return start;	
	}
	p=start;
	for(i = 1;i<pos-1 &&p!=NULL; i++){
		p=p->link;
	}
	tp->link = p->link;
	p->link = tp;
	return start;	
}
struct node *del(struct node *start,int data){
	struct node *tp,*p;
	if(start == NULL){
		printf("list is empty\n");
		return start;
	}
	if(start->info == data)  // deleting 1st node
	{
		tp = start;
		start = start->link;
		free(tp);
		return start;
	}
	p=start;    //deleting between
	while(p->link!=NULL){
		if(p->link->info == data){
			tp = p->link;
			p->link = tp->link;
			free(tp);
			return start;
		}
		p = p->link;
	}
	printf("element not found to delete\n ");
	return start;	
}
struct node *rev(struct node *start){
	struct node *pre,*ptr,*next;
	pre = NULL;
	ptr = start;
	while(ptr!=NULL){
		next = ptr->link;
		ptr->link = pre;
		pre = ptr;
		ptr = next;
	}
	start = pre;
	return start;
}
void isempty(struct node *start){
	if(start == NULL){
	   printf("list is empty\n");	
	}
	else{
		printf("list is not empty\n");
	}
}
void size(struct node *start){
	int count = 0;
	struct node *temp = (struct node*)malloc(sizeof(struct node*));
	temp = start;
	while(temp!=NULL){
		count ++;
		temp =temp->link;
	}
	printf("%d ",count);
}