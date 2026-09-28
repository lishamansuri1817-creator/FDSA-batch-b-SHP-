#include <iostream>
using namespace std;
struct Node{
    string song;
    Node* prev;
    Node* next;
};
Node* head=NULL;
void addBeginning(string song){
    Node* newNode=new Node;
    newNode->song=song;
    newNode->prev=NULL;
    newNode->next=head;
    if(head!=NULL)
        head->prev=newNode;
    head=newNode;
}
void addEnd(string song){
    Node* newNode=new Node;
    newNode->song=song;
    newNode->next=NULL;
    if(head==NULL){
        newNode->prev=NULL;
        head=newNode;
        return;
    }
    Node* temp=head;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=newNode;
    newNode->prev=temp;
}
void insertAfter(string givenSong,string newSong){
    Node* temp=head;
    while(temp!=NULL && temp->song!=givenSong)
        temp=temp->next;
    if(temp==NULL){
        cout<<"Song not found!"<<endl;
        return;
    }
    Node* newNode=new Node;
    newNode->song=newSong;
    newNode->next=temp->next;
    newNode->prev=temp;
    if(temp->next!=NULL)
        temp->next->prev=newNode;
    temp->next=newNode;
}
void removeFirst(){
    if(head==NULL){
        cout<<"Playlist is empty!"<<endl;
        return;
    }
    Node* temp=head;
    head=head->next;
    if(head!=NULL)
        head->prev=NULL;
    delete temp;
}
int countSongs(){
    int count=0;
    Node* temp=head;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}
void display(){
    Node* temp=head;
    cout<<"Playlist: ";
    while(temp!=NULL){
        cout<<temp->song<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    int choice;
    string song,givenSong;
    do{
        cout<<"\n1. Add Beginning\n2. Add End\n3. Insert After\n4. Remove First\n5. Count Songs\n6. Display\n7. Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter song: ";
                cin>>song;
                addBeginning(song);
                display();
                break;
            case 2:
                cout<<"Enter song: ";
                cin>>song;
                addEnd(song);
                display();
                break;
            case 3:
                cout<<"Enter existing song: ";
                cin>>givenSong;
                cout<<"Enter new song: ";
                cin>>song;
                insertAfter(givenSong,song);
                display();
                break;
            case 4:
                removeFirst();
                display();
                break;
            case 5:
                cout<<"Number of songs: "<<countSongs()<<endl;
                break;
            case 6:
                display();
                break;
            case 7:
                cout<<"Exiting..."<<endl;
                break;
            default:
                cout<<"Invalid choice!"<<endl;
        }
    }while(choice!=7);
    return 0;
}
