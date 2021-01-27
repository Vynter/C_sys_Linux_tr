#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node{
    int val;
    struct Node* fg;
    struct Node* fd;
};

struct Node* CreateNode(int val){
    struct Node* tmp =(struct Node*) malloc(1*sizeof(struct Node));
    tmp->val=val;
    tmp->fg=NULL;
    tmp->fd=NULL;
    return tmp;
}

struct Node* insert(struct Node* root,int val){
    if(root == NULL)
        return CreateNode(val);
    if(root->val > val)
        root->fd=insert(root->fd,val);
    else if(root->val < val)
        root->fg=insert(root->fg,val);
    return root;
}

void PrintTreePreOrder(struct Node* root){
    if(root==NULL)
        return;
    printf("%d ",root->val);
    PrintTreePreOrder(root->fd);
    PrintTreePreOrder(root->fg);
}

int find(struct Node* root, int val){
    if(root==NULL)
        return 1;
    if(root->val == val)
        printf("la Valeur que vous chercher se trouve dans l'arbre\n");
        return 0;
    PrintTreePreOrder(root->fd);
    PrintTreePreOrder(root->fg);
    printf("la valeur que vous avez introduit ne se trouve pas dans l'arbre");
    return 1;
    
    
}

int main(){
    srand(time(NULL));
    struct Node* root = NULL;
    int randN=0,nd=0,val,res=0;
    printf("Veuillez introduire le nombre de noeuds \n");
    scanf("%d",&nd);
    
    for(int i=0;i<nd;i++){
        randN=rand()%10;
        printf("la valeur aléatoire N -%d- est : %d \n",i+1,randN);
        root=insert(root,randN);
    }
    printf("----------------\n");

    printf("Veuillez introduire le valeur que vous chercher\n ");

    scanf("%d",&val);

    find(root,val);
    PrintTreePreOrder(root);
   
    return 0;
}
