#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

// linked list first node
struct Node *ll_first = (struct Node *)malloc(sizeof(struct Node));

void Create(int A[], int n){
    struct Node *t, *last;
    ll_first->data = A[0];
    ll_first->next = NULL;
    last = ll_first;

    for(int i=1; i<n; i++){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}


void Display(struct Node *head){
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
}

void RDisplay(struct Node *head){
    if (head != NULL){
        printf("%d ", head->data);
        RDisplay(head->next);
    }
}

struct Node* CopyRecursive(struct Node *head) {
    if (head == NULL) {
        return NULL;
    }
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = head->data;
    newNode->next = CopyRecursive(head->next);
    return newNode;
}

int Count(struct Node *head){
    int count = 0;
    while(head != NULL){
        count++;
        head = head->next;
    }
    return count;
}

int RCount(struct Node *head){
    int count = 0;
    if(head != NULL)
        return RCount(head->next) + 1;
    else
        return 0;
}

int Sum(struct Node *head){
    int sum = 0;
    while(head != NULL){
        sum += head->data;
        head = head->next;
    }
    return sum;
}

int RSum(struct Node *head){
    int sum = 0;
    if(head == NULL)
        return 0;
    else
        return RSum(head->next) + head->data;
}

int Max(struct Node *head){
    int max = 0;
    while(head != NULL){
        if(head->data > max)
            max = head->data;
        head = head->next;
    }
    return max;
}

int RMax(struct Node *head){
    int max = 0;
    if(head == NULL)
        return INT32_MIN;
    max = RMax(head->next);
    if(max > head->data)
        return max;
    else
        return head->data;
}

struct Node* LinearSearch(struct Node *head, int key){

    while(head!=NULL){
        if(key == head->data)
            return head;
        head = head->next;
    }
    return NULL;
}

struct Node* LinearSearch_Move2Head(struct Node *head, int key){
    struct Node *q; // this is to optimise linear search with 'move to head' approach

    while(head!=NULL){
        if(key == head->data){
            q->next = head->next;
            head-> next = ll_first;
            ll_first = head;
            return head;
        }
        q = head; 
        head = head->next;
    }
    return NULL;
}

struct Node* LinearSearch_Transition(struct Node *head, int key){
    // TODO: implement optimization for linear search with transition approach
    return NULL;
}

struct Node* RLinearSearch(struct Node *head, int key){
    if(head == NULL)
        return NULL;
    if(key == head->data)
        return head;
    return RLinearSearch(head->next, key);
}

void Insert(struct Node *head, int index, int x){
    if(index < 0 || index > Count(head))
        return;

    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;

    if(index == 0){
        t->next = ll_first;
        ll_first = t;
    } else {
        for(int i=0; i<index-1; i++){
            head = head->next;
        }
        t->next = head->next;
        head->next = t;
    }
}

void InsertLast(struct Node *head, int x){
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    if(ll_first == NULL){
        ll_first = t;
    } else {
        while(head->next != NULL){
            head = head->next;
        }
        head->next = t;
    }
}

void InsertSorted(struct Node *head, int x){
    struct Node *t, *q = NULL;
    t = (struct Node *)malloc(sizeof(struct Node));
    t -> data = x;
    t -> next = NULL;

    if(ll_first == NULL){
        ll_first = t;
    } else {
        while(head && head->data < x){
            q = head;
            head = head->next;
        }
        if(head == ll_first){
            t->next = ll_first;
            ll_first = t;
        } else {
            t->next = q->next;
            q->next = t;
        }
    }
}

int Delete(struct Node *head, int index){
    struct Node *q = NULL;
    int x=-1, i;

    if(index < 1 || index > Count(head))
        return x;

    if(index==1){
        q = ll_first;
        x = ll_first->data;
        ll_first=ll_first->next;
        // free(q);
        return x;
    } else {
        for(i=0; i<index-1; i++){
            q=head;
            head=head->next;
        }
        q->next = head->next;
        x=head->data;
        // free(q);
        return x;
    }
}

bool IsSorted(struct Node *head){
    int x = INT32_MIN;

    while(head!=NULL){
        if(head->data < x)
            return false;
        x = head->data;
        head = head->next;
    }
    return true;
}

void RemoveDuplicate(struct Node *head){ // Linked List must be sorted?
    struct Node *q = head->next;
    if(!IsSorted(head)){
        printf("Linked list must be sorted! Exited!");
    };
    while(q != NULL){
        if(head->data != q->data){
            head = q;
            q = q->next;
        } else { 
            head->next = q->next;
            // free(q);
            q = head->next;
        }
    }
}

void ReverseWithAuxiliaryArray(struct Node *head){
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    p = head;

    int aa=Count(p);

    int *A = (int*)malloc(sizeof(int)*Count(p));
    int i = 0;
    while(p!=NULL){
        A[i] = p->data;
        p = p->next;
        i++;
    };

    p = head;
    i--;
    while(p!=NULL){
        p->data = A[i];
        p = p->next;
        i--;
    }
}

void ReverseRecursiveGlobal(struct Node *q, struct Node *p){
    // this methods also known as slider pointer method 
    // you have to use global linked ist variable for this
    if(p){
        ReverseRecursiveGlobal(p, p->next);
        p->next = q;
    } else {
        ll_first = q;
    }
}

void ReverseRecursiveAny(struct Node **head_ref) {
    struct Node* first;
    struct Node* rest;

    /* empty list */
    if (*head_ref == NULL)
       return;   

    /* suppose first = {1, 2, 3}, rest = {2, 3} */
    first = *head_ref;  
    rest  = first->next;

    /* List has only one node */
    if (rest == NULL)
       return;   

    /* reverse the rest list and put the first element at the end */
    ReverseRecursiveAny(&rest);
    first->next->next  = first;  

    /* tricky step -- see the diagram */
    first->next  = NULL;          

    /* fix the head pointer */
    *head_ref = rest;             
}

struct Node* ReverseRecursiveAny2(struct Node *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct Node* new_head = ReverseRecursiveAny2(head->next);
    head->next->next = head;
    head->next = NULL;
    return new_head;
}

struct Node* Concat(struct Node *p, struct Node *q){
    struct Node *p_copy = CopyRecursive(p);
    struct Node *q_copy = CopyRecursive(q);
    struct Node *head = p_copy;
    while (p_copy->next != NULL){
        p_copy = p_copy->next;
    }
    p_copy->next = q_copy;
    return head;
}

struct Node* MergeSorted(struct Node *p, struct Node *q){
    struct Node *third, *last;
    if(p->data < q->data){
        third = last = p;
        p = p->next;
        last->next = NULL;
    } else {
        third = last = q;
        q = q->next;
        last->next = NULL;
    }
    while(p && q){
        if(p->data < q->data){
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        } else {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    if(p) last->next = p;
    if(q) last->next = q;

    return third;
}

int IsLoop(struct Node *head){
    struct Node *p, *q;
    p=q=head;
    
    do{
        p = p->next;
        q = q->next;
        q = q?q->next:q; 
    }while(p && q && p!=q);

    if(p==q)
        return 1;
    else
        return 0;
}


int main(){
    int A[] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
    int n = 11;

    Create(A, 11);
    
    printf("Display: ");
    Display(ll_first);
    printf("RDisplay: ");
    RDisplay(ll_first);

    printf("\n");
    printf("\n");
    printf("Node Count: %d \n", Count(ll_first));
    printf("Node Count: %d \n", RCount(ll_first));

    printf("\n");
    printf("Sum: %d \n", Sum(ll_first));
    printf("RSum: %d \n", RSum(ll_first));

    printf("\n");
    printf("Max: %d \n", Max(ll_first));
    printf("RMax: %d \n", RMax(ll_first));

    struct Node *temp;
    int key = 21;
    temp = LinearSearch(ll_first, key);
    printf("\n");
    if(temp != NULL){
        printf("Key is found - Iterative Linear Search : %d \n", temp->data);
        printf("Display: ");
        Display(ll_first);

    } else {
        printf("Key is not in the list.. \n");
    }

    key = 13;
    temp = LinearSearch_Move2Head(ll_first, key);
    if(temp != NULL){
        printf("Key is found - Iterative Linear Search : %d \n", temp->data);
        printf("Display: ");
        Display(ll_first);
    } else {
        printf("Key is not in the list.. \n");
    }

    key = 34;
    temp = RLinearSearch(ll_first, key);
    if(temp != NULL){
        printf("Key is found - Recursive Linear Search : %d \n", temp->data);
        printf("Display: ");
        Display(ll_first);
    } else {
        printf("Key is not in the list.. \n");
    }

    printf("\n\n");

    Insert(ll_first, 0, 99);
    Insert(ll_first, 0, 98);
    printf("Insert: ");
    Display(ll_first);

    printf("\n\n");

    int tmp[] = {1, 2, 3, 4, 5};
    struct Node *ll_first2 = (struct Node *)malloc(sizeof(struct Node));
    ll_first2->next = NULL;
    for (int i=0; i<5; i++){
        InsertLast(ll_first2, tmp[i]);
    }
    printf("Create Linked List with InsertLast(), Display: ");
    Display(ll_first2);

    printf("\n\n");

    struct Node *ll_sorted = (struct Node *)malloc(sizeof(struct Node));
    ll_sorted->next = NULL;
    for (int i=0; i<11; i++){
        InsertLast(ll_sorted, i*3);
    }
    printf("Create Sorted Linked List with InsertLast(), Display: ");
    Display(ll_sorted);
    InsertSorted(ll_sorted, 7);
    InsertSorted(ll_sorted, 2);
    InsertSorted(ll_sorted, 23);
    printf("after InsertSorted: ");
    Display(ll_sorted);

    printf("\n\n");


    printf("Before Delete: ");
    Display(ll_first);
    Delete(ll_first, 3);
    Delete(ll_first, 2);
    Delete(ll_first, 1);
    printf("After Delete: ");
    Display(ll_first);

    printf("\n\n");

    Display(ll_first);
    printf("is  sorted? : %d \n", IsSorted(ll_first));
    Display(ll_first2);
    printf("is  sorted? : %d \n", IsSorted(ll_first2));
    Display(ll_sorted);
    printf("is  sorted? : %d \n", IsSorted(ll_sorted));

    printf("\n\n");

    struct Node *ll_duplicated = (struct Node *)malloc(sizeof(struct Node));
    for(int i=0; i<5; i++){
        InsertLast(ll_duplicated, i*10);
        Insert(ll_duplicated, i*2, i*10);
    };
    printf("ll_duplicated: ");
    Display(ll_duplicated);
    RemoveDuplicate(ll_duplicated);
    printf("\nafter removing duplications : ");
    Display(ll_duplicated);

    printf("\n\n");

    printf("Before reversing with ReverseWithAuxiliaryArray(): ");
    Display(ll_sorted);
    ReverseWithAuxiliaryArray(ll_sorted);
    printf("\nAfter reversing with ReverseWithAuxiliaryArray(): ");
    Display(ll_sorted);
    ReverseWithAuxiliaryArray(ll_sorted);


    printf("\n\n");

    printf("Before reversing with ReverseRecursiveAny(): ");
    Display(ll_sorted);
    ReverseRecursiveAny(&ll_sorted);
    printf("\nAfter reversing with ReverseRecursiveAny(): ");
    Display(ll_sorted);

    printf("\n\n");

    printf("Before reversing with ReverseRecursiveGlobal(): ");
    Display(ll_first);
    ReverseRecursiveGlobal(NULL, ll_first);
    printf("\nAfter reversing with ReverseRecursiveGlobal(): ");
    Display(ll_first);

    printf("\n\n");

    int tmp2[] = {1, 2, 3, 4, 5};
    struct Node *ll_second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *ll_third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *ll_fourth = (struct Node *)malloc(sizeof(struct Node));
    ll_second->next = NULL;
    ll_third->next = NULL;
    ll_fourth->next = NULL;
    for (int i=0; i<5; i++){
        InsertLast(ll_second, tmp2[i]*2);
        InsertLast(ll_third, tmp2[i]*3);
    }

    printf("\nll_second: ");
    Display(ll_second);
    printf("\nll_third: ");
    Display(ll_third);
    ll_fourth = Concat(ll_second, ll_third);
    printf("\nll_second and ll_third concentenation: ");
    Display(ll_fourth);

    printf("\n\n");

    printf("\nll_second: ");
    Display(ll_second);
    printf("\nll_third: ");
    Display(ll_third);
    ll_fourth->next = NULL;
    ll_fourth = MergeSorted(ll_second, ll_third);
    printf("\nll_second and ll_third merge: ");
    Display(ll_fourth);

    printf("\n\n");
    // form a looped linked list
    struct Node *ll_fifth = (struct Node *)malloc(sizeof(struct Node));
    ll_fifth->next = NULL;
    for (int i=0; i<5; i++){
        InsertLast(ll_fifth, tmp2[i]);
    }
    struct Node *t1, *t2;
    t1 = ll_fifth->next->next;
    t2 = ll_fifth->next->next->next->next;
    t2->next = t1;

    printf("IsLoop ll_fifth? : %d", IsLoop(ll_fifth)); // yes 
    printf("\nIsLoop ll_fourth? : %d\n", IsLoop(ll_fourth)); // no
    return 0;
}

