#include<iostream>
using namespace std ;

class node{
  public :
  int data ;
  node* next ;

  node(int value){
    this -> data = value ;
    this -> next = NULL ;
  }
};

class CircularLinkedList{
  private :
    node* head ;

  public :
    CircularLinkedList(){
      this -> head = NULL ;
    }

    void insertAtBegin(int value){
      node* newNode = new node(value);

      // if linked list is empty
      if(head == NULL){
        //point head to new node
        head = newNode ;
        // point new node to head/ newNode
        newNode -> next = head ;
      }

      else{
        node* temp = head;

        // go to last node
        while(temp -> next != head){
          temp = temp -> next ;
        }
        // point new node to first element
        newNode -> next = head ;
        // point head to new node
        head = newNode ;
        // point last element to newNode
        temp -> next = newNode;
      }
      return ;
    }

    void insertAtTail(int value){
      node* newNode = new node(value);

      //if list is empty
      if(head == NULL){
        // point head to newNode
        head = newNode ;
        //point newNode to head/newNode
        newNode -> next = head ;
      }
      else{
        node* temp = head ;
        //go to last node
        while(temp -> next != head){
          temp = temp -> next ;
        }
        //point last node to new node
        temp -> next = newNode ;
        //point new node to head
        newNode -> next = head ;
      }

      }

      void insertAtK(int value , int pos){

        node* newNode = new node(value) ;
        // if linked list is empty
        if(head == NULL){
          // point head to newNode
          head = newNode ;
          // point new node to head / new node
          newNode -> next = head ;
        }

        // if pos == 0
        if(pos == 0){
          node* temp = head ;

          // go to last node
          while(temp -> next != head){
            temp = temp -> next ;
          }

          // point new node to first node
          newNode -> next = head ;
          // point last node to new node
          temp -> next = newNode ;
          //point head to new node
          head = newNode ;
        }

        else{
          node* temp = head ;
          // go to last node or till the position - 1
          while(temp -> next != head && ( --pos > 1)){
            temp = temp -> next ;
          }
          // new node points to pos node
          newNode -> next = temp -> next ;
          // point pos - 1 node to new node
          temp -> next = newNode ;
        }
        
        return ;
      }

    void display(){
      node* temp = head ;
      cout<<"HEAD|"<<temp<<" ->";
      do{
        cout<<temp -> data <<"|"<<temp->next <<" -> ";
        temp = temp -> next ;
      }
      while(temp != head);
      cout<<"\n";
    }
};

int main(){
  CircularLinkedList cll ;
  cll.insertAtTail(1);
  cll.display();
  cll.insertAtBegin(2);
  cll.display();
  cll.insertAtBegin(3);
  cll.display();
  cll.insertAtBegin(4);
  cll.display();
  cll.insertAtTail(10);
  cll.display();
  cll.insertAtK(100 , 10);
  cll.display();
}
