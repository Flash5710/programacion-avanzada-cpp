// Diagnostico 3: Funciones
// El codigo de abajo calcula el area de dos rectangulos distintos,
// duplicando la misma logica dos veces.
//
// Objetivo: escribe una funcion area_rectangulo(base, altura) que reciba
// dos parametros y retorne el area, y reemplaza ambos bloques duplicados
// por una llamada a esa funcion.
//
// Salida esperada (no debe cambiar al refactorizar):
// Area 1: 20
// Area 2: 63
//
// Compilar:  g++ -std=c++20 -Wall -Wextra -g ejercicio3_funciones.cpp -o bin/ejercicio3
// Ejecutar:  ./bin/ejercicio3

#include <iostream>

// TODO: declara aqui tu funcion area_rectangulo(double base, double altura)
double area_rectangulo(double base, double altura){
    return base*altura;
}

int main() {
    // Bloque 1 (duplicado, a reemplazar por una llamada a tu funcion)
    double area1 = area_rectangulo(4.0,5.0);
    std::cout << "Area 1: " << area1 << std::endl;

    // Bloque 2 (misma logica, otros datos)
    double area2 = area_rectangulo(9.0,7.0);
    std::cout << "Area 2: " << area2 << std::endl;

    return 0;
}
