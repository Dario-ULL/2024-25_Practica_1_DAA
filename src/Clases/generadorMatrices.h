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

#pragma once

#include <vector>
#include <random>
#include <chrono>

class GeneradorMatrices {
 public:
  static std::vector<std::vector<int>> generar(int filas, int columnas) {
    std::vector<std::vector<int>> matriz(filas, std::vector<int>(columnas));
    std::random_device dispositivo;
    std::mt19937 generador(dispositivo());
    std::uniform_int_distribution<int> distribucion(1, 10);

    for (auto& fila : matriz) {
      for (auto& elemento : fila) {
        elemento = distribucion(generador);
      }
    }
    return matriz;
  }

  static int generarTamano(int minimo, int maximo) {
    std::random_device dispositivo;
    std::mt19937 generador(dispositivo());
    std::uniform_int_distribution<int> distribucion(minimo, maximo);
    return distribucion(generador);
  }
};