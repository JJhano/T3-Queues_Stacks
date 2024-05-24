#include <iostream>
#include <stack>
#include <queue>
#include <cstdlib>
#include <vector>

using namespace std;

int main(int argc, char **argv) {
    if (argc != 4) {
        cout << "Debe ejecutarse como: ./stlstackqueue2 <n> <k> <seed>" << endl;
        exit(EXIT_FAILURE);
    }
    
    int n = atoi(argv[1]);
    int k = atoi(argv[2]);
    int seed = atoi(argv[3]);
    
    srand(seed);
    stack<int> stack_s;
    queue<int> queue_q;

    cout << "Stack: " << endl;
    for (int i = 0; i < n; i++) {
        int random_number = rand() % (k + 1);
        stack_s.push(random_number);
        cout << random_number << " ";
    }
    cout << endl;
    cout << "Queue: " << endl;
    while (!stack_s.empty()) {
        int value = stack_s.top();
        stack_s.pop();
        if (value <= k / 2) {
            queue_q.push(value);
            cout << value << " ";
        }
    }
    cout << endl;
    while (!queue_q.empty()) {
        stack_s.push(queue_q.front());
        queue_q.pop();
    }
    
    cout << "Final Stack: " << endl;
    vector<int> final_values;
    while (!stack_s.empty()) {
        final_values.push_back(stack_s.top());
        stack_s.pop();
    }
    // Imprime los elementos en el orden original
    for (auto it = final_values.rbegin(); it != final_values.rend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    return EXIT_SUCCESS;
}
