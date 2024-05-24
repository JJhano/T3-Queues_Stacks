#include <iostream>
#include <stack>
#include <queue>

using namespace std;
struct nodeList {
	int val;
	nodeList* next;
};
typedef struct nodeList nodo;

# define MAX 50

void intercalar_lista(nodo **L, stack<int> s, queue<int> q);
void appendToListL(nodo **l, int num);
void printList(nodo *l);

int main(int argc, char **argv){
	if(argc != 4){
		cout << "Debe ejecutarse como: ./stlstackqueue <n> <m> <seed>" << endl;
		exit(EXIT_FAILURE);
	}
	int n = atoi(argv[1]);
    int m = atoi(argv[2]);
	int seed = atoi(argv[3]);
	int i, random_number;
	srand(seed);
	vector<int> vs;
	stack<int> stack_s;
	queue<int> queue_q;
    nodo *L = NULL;
    

	
	cout << "Stack: " << endl;
	for ( i = 0; i < n; i++){
		random_number = rand()%MAX;
		stack_s.push(random_number);
		cout << random_number << " ";
	}
	cout << endl;
	cout << "Queue: " << endl;
	for ( i = 0; i < m; i++){
		random_number = rand()%MAX;
		queue_q.push(random_number);
		cout << random_number << " ";
	}
	cout << endl;
	intercalar_lista(&L,stack_s, queue_q);
	printList(L);
	return EXIT_SUCCESS;
}

void intercalar_lista(nodo **L, stack<int> s, queue<int> q){
    int proporcion = s.size() / q.size();
	cout << "Proporcion: " << proporcion << endl;
	while( !s.empty()){
		for (int i = 0; i < proporcion; i++){
			appendToListL(L,s.top());
			s.pop();
		}
		appendToListL(L,q.front());
		q.pop();
	}    
}

void appendToListL(nodo **l, int num){
	nodo *p=new nodo;
	p->val=num;
	p->next=*l;
	*l=p;
}

void printList(nodo *l){
	nodo *p = l;
	cout << "Lista :" << endl;
	while (p != nullptr){
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
}