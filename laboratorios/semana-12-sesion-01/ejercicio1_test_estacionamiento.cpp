#include <gtest/gtest.h>

#include "estacionamiento.h"

// Pruebas del estacionamiento de la Semana 11. Cada TEST es una prueba
// independiente: crea su propio estacionamiento, hace algo y verifica el
// resultado. El primero ya esta escrito como modelo.
//
// Compilar:  g++ -std=c++20 -Wall -Wextra -g ejercicio1_test_estacionamiento.cpp -lgtest_main -lgtest -pthread -o bin/test_estacionamiento
// Ejecutar:  ./bin/test_estacionamiento

TEST(Estacionamiento, PrimeraPlacaRecibePuestoCero) {
    Estacionamiento estacionamiento(3);

    std::optional<int> puesto = estacionamiento.asignarPuesto(4521);

    ASSERT_TRUE(puesto.has_value());
    EXPECT_EQ(*puesto, 0);
}

TEST(Estacionamiento, LlenoDevuelveVacio){

    Estacionamiento estacionamiento(3);

    estacionamiento.asignarPuesto(123);
    estacionamiento.asignarPuesto(456);
    estacionamiento.asignarPuesto(789);

    std::optional<int> cuarto_estacionamiento=estacionamiento.asignarPuesto(369);

    EXPECT_FALSE(cuarto_estacionamiento.has_value());

}

TEST(Estacionamiento, PlacaRepetida){

    Estacionamiento estacionamiento (3);

    estacionamiento.asignarPuesto(123);
    
    EXPECT_THROW(estacionamiento.asignarPuesto(123), std::invalid_argument);
}

TEST(Estacionamiento, PuestoLiberadoSeRehusa){
    Estacionamiento estacionamiento (3);

    estacionamiento.asignarPuesto(123);
    estacionamiento.asignarPuesto(456);
    estacionamiento.asignarPuesto(789);

    estacionamiento.liberar(456);

    std::optional<int> nuevo_espacio=estacionamiento.asignarPuesto(987);

    ASSERT_TRUE(nuevo_espacio.has_value());
    EXPECT_EQ(*nuevo_espacio, 1);
}
// TODO 1: prueba LlenoDevuelveVacio. Con 3 puestos, asigna tres placas
// distintas; la cuarta tiene que recibir un optional vacio
// (EXPECT_FALSE sobre has_value()).

// TODO 2: prueba PlacaRepetidaLanza. Asigna la placa 7788 y verifica que
// asignarla otra vez lanza std::invalid_argument (EXPECT_THROW).

// TODO 3: prueba PuestoLiberadoSeReusa. Llena los 3 puestos, libera la
// placa del puesto 1 y verifica que la siguiente placa recibe el puesto 1.
