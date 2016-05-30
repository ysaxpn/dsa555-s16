
//singly linked list
template <typename T>
class SortedList{
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
		friend class SortedList;
		Node* curr_;
		SortedList* myList_;
		iterator(Node* curr,SortedList* myList){
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
	SortedList();

	//destructor
	~SortedList();

	//copy constructor
	SortedList(const SortedList& other);

	//move constructor
	SortedList(const SortedList&& other);

	//assignment operator
	const SortedList& operator=(const SortedList& other);

	//move operator
	const SortedList& operator=(const SortedList&& other);

	//data into the list
	iterator insert(const T& data);

	//returns iterator to node containing same value as data
	iterator find(const T& data);

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