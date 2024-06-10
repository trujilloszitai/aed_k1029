#include <iostream>
#include <cstring>
using namespace std;

struct Model
{
    char id[4 + 1];
    char description[20 + 1];
};

struct Seller
{
    int id;
    char name[20 + 1];
};

struct Sale
{
    char model_id[4 + 1];
    int seller_id;
    int date;
    char customer[20 + 1];
};

void bubble_sort_by_date(Sale[], int, bool);
Seller search_seller(Seller[], int, int);
Model search_model(Model[], char[], int);

int main()
{
    Model models[15] = {
        {"lgvC", "may popular"},
        {"UxTt", "occur strip port "},
        {"Yesq", "nest badly father "},
        {"BRoX", "swept primitive"},
        {"oWiI", "game plane amount "},
        {"Rkgb", "egg fall birthday "},
        {"gAYm", "aloud jack house "},
        {"u528", "manufacturing"},
        {"j8tI", "hollow mile receive "},
        {"dcHR", "organized law herd "},
        {"AW9e", "bad lonely spin "},
        {"ZLV0", "show feature"},
        {"yskd", "appearance dress"},
        {"Ef5s", "spent model trouble "},
        {"YwZm", "test suit memory "},
    };

    Seller sellers[10] = {
        {8, "Walter Mason"},
        {1, "Calvin Larson"},
        {5, "Mark Hamilton"},
        {6, "Catherine Hardy"},
        {2, "Teresa Saunders"},
        {4, "Lora Stanley"},
        {3, "Billy Yates"},
        {7, "Iva White"},
        {10, "Claudia Ramsey"},
        {9, "Luis Cook"},
    };

    Sale sales[100] = {
        {"Yesq", 7, 125, "George"},
        {"j8tI", 10, 802, "Valdez"},
        {"UxTt", 4, 714, "McGuire"},
        {"dcHR", 8, 603, "Alexander"},
        {"oWiI", 6, 717, "Carlson"},
        {"u528", 2, 414, "Hawkins"},
        {"BRoX", 5, 629, "Montgomery"},
        {"lgvC", 3, 623, "Padilla"},
        {"gAYm", 9, 825, "Floyd"},
        {"Rkgb", 1, 1224, "Warren"},
    };

    bubble_sort_by_date(sales, 10, true);

    cout << "Ventas ordenadas por fecha: " << endl;
    for (int i = 0; i < 10; i++)
    {
        Seller s = search_seller(sellers, sales[i].seller_id, 10);
        Model m = search_model(models, sales[i].model_id, 15);

        cout << "Fecha " << sales[i].date << " - " << "Cliente " << sales[i].customer << " - " << "Vendedor " << s.name << " - " << "Modelo " << m.description << endl;
    }

    return 0;
}

void bubble_sort_by_date(Sale v[], int N, bool asc)
{
    int i, j;
    Sale aux;
    bool compare;
    for (i = 1; i < N; i++) // pasos
    {
        for (j = 1; j <= N - i; j++) // comparaciones
        {
            compare = asc ? v[j - 1].date > v[j].date : v[j - 1].date < v[j].date;

            if (compare) // condicion a cumplir para int.
            {            // intercambio
                aux = v[j - 1];
                v[j - 1] = v[j];
                v[j] = aux;
            }
        }
    }
}

Seller search_seller(Seller v[], int id, int N)
{
    int i = 0;
    Seller seller = {0, ""};
    bool notFound = true;

    while (notFound && i < N)
    {
        if (v[i].id == id)
        {
            seller = v[i];
            notFound = false;
        }
        i++;
    }

    return seller;
}

Model search_model(Model v[], char id[], int N)
{
    int i = 0;
    Model model = {"", ""};
    bool notFound = true;

    while (notFound && i < N)
    {
        if (strcmp(v[i].id, id) == 0)
        {
            model = v[i];
            notFound = false;
        }
        i++;
    }

    return model;
}