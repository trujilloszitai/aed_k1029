#include <iostream>
using namespace std;

// Este modelo de parcial no me intereso mucho en particular porque no tiene nada de punteros asi que coso
struct Corte
{
    int horaInicial = 0;
    int horaFinal = 0;
    int idSubestacion = 0;
    int dia = 0;
    int mes = 0;
    int idLocalidad = 0;
};

struct Localidad
{
  int id = 0;
  char nombre[50+1] = "";
  int habitantes = 0;
};

int main() {
    return 0;
}

void emitirListado(Corte cortes[])
{
    // Los cortes deben estar ordenados por localidad y por mes
}

void ordenarCortes(Corte cortes[])
{

}
