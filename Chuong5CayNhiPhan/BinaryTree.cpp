#include <iostream>
using namespace std;
struct node
{
    int data;
    node* left;
    node* right;
};

class Tree{
    node *tree;
    public:
    Tree(){
        tree->data=NULL;
    }
    //ham tao node roi rac
    node* make_NodeNew(int value){
        node *tmp=new node();
        tmp->data=value;
        tmp->left=NULL;
        tmp->right=NULL;
        return tmp;
    }
    //ham tao goc cho Tree
    void make_Root(){
        if(tree!=NULL){
            cout <<"Cay da co goc\n";
        }else{
            node *tmp=make_NodeNew(1);
            tree=tmp;
        }
    }
    //them node left cho node co gia tri vule
    void insert_Lift(node *root,int valueNode,int valueInsert){
        if(root!=NULL){
            if(root->data==valueNode){
                //neu tim thay dung node co gia tri valu
                if(root->left!=NULL){
                    cout <<"Node "<<valueNode<<" da co node con trai"<<endl;
                    return;
                }
                else{
                    root->left=make_NodeNew(valueInsert);
                    return;
                }
            }
            //Day la buoc duyen cay de tim node co gia tri vodeNode nhe
            insert_Lift(root->left,valueNode,valueInsert);
            insert_Lift(root->right,valueNode,valueInsert);
        }
    }
    //thao tacs them node phai
    void insert_Right(node *root, int valueNode, int valueInsert){
        if(root!=NULL){
           if(root->data==valueNode){
                //neu tim thay dung node co gia tri valu
                if(root->right!=NULL){
                    cout <<"Node "<<valueNode<<" da co node con trai"<<endl;
                    return;
                }
                else{
                    root->right=make_NodeNew(valueInsert);
                    return;
                }
            }
            //Day la buoc duyen cay de tim node co gia tri vodeNode nhe
            insert_Right(root->left,valueNode,valueInsert);
            insert_Right(root->right,valueNode,valueInsert);
        }
    }
    //loai bo la ben tra
    void remove_Lift(node *root,int valueNode){
        if(root!=NULL){
            if(root->data==valueNode){
                if(root->left==NULL){
                    cout <<"Node "<<valueNode<<" khong co la trai\n";
                    return;
                }
                else if((root->left)->left!=NULL||(root->left)->right!=NULL){
                    cout <<valueNode<<" Khong phai la\n";
                }
                else if((root->left)->left==NULL||(root->left)->right==NULL){
                    node *tmp=root->left;
                    root->left=NULL;
                    delete(tmp);
                    return;
                }
            }
            remove_Lift(root->left,valueNode);
            remove_Lift(root->right,valueNode);
        }
    }
    //loai bo la ben phai
    void remove_Right(node *root,int valueNode){
        if(root!=NULL){
            if(root->data==valueNode){
                if(root->right==NULL){
                    cout <<"Node "<<valueNode<<" khong co la phai\n";
                    return;
                }
                else if((root->right)->left!=NULL||(root->right)->right!=NULL){
                    cout <<valueNode<<" Khong phai la\n";
                }
                else if((root->right)->left==NULL||(root->right)->right==NULL){
                    node *tmp=root->right;
                    root->right=NULL;
                    delete(tmp);
                    return;
                }
            }
            remove_Lift(root->left,valueNode);
            remove_Lift(root->right,valueNode);
        }
    }
    //loai bo cay
    void clear_Tree(node *root){
        if(root!=NULL){
            clear_Tree(root->left);
            clear_Tree(root->right);
            cout <<"Node "<<root->data<<" Duoc gia phong\n";
            delete(root);
        }
    }
    //3 phep duyet cay
    void NLR(node*root){// duyet thu tu truoc
        if(root!=NULL){
            cout <<root->data<<" ";
            NLR(root->left);
            NLR(root->right);
        }
    }
    void LNR(node *root){// thu tu giua
        if(root!=NULL){
            LNR(root->left);
            cout <<root->data<<" ";
            LNR(root->right);
        }
    }
    void LRN(node *root){
        if(root!=NULL){
            LRN(root->left);
            LRN(root->right);
            cout <<root->data<<" ";
        }
    }
    void function(){
        int choice,value,valueNode;
        node *tmp;
        do
        {
            cout <<"\nCAC THAO TAC TREN CAY"<<endl;
            cout <<"1. Tao node goc"<<endl;
            cout <<"2. Tao node la trai"<<endl;
            cout <<"3. Tao node la phai"<<endl;
            cout <<"4. Loai bo la trai"<<endl;
            cout <<"5. Loai bo la phai"<<endl;
            cout <<"6. Loai bo cay"<<endl;
            cout <<"7. Duyet NLR"<<endl;
            cout <<"8. Duyet LNR"<<endl;
            cout <<"9. Duyet LRN"<<endl;
            cout <<"0. Thoat"<<endl;
            cout <<"Lua chon: ";
            cin>>choice;
            switch (choice)
            {
            case 1:{
                make_Root();
                break;
            }
            case 2:{
                cout <<"Node can them trai: ";
                cin>>valueNode;
                cout <<"Gia tri: ";
                cin>>value;
                insert_Lift(tree,valueNode,value);
                break;
            }
            case 3:{
                cout <<"Node can them phai: ";
                cin>>valueNode;
                cout <<"Gia tri: ";
                cin>>value;
                insert_Right(tree,valueNode,value);
                break;
            }
            case 4:{
                cout <<"Node can xoa la trai: ";
                cin>>valueNode;
                remove_Lift(tree,valueNode);
                break;
            }
            case 5:{
                cout <<"Node can xoa la phai: ";
                cin>>valueNode;
                remove_Right(tree,valueNode);
                break;
            }
            case 6:{
                clear_Tree(tree);
                break;
            }
            case 7:{
                cout <<"Duyet NLR: ";
                NLR(tree);
                cout <<endl;
                break;
            }
            case 8:{
                cout <<"Duyet LNR: ";
                LNR(tree);
                cout <<endl;
                break;
            }
            case 9:{
                cout <<"Duyet LRN: ";
                LRN(tree);
                cout <<endl;
                break;
            }
            default:
                break;
            }

        } while (choice!=0);
    }
};
int main(){
    Tree tree;
    tree.function();
    return 0;
}