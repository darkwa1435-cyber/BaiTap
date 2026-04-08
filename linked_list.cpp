#include<iostream>
#include<string>
using namespace std;
struct time_created {
    int year, month, date, hour, minute;
};
struct file {
    string name;
    float size;
    time_created t;
};
struct Node {
    file data;
    Node* next;
};
bool time_compare (time_created t1, time_created t2){
    if (t1.year != t2.year) return t1.year < t2.year;
    if (t1.month != t2.month) return t1.month < t2.month;
    if (t1.date != t2.date) return t1.date < t2.date;
    if (t1.hour != t2.hour) return t1.hour < t2.hour;
    if (t1.minute != t2.minute) return t1.minute < t2.minute;
}
Node* createnode(string n, float s, time_created t){
    Node* newNode = new Node;
    newNode -> data.name = n;
    newNode -> data.size = s;
    newNode -> data.t = t;
    newNode -> next = NULL;
    return newNode;
}
void Chen_file (Node* &H, string n, float s, time_created t){
    Node* newNode = createnode (n,s,t);
    if (H == NULL || time_compare(t, H -> data.t)){
        newNode -> next = H;
        H = newNode;
        return;
    }
    Node* hientai = H;
    while (H != NULL && time_compare(hientai ->next -> data.t,t)){
        hientai = hientai -> next;
    }
    newNode -> next = hientai -> next;
    hientai -> next = newNode;
}
float tinh_size (Node* H){
    float sum = 0.0f;
    Node* hientai = H;
    while (hientai != NULL){
        sum += hientai -> data.size;
        hientai = hientai -> next;
    }
    return sum;
}
void xoa_file_nho_nhat (Node* &H){
    if (H == NULL) return;
    Node *minNode = H, *minPrevious = NULL;
    Node *current = H, *previous = NULL;
    while (current != NULL){
        if (current -> data.size < minNode -> data.size){
            minNode = current;
            minPrevious = previous;
        }
        previous = current;
        current = current -> next;
    }
    if (minNode == H){
        H = H -> next;
    }
    else {
        minPrevious -> next = minNode -> next;
    }
    delete minNode;
}
void sao_luu(Node* &H){
    float limit = 32.0 * 1024;
    while (tinh_size(H) > limit){
        xoa_file_nho_nhat(H);
    }
}
int main(){
    Node* folderD = NULL;
    Chen_file (folderD,"abc.docx",3667.0,{2018,7,30,15,36});
    Chen_file (H,);
}