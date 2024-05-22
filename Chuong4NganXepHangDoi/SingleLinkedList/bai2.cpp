#include <iostream>
#include <string>
using namespace std;
struct node
{   
    string maSoSinhVien;
    string tenSinhVien;
    int cmnd;
    node *next;
};
class QuanLySinhVien{
private:
    node *danhSachSinhVien;
public:
    QuanLySinhVien(){
        danhSachSinhVien=NULL;
    }
    node* taoNodeMoi(string maSoSinhVien, string tenSinhVien, int cmnd){
        node *temp=new node;
        temp->maSoSinhVien=maSoSinhVien;
        temp->tenSinhVien=tenSinhVien;
        temp->cmnd=cmnd;
        temp->next=NULL;
        return temp;
    }
    void duyetDanhSach(){
        node* temp=danhSachSinhVien;
        while (temp!=NULL)
        {
            cout <<"MSSV: "<<temp->maSoSinhVien<<endl;
            cout <<"Ten: "<< temp->tenSinhVien<<endl;
            cout <<"CMND: "<<temp->cmnd<<endl;
            cout <<endl;
            temp=temp->next;
        }
    }
    void themSinhVien(){
        string maSoSinhVien;
        string tenSinhVien; 
        int cmnd;
        cout <<"Nhap MSSV: ";
        getline(cin,maSoSinhVien);
        cout <<"Nhap ten: ";
        getline(cin,tenSinhVien);
        cout <<"Nhap cmnd: ";
        cin>>cmnd;
        cin.ignore();
        node* temp= taoNodeMoi(maSoSinhVien,tenSinhVien,cmnd);//tao node roi rac
        if(danhSachSinhVien==NULL){
            danhSachSinhVien=temp;
        }
        else{
            temp->next=danhSachSinhVien;
            danhSachSinhVien=temp;   
        }
    }
};
int main(){
    QuanLySinhVien quanLySinhVien;
    int luaChon;
    do
    {
        cout <<"-----------------------------\n";
        cout <<"1. Them 1 sinh vien\n";
        cout <<"2. Nhap danh sach\n";
        cout <<"2. Duyet danh sach sinh vien\n";
        cout <<"0. Thoat\n";
        cout <<"-----------------------------\n";

        cin>>luaChon;
        cin.ignore();
        switch (luaChon)
        {
        case 1:{
            quanLySinhVien.themSinhVien();
            break;
        }
        case 2:{
            quanLySinhVien.duyetDanhSach();
            break;
        }
        default:
            break;
        }
    } while (luaChon!=0);
    
    return 0;
}