#include <iostream>
#include <cstring>
using namespace std;

struct Paciente
{
    int id;
    char nombre[50 + 1];
    char apellido[50 + 1];
    int edad;
    int diagnostico;
};

struct Medicamento
{
    char ean[13 + 1];
    char nombre[50 + 1];
    int dosis;
};

struct Prescripcion
{
    int id_paciente;
    char ean[13 + 1];
    int horas_frecuencia;
    int hora_inicio;
};

int main()
{
    int i = 0;
    FILE *f_pacientes = fopen("pacientes.bin", "wb");
    FILE *f_medicamentos = fopen("medicamentos.bin", "wb");
    FILE *f_prescripciones = fopen("prescripciones.bin", "wb");
    cout << "HOLA, ESTE ES UN SOFTWARE PARA LAS PRESCRIPCIONES DEL DÍA." << endl;


    FILE *f_pacientes = fopen("pacientes.bin", "rb");
    FILE *f_medicamentos = fopen("medicamentos.bin", "rb");
    FILE *f_prescripciones = fopen("prescripciones.bin", "rb");

    fclose(f_pacientes);
    fclose(f_medicamentos);
    fclose(f_prescripciones);
    return 0;
}

void prescripciones(Prescripcion prescripciones[], Paciente pacientes[], Medicamento medicamentos[], int len_pres, int len_paci, int len_medi)
{
    int i = 0;

    cout << "Prescripciones del día: " << endl;
    for (i; i < len_pres; i++)
    {
        Prescripcion pre = prescripciones[i];
        Paciente pac = pacientes[buscar_paciente(pacientes, len_paci, pre.id_paciente)];
        Medicamento med = medicamentos[buscar_medicamento(medicamentos, len_medi, pre.ean)];

        cout << "ID " << pre.id_paciente << endl;
        cout << "Nombre " << pac.nombre << endl;
        cout << "Apellido " << pac.apellido << endl;
        cout << "EAN " << med.ean << endl;
        cout << "Nombre genérico " << med.nombre << endl;
        cout << "Dosis " << med.dosis << endl;
        cout << "Hora de inicio " << pre.hora_inicio << endl;
    }
}

void listar_prescripciones(Prescripcion prescrips[], Paciente pacientes[], Medicamento medicamentos[], int len_pres, int len_paci, int len_medi)
{
    agrupar_prescripciones(prescrips, len_pres);

    prescripciones(prescrips, pacientes, medicamentos, len_pres, len_paci, len_medi);
}

void agrupar_prescripciones(Prescripcion v[], int N)
{
    int i, j;
    i = j = 0;
    Prescripcion aux;

    for (i; i < N-1; i++)
    {
        for (j; j < N-i-1; j++)
        {
            if (!compararPrescripcciones(v[j], v[j+1]))
            {
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
        }
    }
}

void leer_pacientes(Paciente v[], FILE *&f, bool asc, int &len)
{
    Paciente pac;
    int N = 0;
    while (fread(&pac, sizeof(Paciente), 1, f))
    {
        v[N] = pac;
        N++;
    }

    int i, j;
    Paciente aux;
    bool comparar;
    i = j = 1;
    len = N;

    for (i; i < N; i++)
    {
        for (j; j <= N - i; j++)
        {
            comparar = asc ? v[j - 1].id > v[j].id : v[j - 1].id < v[j].id;

            if (comparar)
            {
                aux = v[j - 1];
                v[j - 1] = v[j];
                v[j] = aux;
            }
        }
    }
}

void leer_medicamentos(Medicamento v[], FILE *&f, int &len)
{
    Medicamento med;
    int i = 0;
    while (fread(&med, sizeof(Medicamento), 1, f))
    {
        v[i] = med;
        i++;
    }

    len = i;
}

void leer_prescripciones(Prescripcion v[], FILE *&f, bool asc, int &len)
{
    Prescripcion pres;
    int N = 0;
    while (fread(&pres, sizeof(Prescripcion), 1, f))
    {
        v[N] = pres;
        N++;
    }

    int i, j;
    Prescripcion aux;
    bool comparar;
    i = j = 1;
    len = N;

    for (i; i < N; i++)
    {
        for (j; j < N - i; j++)
        {
            comparar = asc ? v[j - 1].id_paciente > v[j].id_paciente : v[j - 1].id_paciente < v[j].id_paciente;

            if (comparar)
            {
                aux = v[j - 1];
                v[j - 1] = v[j];
                v[j] = aux;
            }
        }
    }
}

int buscar_paciente(Paciente v[], int N, int id)
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

int buscar_medicamento(Medicamento v[], int N, char ean[])
{
    int i = 0;
    while (i < N && strcmp(ean, v[i].ean) != 0)
    {
        i++;
    }

    return i == N ? -1 : i;
}

int buscar_prescripcion(Prescripcion v[], int N, int id_paciente)
{
    int i = 0;
    while (i < N && v[i].id_paciente != id_paciente)
    {
        i++;
    }

    return i == N ? -1 : i;
}

bool compararPrescripcciones(Prescripcion &a, Prescripcion &b)
{
    if (a.id_paciente != b.id_paciente) return a.id_paciente < b.id_paciente;
    return a.hora_inicio < b.hora_inicio;
}