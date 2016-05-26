
//singly linked list
template <typename T>
class DList{
	struct Node{
		T data_;
		Node* next_;
		Node* prev_;
		Node(const T& data, Node* prev=nullptr, Node* next=nullptr){
			data_=data;
			next_=next;
			prev_=prev;
		}
	};
	Node* first_;
	Node* last_;
public:
	class iterator{
		friend class DList;
		Node* curr_;
		DList* myList_;
		iterator(Node* curr,DList* myList){
			curr_=curr;
			myList_=myList;
		}
	public:
		iterator(){
			curr_=nullptr;
			myList_=nullptr;
		}
		T& operator*(){
			return curr_->data_;
		}
		const T& operator*() const{
			return curr_->data_;
		}
		iterator operator++(){
			//++x
			if(curr_){
				curr_=curr_->next_;
			}
			return *this;
		}
		iterator operator++(int){
			//x++
			iterator old=*this;
			if(curr_){
				curr_=curr_->next_;
			}
			return old;
		}
		iterator operator--(){
			//--x
			if(curr_){
				curr_=curr_->prev_;
			}
			return *this;
		}
		iterator operator--(int){
			//--x
			iterator old=*this;
			if(curr_){
				curr_=curr_->prev_;
			}
			return old;
		}
		bool operator==(const iterator& other){
			return other.curr_==curr_;
		}
		bool operator!=(const iterator& other){
			return other.curr_!=curr_;
		}
	};
	//creates empty linked list
	DList(){
		first_=last_=nullptr;
	}
	//insert node at front of list and return iterator
	//to that node
	//O(1)
	iterator insertFront(const T& data){
		Node* nn=new Node(data,nullptr,first_);
		if(first_==nullptr){
			last_=nn;
		}
		else{
			first_->prev_=nn;
		}
		first_=nn;

		iterator rc(nn,this);
		return rc;
	}
	//inserts a node to end of list
	//and returns iterator to newly added node
	//O(1)
	iterator insertBack(const T& data){
		Node* nn=new Node(data,last_,nullptr);
		if(last_==nullptr){
			//empty list
			first_=nn;
		}
		else{
			last_->next_=nn;
	
		}
		last_=nn;
		iterator rc(nn,this);
		return rc;
	}

	//inserts a node after the node it refers to
	//and returns iterator to newly added node
	//O(1)
	iterator insert(iterator& it, const T& data){
		iterator rc;
		if(it.myList_ == this && it!=end()){
			Node* curr=it.curr_;
			Node* next=curr->next_;
			Node* nn=new Node(data,curr,curr->next_);
			curr->next_=nn;
			if(curr==last_){
				last_=nn;
			}
			else{
				next->prev_=nn;
			}
			rc=iterator(nn,this);
		}
		return rc;

	}

	//O(1)
	void removeFront(){

	}
	//O(n)
	void remove(iterator& it){

	}

	//O(n)
	void removeBack(){


	}
	iterator begin(){return iterator(first_,this);}
	iterator end(){return iterator(nullptr,this);}
};