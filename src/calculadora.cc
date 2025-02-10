/**
 * Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Diseño y Analisis de Complejidad
 * 
 * @author  Dario Dominguez Gonzalez
 * @date    11/02/2024
 * @brief   Implementar dos algoritmos de productos de matrizes utilizandos
 *          los principios SOLID y el patron de Estategia.
 *          
*/

#include <iostream>
#include <vector>
#include <chrono>
#include <random>

#include "Clases/estrategiaMultiplicacion.h"
#include "Clases/estrategiaMultiplicacionColumnas.h"
#include "Clases/estrategiaMultiplicacionFilas.h"
#include "Clases/generadorMatrices.h"
#include "Clases/contextoMultiplicacion.h"

// Función para medir el tiempo de ejecución de una operación de multiplicación de matrices
//
// Parámetros:
// - contexto: Contexto que contiene la estrategia de multiplicación a utilizar (por ejemplo, por filas o por columnas).
// - A: La primera matriz (de tamaño filas x intermedio).
// - B: La segunda matriz (de tamaño intermedio x columnas).
// - metodo: El nombre del método de multiplicación (por ejemplo, "Recorrido por filas" o "Recorrido por columnas") que se utiliza
//           para mostrar en la salida el tiempo de ejecución correspondiente.
//
// La función mide el tiempo transcurrido en milisegundos y lo imprime en consola.
void medirTiempoEjecucion(ContextoMultiplicacion& contexto, const std::vector<std::vector<int>>& A, 
                          const std::vector<std::vector<int>>& B, const std::string& metodo) {
    auto inicio = std::chrono::high_resolution_clock::now();
    std::vector<std::vector<int>> resultado = contexto.multiplicar(A, B);
    auto fin = std::chrono::high_resolution_clock::now();
    
    std::chrono::duration<double, std::milli> duracion = fin - inicio;
    std::cout << "Tiempo de ejecución (" << metodo << "): " << duracion.count() << " ms\n";
}

int main() {
    int minimo = 100, maximo = 1000;

    int filas = GeneradorMatrices::generarTamano(minimo, maximo);
    int columnas = GeneradorMatrices::generarTamano(minimo, maximo);
    int intermedio = GeneradorMatrices::generarTamano(minimo, maximo);

    std::cout << "Tamaño generado: " << filas << "x" << intermedio << " * " << intermedio << "x" << columnas << "\n";

    std::vector<std::vector<int>> A = GeneradorMatrices::generar(filas, intermedio);
    std::vector<std::vector<int>> B = GeneradorMatrices::generar(intermedio, columnas);

    MultiplicacionPorFilas estrategiaFilas;
    MultiplicacionPorColumnas estrategiaColumnas;

    ContextoMultiplicacion contexto(&estrategiaFilas);
    medirTiempoEjecucion(contexto, A, B, "Recorrido por filas");

    contexto.establecerEstrategia(&estrategiaColumnas);
    medirTiempoEjecucion(contexto, A, B, "Recorrido por columnas");

    return 0;
}
