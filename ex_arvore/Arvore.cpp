#include <bits/stdc++.h>

using namespace std;

typedef struct node {
    int n;
    struct node * left;
    struct node * right;
} Node;

typedef struct arvore {
    struct node * raiz;
} Arvore;

Arvore * a = new Arvore();

void insere(int n){
    Node * at = a->raiz;
    Node * temp = new Node();
    temp->n = n;
    temp->left = NULL;
    temp->right = NULL;

    while(true){
        if(n > at->n){
            if(at->right == NULL){
                at->right = temp;
                return;
            }else{
                at = at->right;
            }
        }
        else if(n < at->n){
            if(at->left == NULL){
                at->left = temp;
                return;
            }else{
                at = at->left;
            }
        }else{
            cerr << "No existente\n";
            return;
        }
    }
}

void preordem(Node * next){
    if(next == NULL)
        cerr << "Raiz nao identificada\n";
    cout << next->n << " ";
    if(next->left)
        preordem(next->left);
    if(next->right)
        preordem(next->right);
}

void simetric(Node * next){
    if(next == NULL)
        cerr << "Raiz nao identificada\n";
    if(next->left)
        simetric(next->left);
    cout << next->n << " ";
    if(next->right){
        simetric(next->right);
    }
}

void posordem(Node * next){
    if(next == NULL)
        cerr << "Raiz nao identificada\n";
    if(next->left){
        posordem(next->left);
    }
    if(next->right){
        posordem(next->right);
    }
    cout << next->n << " ";
}

int main(){

    int aux;
    cin >> aux;
    Node * b = new Node();
    b->n = aux;
    b->left = NULL;
    b->right = NULL;
    a->raiz = b;
    
    while(cin >> aux)
        insere(aux);

    cout << "Pre ordem: "; preordem(a->raiz); cout << endl;
    cout << "Simetrica: "; simetric(a->raiz); cout << endl;
    cout << "Pos ordem: "; posordem(a->raiz); cout << endl;

}
