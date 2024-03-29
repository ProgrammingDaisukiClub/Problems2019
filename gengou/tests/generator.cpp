#include <fstream>
#include <string>
#include "testlib.h"
#include "constraints.h"

using namespace std;

void generate (const string &file_name, int MIN_T, int MAX_T) {
    ofstream ofs(file_name);
    int T = rnd.next(MIN_T, MAX_T);
    ofs << T << endl;
    --T;
    for (int i = 0; i < T/2; i++) {
        int Y = rnd.next(MIN_Y, MAX_Y);
        int M = rnd.next(MIN_M, MAX_M);
        int D = rnd.next(MIN_D, MAX_D);
        ofs << Y << " " << M << " " << D << endl;
    }
    int Y = rnd.next(MIN_Y, MAX_Y);
    ofs << Y << " 12 1" << endl;
    for (int i = 0; i < T-T/2; i++) {
        int Y = rnd.next(MIN_Y, MAX_Y);
        int M = rnd.next(MIN_M, MAX_M);
        int D = rnd.next(MIN_D, MAX_D);
        ofs << Y << " " << M << " " << D << endl;
    }
    ofs.close();
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    generate("small.in", SMALL_MAX_T, SMALL_MAX_T);
    generate("large.in", LARGE_MAX_T, LARGE_MAX_T);
    for(int i=0;i<10;++i){
        generate("random_test"+to_string(i)+".in", LARGE_MIN_T, LARGE_MAX_T);
    }
    return 0;
}