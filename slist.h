
//singly linked list
template <typename T>
class SList{
	struct Node{
		T data_;
		Node* next_;
		Node(const T& data, Node* next=nullptr){
			data_=data;
			next_=next;
		}
	};
	Node* first_;
	Node* last_;
public:
	class iterator{
		friend class SList;
		Node* curr_;
		SList* myList_;
		iterator(Node* curr,SList* myList){
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
		bool operator==(const iterator& other){
			return other.curr_==curr_;
		}
		bool operator!=(const iterator& other){
			return other.curr_!=curr_;
		}
	};
	//creates empty linked list
	SList(){
		first_=last_=nullptr;
	}
	//insert node at front of list and return iterator
	//to that node
	iterator insertFront(const T& data){
		Node* nn=new Node(data,first_);
		first_=nn;
		if(first_->next_==nullptr){
			last_=nn;
		}
		iterator rc(nn,this);
		return rc;
	}

	//inserts a node after the node it refers to
	//and returns iterator to newly added node
	iterator insert(iterator& it, const T& data){}
	//inserts a node to end of list
	//and returns iterator to newly added node
	iterator insertBack(const T& data){}

	void removeFront(){}
	void remove(iterator& it){}
	void removeBack(){}
	iterator begin(){return iterator(first_,this);}
	iterator end(){return iterator(nullptr,this);}
};