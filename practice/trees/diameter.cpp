#include <bits/stdc++.h>

using namespace std;

typedef struct Node{

    int data;
    struct Node *left, *right;
    Node(int data){

        this->data =  data;
        this->left = this->right = NULL;
    }
} Node;

//m1 is the naive method O(n^2)

int diameter_m2(Node *root, int *height){

    if(root==NULL){
        *height = 0;
        return 0;
    }
    int lh, rh, ld, rd;
    ld = diameter_m2(root->left, &lh);
    rd = diameter_m2(root->right, &rh);

    *height = max(lh, rh) + 1;
    return max(lh+rh+1, max(ld, rd));
}

//m3 use the height function to compute diameter
int diameter_m3(Node *root, int *diameter){

    if(root==NULL){
        *diameter = max(*diameter, 0);
        return 0;
    }

    int lh  = diameter_m3(root->left, diameter);
    int rh =  diameter_m3(root->right, diameter);

    *diameter = max(*diameter, lh+rh+1);

    return max(lh, rh)+1;

}

int main(){

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    int dummy_height = -1;
    cout<<"Diameter M2: "<<diameter_m2(root, &dummy_height)<<endl;
    int diameter = INT_MIN;
    dummy_height = diameter_m3(root, &diameter);
    cout<<"Diameter M3: "<<diameter<<endl;

    return 0;
}
