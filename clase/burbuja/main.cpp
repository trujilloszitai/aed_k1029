#include <iostream>
#include <cstring>
using namespace std;

struct Book
{
    int id;
    char name[100 + 1];
};

void bubble_sort_by_id(Book v[], int N, bool asc)
{
    int i, j;
    Book aux;
    bool compare;
    for (i = 1; i < N; i++) // pasos
    {
        for (j = 1; j <= N - i; j++) // comparaciones
        {
            compare = asc ? v[j - 1].id > v[j].id : v[j - 1].id < v[j].id;

            if (compare) // condicion a cumplir para intercambio
            {                          // intercambio
                aux = v[j - 1];
                v[j - 1] = v[j];
                v[j] = aux;
            }
        }
    }
}

void bubble_sort_by_name(Book v[], int N, bool asc)
{
    int i, j;
    Book aux;
    bool compare;
    for (i = 1; i < N; i++) // pasos
    {
        for (j = 1; j <= N - i; j++) // comparaciones
        {
            compare = asc ? strcmp(v[j - 1].name, v[j].name) > 0 : strcmp(v[j - 1].name, v[j].name) < 0;

            if (compare) // condicion a cumplir para int.
            {            // intercambio
                aux = v[j - 1];
                v[j - 1] = v[j];
                v[j] = aux;
            }
        }
    }
}

int main()
{
    Book books[10] = {
        {7, "Jeffrey"},
        {10, "Ellen"},
        {8, "Ethel"},
        {5, "Mittie"},
        {9, "Mark"},
        {6, "Ronnie"},
        {2, "Clifford"},
        {4, "Jared"},
        {3, "Chester"},
        {1, "Louise"},
    };

    bubble_sort_by_id(books, 10, false);

    cout << "Por ID:" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << "Libro " << books[i].id << endl;
    }

    bubble_sort_by_name(books, 10, true);

    cout << "Por nombre:" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << "Libro " << books[i].name << endl;
    }

    return 0;
}