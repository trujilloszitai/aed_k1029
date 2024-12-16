#include <iostream>
using namespace std;

struct Usuario {
	int idUsuario;
	char nombreUsuario[250 + 1];
	char mail[100 + 1];
};

struct InfoVisualizacion {
	int idPelicula = 0;
	char nombrePelicula[100 + 1] = "";
	int idUsuario = 0;
};

struct infoLP
{
    int idPelicula;
    char nombrePelicula[100+1];
};

struct nodoLP
{
    infoLP info;
    nodoLP* sgte;
};

struct infoLU
{
    int idUsuario = 0;
    char nombreUsuario[250+1] = "";
    int peliculasVistas = 0;
    nodoLP* listaPeliculas;
};

struct nodoLU
{
    infoLU info;
    nodoLU* sgte;
};

nodoLU obtenerListaUsuarios(FILE *&);
void cargarPelicula(nodoLU *&, InfoVisualizacion);
bool tienenGustosSimilares(nodoLU *&, nodoLU*&);

int main() {
    return 0;
}

int cantReg(FILE*& f)
{
	//preservar la posicion actual
	int posActual=ftell(f);
	fseek(f,0,SEEK_END);
	int desplaz=ftell(f);
	int cantidad=desplaz/sizeof(Usuario);
	//vuelvo el puntero a donde estaba
	fseek(f,posActual,SEEK_SET);
	return cantidad;
}

int buscar_usuario(nodoLU *&, int N, int id)
{
    int izq = 0;
    int der = N - 1;
    while (izq <= der)
    {
        int medio = (izq + der) / 2;
        int valor = v[medio].id;
        if (valor == id)
        {
            return medio;
        }
        else if (valor < id)
        {
            izq = medio + 1;
        }
        else
        {
            der = medio - 1;
        }
    }

    return -1;
}
