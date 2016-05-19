
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
		T& operator*(){}
		const T& operator*() const{}
		iterator operator++(){}
		iterator operator++(int){}
		bool operator==(const iterator& other){}
		bool operator!=(const iterator& other){}
	};
	//creates empty linked list
	SList(){}
	//insert node at front of list and return iterator
	//to that node
	iterator insertFront(const T& data){}

	//inserts a node after the node it refers to
	//and returns iterator to newly added node
	iterator insert(iterator& it, const T& data){}
	//inserts a node to end of list
	//and returns iterator to newly added node
	iterator insertBack(const T& data){}

	void removeFront(){}
	void remove(iterator& it){}
	void removeBack(){}
	iterator begin(){}
	iterator end(){}
};