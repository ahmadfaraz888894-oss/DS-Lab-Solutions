#include <iostream>
using namespace std;

class Node{
	public:
		int data;
		Node*next;
		Node*prev;
		
		Node(int patient_id){
			data=patient_id;
			next = prev = nullptr;
		}
};

class Doublylist{
	public:
	Node*head;
	Node*tail;
	
	Doublylist(){
		
			head = tail = nullptr;
	}
	~Doublylist(){
		while(head!=nullptr)
			deleteatbegining();
	}


void insertatbegining(int patient_id){
	Node* newnode = new Node( patient_id);
	
	if(head==nullptr){
		head=tail=newnode;
	}
	else{
		newnode->next=head;
		
		head->prev=newnode;
		head=newnode;
	}
}

void insertatend(int patient_id){
	Node*newnode=new Node(patient_id);
		
	if(head==nullptr){
		head=tail=newnode;
		return;
		
		
	}
	
	Node*temp = head;
	while(temp->next!=nullptr){
		temp = temp->next;
	}
	temp->next= newnode;
	newnode->prev=temp;
	tail=newnode;
	
	
	}
	
	/*if we want to insert node at end through tail we use this process*/
	
	/*tail->next=newnode;
	newnode->prev=tail;
	tail=newnode;*/
	
	

void deleteatbegining(){
	 if(head==nullptr){
	 	cout<<"ur list is empty:";
	 	return;
	 }
	 
	 
	 if(head==tail){
	 	head= tail= nullptr;
	 	delete head;
	 	return;
	 	
	 }
	 Node*temp=head;
	 head=head->next;
	 if(temp->next != nullptr)
	 temp->next->prev=nullptr;
	 delete temp;
	 
}

void insertatposition(int patient_id,int pos){
	Node*newnode=new Node(patient_id);
	//bounds
	//--
	if(pos<1){
		cout<<"invalid pos:"<<endl;
	}
	int count=0;
	Node* curr=head;
	while(curr!=nullptr){
		curr=curr->next;
		count++;
	}
	
	if(pos>count){
		cout<<"invalid position:"<<endl;
	}
	//--
	if(pos==1){
		insertatbegining(patient_id);
		return;
	}
	Node*temp=head;
	for(int i=1;i<pos-1;i++){
		temp=temp->next;
	}
	newnode->prev=temp;
	newnode->next=temp->next;
	if(temp->next != nullptr)
	temp->next->prev=newnode;
	temp->next=newnode;
			
}

void display(){
	Node*temp = head;
	cout << "NULL";
	while(temp!=nullptr){
		cout << " <- "<< temp->data << " -> ";
		temp = temp->next;
	}
	cout << "NULL";
}
};
	


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Doublylist list;
	list.insertatbegining(5);
	list.insertatbegining(6);
	list.insertatbegining(7);
	list.insertatbegining(8);
	list.display();
	cout<<endl;
	cout<<"------------------------------------------------------------------:"<<endl;
	cout<<"after the discharge of first patient:"<<endl;
	cout<<"------------------------------------------------------------------:"<<endl;
	list.deleteatbegining();
	list.display();
	cout<<endl;
	cout<<"-----------------------------------------------------------------:"<<endl;
	cout<<"after two more patients have arrived:"<<endl;
	cout<<"-----------------------------------------------------------------:"<<endl;
	list.insertatend(9);
	list.insertatend(10);
	list.display();
	cout<<endl;
	cout<<"-----------------------------------------------------------------:"<<endl;
	cout<<"after the entry of an emergency patient:"<<endl;
	cout<<"-----------------------------------------------------------------:"<<endl;
	list.insertatposition(4,3);
	
	list.display();
	cout<<endl;
	cout<<"------------------------------------------------------------------:"<<endl;
	cout<<"no more patients the hospital is closed plz come tommorow:"<<endl;
	cout<<"-------------------------------------------------------------------"<<endl;
	list.insertatposition(1,10);
	list.display();
	
	return 0;
	
}