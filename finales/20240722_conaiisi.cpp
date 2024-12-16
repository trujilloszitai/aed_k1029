#include <iostream>
#include <cstring>
using namespace std;

struct Trabajo {
    char titulo[50+1];
    int categoria;
    char correoResp[50+1];
    int idEvaluadores[3];
    int resultado[3];
};

struct Dictamen {
    int aspFormales;
    int cyt;
    int autores;
    bool rechazado;
};

void presentacionTrabajos() {

};

void insertarTrabajo(Trabajo trabajo) {

}