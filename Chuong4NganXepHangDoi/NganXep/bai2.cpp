#include <iostream>
#define MAXSIZE 5

using namespace std;

struct node {
    int info;
    node* link;
};

class stack_list {
private:
    node* danhSachHangDoi;

public:
    stack_list() {
        danhSachHangDoi = NULL;
    }

    node* push(int it) {
        node* tmp = new node;
        tmp->info = it;
        tmp->link = danhSachHangDoi; // Liên kết nút mới với danh sách hiện tại
        danhSachHangDoi = tmp; // Cập nhật con trỏ danhSachHangDoi để trỏ đến nút mới
        return tmp; // Trả về con trỏ đến nút mới được thêm vào
    }
    node *pop(){
        node * tmp;
        if (danhSachHangDoi==NULL){
            cout <<"Danh sach rong"<<endl;
        }
        else{
            tmp=danhSachHangDoi;
            cout <<"Phan tu bi loai bo: "<<tmp->info<<endl;
            danhSachHangDoi=danhSachHangDoi->link;
            free(tmp);
        }
        return danhSachHangDoi;
    }
    void show(){
        node *ptr;
        ptr=danhSachHangDoi;
        if(danhSachHangDoi==NULL){
            cout <<"Danh sach rong"<<endl;
        }
        else{
            cout <<"Noi dung:\n ";
            while (ptr!=NULL)
            {
                cout <<ptr->info<<endl;
                ptr=ptr->link;
            } 
        }
    }

};

int main() {
    stack_list myStack;
    int luaChon;
    do
    {
        cout <<"1. Xem ngan xep\n";
        cout <<"2. Them\n";
        cout <<"3. Lay\n";
        myStack.show();
        cin>>luaChon;
        switch (luaChon)
        {
        case 1: {
            myStack.show();
            break;
        }
        case 2:{
            int item;
            cout <<"Gia tri can them: ";
            cin>>item;
            myStack.push(item);
            break;
        }
        case 3:{
            myStack.pop();
            break;
        }
            break;
        
        default:
            break;
        }
    } while (luaChon!=0);
    return 0;
}
