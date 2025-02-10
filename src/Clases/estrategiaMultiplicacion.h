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

class EstrategiaMultiplicacion {
 public:
  virtual std::vector<std::vector<int>> multiplicar(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B) = 0;
  virtual ~EstrategiaMultiplicacion() = default;
};
