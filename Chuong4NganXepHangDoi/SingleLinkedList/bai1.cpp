#include <iostream>
using namespace std;

struct node {
    int info;
    node *next; //node tiep theo
};

class single_linked_list {
private:
    node* danhSachLienKet;//khoi tao 1 danh sahc
public:
    single_linked_list() {
        danhSachLienKet = NULL;
    }

    //khoi tao 1 node rieng le
    node* create_node(int value) {
        node* temp= new node;
        if (temp == NULL) {
            cout << "Khong du bo nho" << endl;
            return 0;
        }
        else {
            temp->info = value;
            temp->next = NULL;
            return temp;
        }
    }

    void insert_begin(int value) {
        node* temp, * p;
        temp = create_node(value);
        if (danhSachLienKet == NULL) {
            danhSachLienKet = temp;
        }
        else {
            p = danhSachLienKet;
            temp->next = p;
            danhSachLienKet = temp;
        }
        cout << "Hoan thanh them node vao dau" << endl;
    }
    void insert_last(int value){
        node *temp, *s;
        temp=create_node(value);
        if (danhSachLienKet=NULL){
            danhSachLienKet=temp;
            temp->next=NULL;
        }
        s=danhSachLienKet;
        while (s->next!=NULL)
        {
            s=s->next;
        }
        temp->next=NULL;
        s->next=temp;
        cout <<"Hoan thanh"<<endl;
    }
    void display() {
        node* temp;
        if (danhSachLienKet == NULL) {
            cout << "Co gi dau ma hien thi" << endl;
            return;
        }
        temp = danhSachLienKet;
        cout << "Noi dung danh sach: " << endl;
        while (temp != NULL) {
            cout << temp->info << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    void insert_pos(int value, int pos){
        int connter=0;
        node *temp, *ds, *ptr;
        temp =create_node(value);
        ds=danhSachLienKet;
        while (ds!=NULL)
        {
            ds=ds->next;
            connter++;
        }
        if(connter==0){
            cout <<"Danh sach rong"<<endl;
        }
        if(pos==1){
            if (danhSachLienKet==NULL){
                danhSachLienKet=temp;
                danhSachLienKet->next=NULL;
            }
            else{
                ptr=danhSachLienKet;
                danhSachLienKet=temp;
                danhSachLienKet->next=ptr;
            }
        }
        else if(pos>1&& pos<=connter){
            ds=danhSachLienKet;
            for (int i=1;i<pos;i++){
                ptr=ds;
                ds=ds->next;
            }
            ptr->next=temp;
            temp->next=ds;
        }
        else{
            cout <<"Vuot qua gioi han DSSLK"<<endl;
        }
    }
    void delete_pos(int pos){
        int counter =0;
        if(danhSachLienKet=NULL){
            cout <<"Rong nhe"<<endl;
            return;
        }
        node *ds, *ptr;
        ds=danhSachLienKet;
        if(pos==1){
            danhSachLienKet=ds->next;
            ds->next=NULL;
            free(ds);
        }else{
            while (ds!=NULL){
                ds=ds->next;
                counter++;
            }
            if(pos>0&&pos<=counter){
                ds=danhSachLienKet;
                for(int i=1;i<pos;i++){
                    ptr=ds;
                    ds=ds->next;
                }
                ptr->next=ds->next;
            }else{
                cout <<"Khong hop le";
            }
            
        }

    }

};

int main() {
    single_linked_list dSLK;


    dSLK.insert_begin(23);
    dSLK.insert_begin(24);
    dSLK.insert_begin(25);
    dSLK.insert_begin(25);
    dSLK.insert_begin(25);
    dSLK.insert_pos(5613,2);
    dSLK.display();
    return 0;
}
