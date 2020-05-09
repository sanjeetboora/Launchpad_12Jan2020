#include<iostream>
using namespace std;

template<typename T>
class node
{
public:
	string key;
	T value;
	node<T>* next;
	node(string k, T val) {
		key = k;
		value = val;
		next = NULL;
	}

	//destructor
	~node() {
		if (next != NULL) {
			cout << "destructor called" << endl;
			delete next;
		}
	}
};

// 4 + T_bytes + 8 =>
// 4 + 1 + 8 => 13
// node<T>* a;
template<typename T>
class hashMap
{	node<T>** arr; // array to store address of nodes
	int totalSize;
	int currSize;

	int hashFunc(string str) {
		int idx = 0;
		int len = str.length();
		int multiplicationFactor = 1;

		for (int i = 0; i < len; ++i)
		{	//(a*b)%x => ((a%x)*(b%x))%x
			int result = ((str[len - i - 1]) % totalSize * (multiplicationFactor % totalSize)) % totalSize;
			idx = ((idx % totalSize) + (result % totalSize)) % totalSize;
			multiplicationFactor =  ((multiplicationFactor % totalSize) + (37 % totalSize)) % totalSize;

		}
		return idx;
	}

	void rehash() {
		cout << "rehashing" << endl;
		node<T>** oldArray = arr;
		int oldSize = totalSize;

		totalSize = 2 * totalSize;

		arr = new node<T>*[totalSize];//new array
		currSize = 0;
		for (int i = 0; i < totalSize; ++i)
		{
			arr[i] = NULL;
		}

		for (int i = 0; i < oldSize; ++i) //copy all elements of older array to newer one
		{
			if (oldArray[i] != NULL) {
				node<T>* temp = oldArray[i];
				while (temp != NULL) {
					insert(temp->key, temp->value);
					temp = temp->next;
				}
			}
		}

		//delete the old array
		for (int i = 0; i < oldSize; ++i)
		{
			delete oldArray[i];
		}
		delete[] oldArray;
	}



public:

	hashMap(int defaultSize = 7) {
		totalSize = defaultSize;
		currSize = 0;
		arr =  new node<T>*[totalSize];
		for (int i = 0; i < totalSize; ++i)
		{
			arr[i] = NULL;
		}
	}

	void insert(string k, T val) {
		int idx = hashFunc(k);

		node<T>* newNode = new node<T>(k, val);
		//attach new node at head
		newNode -> next = arr[idx];
		arr[idx] = newNode;
		currSize++;

		float loadFactor = (float)currSize / (float) totalSize;

		if (loadFactor > 0.75) {
			rehash();
		}

	}

	void print() {
		for (int i = 0; i < totalSize; ++i)
		{
			cout << i << " --> ";
			node<T>* temp = arr[i];
			while (temp != NULL) {
				cout << "(" << temp->key << ", " << temp->value << ") ";
				temp = temp->next;
			}
			cout << endl;
		}
	}

	T* search(string k) {
		int idx = hashFunc(k);

		node<T>* temp = arr[idx];

		while (temp != NULL) {
			if (temp->key == k) {
				return &(temp->value);
			}
			temp = temp->next;
		}
		return NULL;
	}

	T& operator[](string k) { //this will return value by refernce
		T* valueAdd = NULL; //address of value
		if (search(k) != NULL) { //if key already exists
			valueAdd = search(k);
		}
		else { // key doesn't exists
			T garbageValue;
			insert(k, garbageValue);
			valueAdd = search(k);
		}
		return *valueAdd; // return value
	}

};

// arr[10] = node_x;


int main(int argc, char const *argv[])
{
	hashMap<int> hp(11);

	hp.insert("abc", 10);
	hp.insert("1b2", 11);
	hp.insert("ahdc", 723);
	hp.insert("bks", 24);
	hp.insert("ojpw", 32);
	hp.insert("qieuw", 90);
	hp.print();
	hp.insert("ajskhsk", 78);
	hp.insert("akdhks", 256);
	hp.insert("hsdks", 56);

	hp.print();

	if (hp.search("ajskhsk") != NULL) {
		cout << "ajskhsk" << " found" << endl;
	}
	else {
		cout << "ajskhsk" << " not found" << endl;
	}

	if (hp.search("ajk") != NULL) {
		cout << "ajk" << " found" << endl;
	}
	else {
		cout << "ajk" << " not found" << endl;
	}

	hp["ajk"] = 800; // it should make a new entry for key "ajk" and store it's valuue as 800;
	hp["hsdks"] = 90; //it should replace older value 56 by 90



	hp.print();
	cout << hp["hsdks"] << endl;

	return 0;
}



