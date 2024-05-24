#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char **argv){
    if(argc != 3){
        printf("Execute as ./main <n> <seed> \n");
        return EXIT_FAILURE;
    }
	int n = atoi(argv[1]);
	int seed = atoi(argv[2]);
	srand(seed);

	return EXIT_SUCCESS;
}

