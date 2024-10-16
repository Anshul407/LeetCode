class Node{
    public:
    int val;
    Node*next;
    Node(int val){
        this->val=val;
        next=nullptr;
    }
};
class MyLinkedList {
public:
   
    Node*head;
    Node*tail;
    
    MyLinkedList() {
       
        head=nullptr;
        tail=nullptr;
    }
    
    int get(int index) {
        if(index<0)return -1;
        int i=0;
        Node*temp=head;
        while(temp&&i<index){
            temp=temp->next;
            i++;
        }
        return temp?temp->val:-1;
    }
    
    void addAtHead(int val) {
        Node*temp=new Node(val);
        if(!head){head=tail=temp;}
        else {
            temp->next=head;
            head=temp;
        }
    
    }
    
    void addAtTail(int val) {
        Node*temp=new Node(val);
        if(!tail){tail=head=temp;}
        else{
        tail->next=temp;
        tail=tail->next;
        }
    }
    
    void addAtIndex(int index, int val) {
        if(index==0){
            addAtHead(val);
            return ;
        }
        int i=1;
        Node*temp=head;
        while(temp&&i<index){
            temp=temp->next;
            i++;
        }
        if(!temp)return;
        Node*newnode=new Node(val);
        newnode->next=temp->next;
        temp->next=newnode;
        if(!newnode->next)tail=newnode;
    }
    
    void deleteAtIndex(int index) {
        if(!head)return;
        if(index==0){
            Node*t=head;
            head=head->next;
            if(!head)tail=nullptr;
            delete t;
            return ;
        }
        int i=1;
        Node*temp=head;
        while(temp&&i<index){
            
            temp=temp->next;
            i++;
            
        }
        if(!temp||!temp->next)return;
        
       Node*t=temp->next;
        temp->next=temp->next->next;
        if(!temp->next)tail=temp;
        delete t;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */