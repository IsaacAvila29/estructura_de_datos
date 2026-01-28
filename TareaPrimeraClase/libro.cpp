#include <string>

using namespace std;

class Libro {
private:
    string titulo;
    int paginas;
    bool disponible;

public:
    // Constructor por defecto
    Libro() {
        titulo = "";
        paginas = 0;
        disponible = true;
    }

    // Constructor alternativo
    Libro(string t, int p) {
        titulo = t;
        paginas = p;
        disponible = true;
    }

    // Cambia el estado de disponibilidad
    void prestar() {
        disponible = false;
    }

    // Regresa el número de páginas
    int obtenerPaginas() {
        return paginas;
    }
};
