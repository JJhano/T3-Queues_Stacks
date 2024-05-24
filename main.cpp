#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main(int argc, char **argv){
	if(argc != 4){
		cout << "Debe ejecutarse como: ./main <n> <m> <seed>" << endl;
		exit(EXIT_FAILURE);
	}
	int n = atoi(argv[1]);
    int m = atoi(argv[2]);
	int seed = atoi(argv[3]);
	// int i, random_number;
	srand(seed);

	return EXIT_SUCCESS;
}

