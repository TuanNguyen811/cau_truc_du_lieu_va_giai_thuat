#include <iostream>

using namespace std;
struct node{
    int data;
    node *left;
    node *right;
};

class BinarySearchTree
{
private:
    node *root;
public:
    BinarySearchTree(){
        root=NULL;
    };
  
    node *search(node* root,int value){
        if(root==NULL||root->data==value){
            return root;
        }
        if(root->data<value){
            return search(root->right,value);
        }else{
            return search(root->left,value);
        }
    }
    //3 kieu duyet tree
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
    node *newNode(int value){
        node* temp=new node;
        temp->data=value;
        temp->left=NULL;
        temp->right=NULL;
        return temp;
    }
    node* insert(node * root, int value){
        if(root==NULL){//neu
            return newNode(value);
        }
        // day la buoc duyet den tim duong den vi tri NULL(theo dung huong)
        if(value<root->data){
            root->left=insert(root->left,value);
        }
        else{
            root->right=insert(root->right,value);
        }
        return root;
    }
    /*
    Xóa node con
    - Trường hợp 1: xóa node con chỉ có 1 cây con phải, trái => tạo liên kết đến cây con đó
    - Trường hợp 2: node có cả 2 cây con => tạo liên kế lớn nhất bên trái || nhỏ nhất bên phải
    */
    node *minValueNode(node *p){
        node *current=p;
        while (current->left!=NULL)
        {
            current =current->left;
        }
        return current;
    }
    node* deteleNode(node* root, int value){
        if(root==NULL){
            return root;// không có gì để loại bỏ
        }
        //day la phan tim duong den node value
        if(value<root->data){
            root->left=deteleNode(root->left,value);
        }
        else if(value>root->data){
            root->right=deteleNode(root->right,value);
        }
        else if(value==root->data){
            // LAM 2 TRUONG HOP
            if(root->left==NULL){
                node *temp=root->right;
                free(root);
                return temp;
            }
            else if(root->right==NULL){
                node *temp=root->right;
                free(root);
                return temp;
            }
            else{
                node *temp=minValueNode(root->right);
                root->data=temp->data;
                root->right=deteleNode(root->right,temp->data);
            }
        }
        return root;
    }
    // Hàm in cây nhị phân theo chiều ngang với các đường đi
    void printTree(node* root, int space = 0, int height = 10, string prefix = "", bool isLeft = true) {
        if (root == nullptr) return;
        space += height;
        // In nhánh phải trước
        printTree(root->right, space, height, prefix + (isLeft ? ":   " : "    "), false);
        // In node hiện tại
        cout << prefix;
        if (!prefix.empty()) {
            cout << (isLeft ? ":..." : ":'''");
        }
        cout << root->data << endl;
        // In nhánh trái sau
        printTree(root->left, space, height, prefix + (isLeft ? "    " : ":   "), true);
    }
    void function(){
        node *tmp;
        int value,choice;
        do
        {
            cout <<"\n====CAY=NHI=PHAN=TIM=KIEM====\n";
            printTree(root);
            cout <<"\nCac chuc nang\n";
            cout <<"1. Them node vao cay\n";
            cout <<"2. Xoa node tren cay\n";
            cout <<"3. Duyet cay\n";
            cout <<"4. Tim kiem node\n";
            cout <<"5. In cay nhi phan\n";
            cout <<"6. Kiem tra cay mat can bang\n";
            cout <<"0. Thoat\n";
            cout <<"Nhap lua chon: ";
            cin>>choice;
            switch (choice)
            {
            case 1:{
                system("cls");
                printTree(root);     
                int a=0;           
                while (a<100)
                {
                    cout <<"Gia tri node can them: ";
                    cin>>value;
                    if(value!=-1){
                        root=insert(root,value);
                        system("cls");
                        printTree(root);
                        a++;
                    }else{
                        break;
                    }
                }
                break;
            }
            case 2:{
                system("cls");
                printTree(root);     
                cout <<"Gia tri node can xoa: ";
                cin>>value;
                root=deteleNode(root,value);
                cout <<"Ket qua cay moi: "<<endl;
                printTree(root);
                break;
            }
            case 3:{
                system("cls");     
                cout <<"Duyet NLR: ";
                NLR(root);
                cout <<"\nDuyet LNR: ";
                LNR(root);
                cout <<"\nDuyet LRN: ";
                LRN(root);
                cout<<endl;
                break;
            }
            case 4:{
                system("cls");     
                cout <<"Gia tri node can tim: ";
                cin>>value;
                node *tmp=search(root, value);
                if(tmp==NULL){
                    cout <<"Node khong co tren cay"<<endl;
                }else{
                    cout <<"Node co tren cay: "<<tmp->data<<endl;
                }
                break;
            }
            case 5:{
                system("cls");     
                printTree(root);
                break;
            }
                break;
            
            default:
                break;
            }

        } while (choice!=0);
    }
};
int main(){
    BinarySearchTree tree;
    tree.function();
    return 0;
}

