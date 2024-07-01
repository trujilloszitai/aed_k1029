#include <iostream>
#include <fstream>
using namespace std;

struct Alumno {
    char nombre[20+1];
    int id;
};

int main() {

    Alumno al;
    FILE* f=fopen("alumnos.bin","wb");
    
    return 0;
}