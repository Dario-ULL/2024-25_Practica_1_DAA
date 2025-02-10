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

#include "estrategiaMultiplicacion.h"

class MultiplicacionPorFilas : public EstrategiaMultiplicacion {
 public:
  std::vector<std::vector<int>> multiplicar(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B) override {
    int filas = A.size();
    int columnas = B[0].size();
    int intermedio = B.size();
    std::vector<std::vector<int>> resultado(filas, std::vector<int>(columnas, 0));

    for (int i = 0; i < filas; ++i) {
      for (int j = 0; j < columnas; ++j) {
        for (int k = 0; k < intermedio; ++k) {
          resultado[i][j] += A[i][k] * B[k][j];
        }
      }
    }
    return resultado;
  }
};