#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    int height;
};
class AVL_Tree{
    private:
    Node *root;
    public:
    AVL_Tree(){
        root=NULL;
    }
    int max(int a, int b){
        if(a>b){
            return a;
        }else{
            return b;
        };
    }
    int height(Node *node){
        if(node==NULL){
            return 0;
        }
        return node->height;
    }
    Node *newNode(int value){
        Node*tmp=new Node();
        tmp->left=NULL;
        tmp->right=NULL;
        tmp->height=1;
        tmp->data=value;
        return tmp;
    }
    Node *search(Node* root, int value){
        if(root==NULL||root->data==value){
            return root;
        }
        if(root->data<value){
            return search(root->right,value);
        }else{
            return search(root->left,value);
        }
    }
    //ham dich trai
    Node *leftRotate(Node *x){
        Node *y=x->right;//con phai cua node
        Node *T2=y->left;// con trai cua con phai
        //thực hiện phép xoay trai
        y->left=x;
        x->right=T2;
        //cap nhap do cap
        x->height=max(height(x->left),height(x->right))+1;
        y->height=max(height(y->right),height(y->left))+1;
        return y;
    }
    Node *rightRotate(Node *y){
        Node *x=y->left;
        Node *T2=x->right;
        //thuc hien phem xoay cay
        x->right=y;
        y->left=T2;
        //cap nhat dia chi cho cay
        x->height=max(height(x->left),height(x->right))+1;
        y->height=max(height(y->right),height(y->left))+1;
        return x;
    }
    //tim chi so can bang cua node= chieu cao node trai - chieu cao node phai
    int getBalance(Node *N){
        if(N==NULL){
            return 2;
        }
        return height(N->left)-height(N->right);
    }
    // ham them
    Node *insert(Node* node, int data){
        //B1 thức hiện thêm node
        if(node ==NULL){
            return newNode(data);
        }
        if(data <node->data){
            node->left=insert(node->left,data);
        }else{
            node->right=insert(node->right,data);
        }
        //B2 cập nhật độ cao cho node
        node->height=max(height(node->right),height(node->left))+1;
        //B3 lấy chỉ số cân bằng
        int balance=getBalance(node);
        // Nếu node mất cân bằng, có 4 trường hợp
        // Trường hợp Left Left
        if (balance > 1 && data < node->left->data){
            return rightRotate(node);
        }
        // Trường hợp Right Right
        if (balance < -1 && data > node->right->data){
            return leftRotate(node);
        }
        // Trường hợp Left Right
        if (balance > 1 && data > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        // Trường hợp Right Left
        if (balance < -1 && data < node->right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        return node;
    }
    Node *insertNOTreeAVL(Node* root, int value){
        if(root==NULL){
            return newNode(value);
        }
        if(value <root->data){
            root->left=insertNOTreeAVL(root->left,value);
        }else{
            root->right=insertNOTreeAVL(root->right,value);
        }
        root->height=max(height(root->right),height(root->left))+1;
        return root;
    }
    void kiemTraCayCanBang(Node* root){
        if(root==NULL){
            return;
        }
        int balance = getBalance(root);
        //cout <<"Chi so can bang"<<root->data<<" = "<<balance<<endl;
        if (balance > 1 && getBalance(root->left) >= 0) {
            cout <<"Node "<<root->data<<" Mat can bang left left"<<endl;
        }
        if (balance > 1 && getBalance(root->left) < 0) {
            cout <<"Node "<<root->data<<" Mat can bang lef right"<<endl;
        }
        if (balance < -1 && getBalance(root->right) <= 0) {
            cout <<"Node "<<root->data<<" Mat can bang right right"<<endl;
        }
        if (balance < -1 && getBalance(root->right) > 0) {
            cout <<"Node "<<root->data<<" Mat can bang right left"<<endl;
        }
        //duyet cac node khac trong cay
        kiemTraCayCanBang(root->left);
        kiemTraCayCanBang(root->right);
    }
    Node* canBangCay(Node* root){
        int balance = getBalance(root);
        // Cân bằng cây
        if (balance > 1 && getBalance(root->left) >= 0) {//LL
            return rightRotate(root);
        }
        if (balance > 1 && getBalance(root->left) < 0) {//LR
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        if (balance < -1 && getBalance(root->right) <= 0) {//RR
            return leftRotate(root);
        }
        if (balance < -1 && getBalance(root->right) > 0) {//RL
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
        return root;
    }
    Node *minValueNode(Node* node){
        Node* tmp=node;
        while (tmp->left!=NULL)
        {
            tmp=tmp->left;            
        }
        return tmp; 
    }
    Node *deleteNode(Node *root, int key) {
        // B1: Thực hiện tìm kiếm key
        if (root == NULL) {
            return root;
        }
        // Tìm đường đi đến key
        if (key < root->data) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->data) {
            root->right = deleteNode(root->right, key);
        } else {
            // Trường hợp tìm thấy key
            if ((root->left == NULL) || (root->right == NULL)) {
                Node *tmp = root->left ? root->left : root->right;
                if (tmp == NULL) {
                    tmp = root;
                    root = NULL;
                } else {
                    *root = *tmp;
                }
                free(tmp);
            } else {
                Node *tmp = minValueNode(root->right);
                root->data = tmp->data;
                root->right = deleteNode(root->right, tmp->data);
            }
        }

        // B2: Kiểm tra cây có mất cân bằng hay không
        if (root == NULL) {
            return root;
        }
        root->height = max(height(root->left), height(root->right)) + 1;
        int balance = getBalance(root);
        // Cân bằng cây
        if (balance > 1 && getBalance(root->left) >= 0) {
            return rightRotate(root);
        }
        if (balance > 1 && getBalance(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        if (balance < -1 && getBalance(root->right) <= 0) {
            return leftRotate(root);
        }
        if (balance < -1 && getBalance(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
        return root;
    }
    Node* deteleNodeKhongCanBang(Node* root, int value){
        if(root==NULL){
            return root;// không có gì để loại bỏ
        }
        //day la phan tim duong den node value
        if(value<root->data){
            root->left=deteleNodeKhongCanBang(root->left,value);
        }
        else if(value>root->data){
            root->right=deteleNodeKhongCanBang(root->right,value);
        }
        else if(value==root->data){
            // LAM 2 TRUONG HOP
            if(root->left==NULL){
                Node *temp=root->right;
                free(root);
                return temp;
            }
            else if(root->right==NULL){
                Node *temp=root->right;
                free(root);
                return temp;
            }
            else{
                Node *temp=minValueNode(root->right);
                root->data=temp->data;
                root->right=deteleNodeKhongCanBang(root->right,temp->data);
            }
        }
        return root;
    }
    
    void printTree(Node* root, int space = 0, int height = 10, string prefix = "", bool isLeft = true) {
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
    //3 kieu duyet tree
    void NLR(Node*root){// duyet thu tu truoc
        if(root!=NULL){
            cout <<root->data<<" ";
            NLR(root->left);
            NLR(root->right);
        }
    }
    void LNR(Node *root){// thu tu giua
        if(root!=NULL){
            LNR(root->left);
            cout <<root->data<<" ";
            LNR(root->right);
        }
    }
    void LRN(Node *root){
        if(root!=NULL){
            LRN(root->left);
            LRN(root->right);
            cout <<root->data<<" ";
        }
    }
    void function(){
        Node *tmp;
        int value,choice;
        do
        {
            cout <<"\n====CAY NHI PHAN TIM KIEM====\n";
            printTree(root);
            cout <<"1. Them node vao cay can bang\n";
            cout <<"2. Xoa node tren cay can bang\n";
            cout <<"3. Duyet cay NLR LNR LRN\n";
            cout <<"4. Tim kiem node co trong cay\n";
            cout <<"5. In cay nhi phan\n";
            cout <<"----------------------------\n";
            cout <<"6. Them node vao cay\n";
            cout <<"7. Kiem tra cay can bang\n";
            cout <<"8. Xoa node cay\n";
            cout <<"0. Thoat\n";
            cout <<"Nhap lua chon: ";
            cin>>choice;
            switch (choice)
            {
            case 1:{
                system("cls");
                printTree(root);
                int a=0;     
                while (true)
                {
                    cout <<"Gia tri node can them(-1 exit): ";
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
                int a=0;     
                while (true)
                {
                    cout <<"Gia tri node can xoa(-1 exit): ";
                    cin>>value;
                    if(value!=-1){
                        root=deleteNode(root,value);
                        system("cls");
                        printTree(root);
                        a++;
                    }else{
                        break;
                    }
                }
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
                Node *tmp=search(root, value);
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
            case 6:{
                system("cls");
                printTree(root);
                int a=0;     
                while (true)
                {
                    cout <<"Gia tri node can them(-1 exit): ";
                    cin>>value;
                    if(value!=-1){
                        root=insertNOTreeAVL(root,value);
                        system("cls");
                        printTree(root);
                        a++;
                    }else{
                        break;
                    }
                }
                kiemTraCayCanBang(root);           
                break;
            }
            case 7:{
                cout <<"\nNode mat can bang:\n";
                kiemTraCayCanBang(root); 
                break;          
            }
            case 8:{
                system("cls");
                printTree(root);
                int a=0;     
                while (true)
                {
                    cout <<"Gia tri node can xoa(-1 exit): ";
                    cin>>value;
                    if(value!=-1){
                        root=deteleNodeKhongCanBang(root,value);
                        system("cls");
                        printTree(root);
                        a++;
                    }else{
                        break;
                    }
                }
                break;
            }
            default:
                break;
            }
        } while (choice!=0);
    }
};
int main(){
    AVL_Tree tree;
    tree.function();
    return 0;
}