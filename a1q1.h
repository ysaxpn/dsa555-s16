
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
		}
	public:
		iterator(){
		}
		T& operator*(){
		}
		const T& operator*() const{
		}
		iterator operator++(){
		}
		iterator operator++(int){
		}
		iterator operator--(){
		}
		iterator operator--(int){
		}
		bool operator==(const iterator& other){
		}
		bool operator!=(const iterator& other){

		}
	};
	//creates empty linked list
	DList();

	//destructor
	~DList();

	//copy constructor
	DList(const DList& other);

	//move constructor
	DList(DList&& other);

	//assignment operator
	const DList& operator=(const DList& other);

	//move operator
	const DList& operator=(DList&& other);

	//insert node at front of list and return iterator
	//to that node
	//O(1)
	iterator insertFront(const T& data);
	//inserts a node to end of list
	//and returns iterator to newly added node
	//O(1)
	iterator insertBack(const T& data);

	//inserts a node before the node it refers to
	//and returns iterator to newly added node
	//O(1)
	iterator insertBefore(iterator it, const T& data);

	//inserts a node after the node it refers to
	//and returns iterator to newly added node
	//O(1)
	iterator insertAfter(iterator it, const T& data);

	//removes the node referred to by it and returns 
	//the node after the removed node.
	iterator erase(iterator it);

	//removes all nodes between from and to.  This includes
	//the node referred to by from but NOT the one referred to by 
	//to.  Function returns iterator to the node referred to by to
	iterator erase(iterator from, iterator to);

	iterator begin(){return iterator(first_,this);}
	iterator end(){return iterator(nullptr,this);}
};
