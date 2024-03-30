#include<stdio.h>
int list[100], n;

int linsearch(int item) {
    int i, flag=0;
    for(i=0;i<n;i++) {
        if(list[i] == item) {
            flag=1;
            break;
        }
    }
    if(flag==0){
        return -1;
    }
    else {
        return i;
    }        
}

int linsearch_rec(int item, int size) {
    if(list[size]==item) {
        return size;
    }
    if(size==-1) {
        return-1;
    }
    linsearch_rec(item, size-1);    
}

void input() {
    int i;
    printf("Enter the elements:- ");
    for(i=0;i<n;i++) {
        scanf("%d", &list[i]);
    }
}

void output() {
    for(int i=0;i<n;i++) {
        printf("%d \t",list[i]);
    }
}

int main() {
    int item, ch=1, index, size;
    printf("\n Enter the no. of elements of array :- ");
    scanf("%d", &n);
    input();
    printf("The elements entered are:- ");
    output();

    while(ch!=0) {
        printf("\n--Menu--\n 1.Iterative Linear Search\n 2.Recursive Linear Search");
        printf("\nEnter your choice :-\n");
        scanf("%d",&ch);
        switch(ch) {
            case 0: break;
            case 1: printf("\n Enter item to be searched:- ");
                    scanf("%d",&item);
                    index = linsearch(item);
                    if(index==-1) {
                        printf("Element not found");
                    }
                    else {
                        printf("\n Item found at position:- %d",index);
                    }
                    break;
            case 2: printf("\n Enter item to be searched:- ");
                    scanf("%d",&item);
                    size = n-1;
                    index = linsearch_rec(item, size);
                    if(index==-1) {
                        printf("Element not found");
                    }
                    else {
                        printf("\n Item found at position:- %d",index);
                    }
                    break;
        }
    }

    return 0;
}