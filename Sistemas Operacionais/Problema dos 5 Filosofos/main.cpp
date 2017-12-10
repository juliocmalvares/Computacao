#include <iostream>
#include <cstdlib>
#include "hashi.h"
#include "filosofo.h"
#include "filosofo.cpp"
#include <thread>
#include <chrono>
#include "jantar.h"
using namespace std;

int main(){
    Jantar<int> jantar = Jantar<int>();
    thread threads[5];
    for(int i = 0; i < 5; i++){
        threads[i] = thread(&Jantar<int>::jantar, &jantar);
    }
    threads[0].join();
    threads[1].join();
    threads[2].join();
    threads[3].join();
    threads[4].join();


	return EXIT_SUCCESS;
}
