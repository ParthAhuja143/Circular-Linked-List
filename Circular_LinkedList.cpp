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

      void deleteAtBegin(){
        if(this -> head == NULL){
          return ;
        }

        node* temp = head ;
        while(temp -> next != head){
          temp = temp -> next ;
        }

        node* nodeToBeDeleted = temp -> next ;
        // point last node to second node
        temp -> next = head -> next ;
        // point head to second node
        head = head ->next ;
        delete nodeToBeDeleted;

        return ;
      }

      void deleteAtEnd(){
        if(head == NULL){
          return ;
        }

        node* temp = head ;
        while(temp -> next -> next!= head){
          temp = temp -> next ;
        }
        // delete last node
        delete temp -> next ;
        //point second last to head
        temp -> next = head ;
        return ;
      }

      void deleteAtK(int pos ){
        if(this -> head == NULL){
          return ;
        }
        // delete at begin
        if(pos == 0 ){
          node* temp = head ;
          while(temp -> next != head){
            temp = temp -> next ;
          }
          node* nodeToBeDeleted = temp -> next ;
          temp -> next = head -> next ;
          head = head -> next ;
          delete nodeToBeDeleted ;
          return ;
        }

        else{
          node* temp = head ;
          // go to previous node to the node to be deleted
          while((--pos > 1)){
            // if you get to the second last node delete last node(it means position is of last node or greater)
            if(temp -> next -> next == head){
              delete temp -> next ;
              temp -> next = head ;
              break;
            }
            else{
              temp = temp -> next ;
            }
          }
          // we will enter this condition only if position is in the list and not the last node
          if(pos >= 1){
           node* nodeToBeDeleted = temp -> next ;
           temp -> next = temp -> next -> next ;
           delete nodeToBeDeleted ;
         }
        }
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
  cll.deleteAtBegin();
  cll.display();
  cll.deleteAtEnd();
  cll.display();
  cll.deleteAtK(2);
  cll.display();
}
