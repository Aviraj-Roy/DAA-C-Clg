#include<stdio.h>
int list[100], n;

int binsearch(int item) {
    int lb=0, ub=n-1,mid;
    while(lb<=ub) {
        mid = (lb+ub)/2;
        if(item == list[mid]) {
            return mid;
        }
        if(item < list[mid]) {
            ub = mid-1;
        }
        else {
            lb = mid+1;
        }
    }
    return -1;
}

int binsearch_rec(int lb, int ub, int item) {
    int mid = (lb+ub)/2;
    if(lb > ub) {
        return -1;
    }
    if(lb <= ub) {
        if (item == list[mid])        {
            return mid;
        }
        else if(item < list[mid]) {
            binsearch_rec(lb, mid-1, item);
        }
        else {
            binsearch_rec(mid+1, ub, item);
        }        
    }
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

    int lb=0,ub=n-1;

    while(ch!=0) {
        printf("\n--Menu--\n 1.Iterative Binary Search\n 2.Recursive Binary Search");
        printf("\nEnter your choice :-\n");
        scanf("%d",&ch);
        switch(ch) {
            case 0: break;
            case 1: printf("\n Enter item to be searched:- ");
                    scanf("%d",&item);
                    index = binsearch(item);
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
                    index = binsearch_rec(lb, ub, item);
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
