#include <iostream>

using type_var = double;


/*!
     * Returns the result given by the calculation the area of a triangule;
     * \param base_triangulo The value of a triangule's base someone wants to calculate.
     * \param altura_triangulo The value of a triangule's height someone wants to calculate.
*/
type_var area_triangulo(type_var base_triangulo, type_var altura_triangulo){
    type_var resultado;
    resultado = (base_triangulo * altura_triangulo)/2;
    return resultado;
}


/*!
     * Returns the result given by the calculation the area of a quadrilateral shape;
     * \param base_quadrilatero The value of a quadrangle's base someone wants to calculate.
     * \param altura_quadrilatero The value of a quadrangle's height someone wants to calculate.
*/
type_var area_quadrilatero(type_var base_quadrilatero, type_var altura_quadrilatero){
    type_var resultado;
    resultado = base_quadrilatero * altura_quadrilatero;
    return resultado;
}


/*!
     * Returns the result given by the calculation the area of a circle;
     * \param raio The value of a circle's radius someone wants to calculate.
*/
type_var area_circulo(type_var raio){
    type_var resultado;
    resultado = 3.14 * (raio * raio);
    return resultado;
}