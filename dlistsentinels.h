
//singly linked list
template <typename T>
class DList{
	struct Node{
		T data_;
		Node* next_;
		Node* prev_;
		Node(const T& data=T{}, Node* prev=nullptr, Node* next=nullptr){
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
		first_=new Node();
		last_=new Node();
		first_->next_=last_;
		last_->prev_=first_;
	}
	//insert node at front of list and return iterator
	//to that node
	//O(1)
	iterator insertFront(const T& data){
		Node* firstData=begin().curr_;
		Node* nn=new Node(data,first_,firstData);
		firstData->prev_=nn;
		first->next_=nn;


		iterator rc(nn,this);
		return rc;
	}
	//inserts a node to end of list
	//and returns iterator to newly added node
	//O(1)
	iterator insertBack(const T& data){		

	}

	//inserts a node after the node it refers to
	//and returns iterator to newly added node
	//O(1)
	iterator insert(iterator& it, const T& data){


	}

	//O(1)
	void removeFront(){
		//begin() == end() means empty list
		if(begin() != end()){
			Node* rm=begin().curr_;
			Node* next=rm->next_;
			first_->next_=next;
			next->prev_=first_;
			delete rm;

		}

	}
	//O(n)
	void remove(iterator& it){
	}

	//O(n)
	void removeBack(){


	}
	iterator begin(){return iterator(first_->next_,this);}
	iterator end(){return iterator(last_,this);}
};