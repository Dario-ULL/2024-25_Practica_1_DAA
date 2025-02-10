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

class ContextoMultiplicacion {
 private:
  EstrategiaMultiplicacion* estrategia;
 public:
  explicit ContextoMultiplicacion(EstrategiaMultiplicacion* nueva_estrategia) : estrategia(nueva_estrategia) {}

  void establecerEstrategia(EstrategiaMultiplicacion* nueva_estrategia) {
    estrategia = nueva_estrategia;
  }

  std::vector<std::vector<int>> multiplicar(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B) {
    return estrategia->multiplicar(A, B);
  }
};