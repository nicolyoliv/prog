#include "esfera_utils.h"
#include <stdio.h> 
#include <math.h> 

#define PI 3.14

/**
 * @brief Calcula o volume de uma esfera com raio R.
 * @param R O raio da esfera.
 * @return O volume da esfera.
 */
float calcula_volume (float R){

    float volume = 0.0;
   return volume = (4.0/3.0)*PI*(pow(R,3));

}

/**
 * @brief Calcula a área de superfície de uma esfera com raio R.
 * @param R O raio da esfera.
 * @return A área de superfície da esfera.
 */
float calcula_area (float R){

    float area= 0.0;
    return area = 4.0*PI*(pow(R,2));
}

