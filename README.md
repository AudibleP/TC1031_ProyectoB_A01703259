# GPS Mapa de Among Us
***Bastante sus que esto exista...*** 

Este proyecto encuentra la ruta mas corta en el mapa de among us ***SKELD*** y te dice los tiempos de distancia entre cada una de las estaciones.

<div>
<p style = 'text-align:center;'>
<img src="https://static1-es.millenium.gg/articles/5/27/32/5/@/125848-fuente-mooseknuckle-king-en-reddit-full-1.jpg" alt="JuveYell" width="900px">
</p>
</div>

# Avance 1 (Competencias).
Este avance crea el gps unicamente para el mapa Skeld.

## SICT0301B: Evalúa los componentes
### Presenta Casos de Prueba correctos y completos para todas las funciones y procedimientos del programa
Leer archivo llamado casos.txt

## SICT0302B: Toma decisiones 
### Usa grafos para hacer analisis de información
Despues de cargar el archivo si se elige la opcion tos del menu, el programa te podra hacer un analisis de los datos dentro del grafo.
### Usa un algoritmo de búsqueda en grafos adecuado para resolver un problema
El algoritmo de grafos usado logra encontrar el mejor camino dependiendo de los segundos marcados en la opcion dos.

## SICT0303B: Implementa acciones científicas
### Implementa mecanismos para consultar información de las estructras correctos
Se le el archivo amogus de manera correcta con ifstreams y se analiza los datos.

# Avance 3 (Competencias)
Estructura extra

## SEG0702A: Tecnologías de Vanguardia
### Investiga e implementa un algoritmo o una estructura de datos que no se vió durante el curso.
La estructura investigada en este caso se puede encontrar en graph.h ya que aqui se uso ***unordered_map*** el cual es una estructura parecida a hashes, pero no fue vista en clase.

### Describe cada algoritmo de la estructura (inserción, consulta, etc...) de forma clara y con ejemplos

### TL,DR (too long, didnt read): 
Los unordered_map varian de los hashes ya que usan una implementacion parecida a estos, la diferencia es que la estructura del unordered_map al 
hash, es que el umap no tiene ningun porblema al crecer su estructura, ya que esta no ordena y tiene sus valores guardados en buckets de manera aleatoria, sus tres principales 
funciones siendo search, insertion y detele, de las cuales las 3 tienen en su peor de los casos o(n), pero es su mayoria de aplicaciones es o(1).

<div>
<p style = 'text-align:center;'>
<img src="https://miro.medium.com/max/2400/1*-BjbJwNd34nP6OYk2TbCdw.png" alt="JuveYell" width="900px">
</p>
</div>

Los unordered_map son contenedores que almacenaran elementos por una combinacion de datos, esta combinacion esta formada por un key-value y un valor mapeado. El key-value ayuda 
a encontrar en el mapa el valor mapeado. Estos dos valores puedes ser de cualquier tipo y definido por el usuario o valores predefinidos.
Unordered_maps son implementados en base a Hashes (Por esto se considera una estructura de datos extra), donde el key-value se convierte en un indice de una tabla hash.
Unordered_maps tiene 3 funciones principales, las cuales son busqueda, insercion y eliminacion. Estas en el peor de los casos es de O(n).

### Estos son los metodos mas usados de unordered_maps: (retrieved from: https://www.mygreatlearning.com/blog/unordered_map-in-cpp/)


find() Return iterator to the element (public member function), en el peor de los casos es o(n).

insert() Insert elements (public member function ), en el peor de los casos es o(n).

erase() Erase elements (public member function ), en el peor de los casos es o(n).




### Un ejemplo basico de unordered_map seria:

#include <iostream>
#include <unordered_map>
using namespace std;
    
int main()
{
    
    unordered_map<string, int> umap;
    
    umap["GeeksforGeeks"] = 10;
    umap["Practice"] = 20;
    umap["Contribute"] = 30;
    
    for (auto x : umap)
      cout << x.first << " " << x.second << endl;
    
}

Aqui se puede ver como la variable umap fue inicializada es para el valor key es un string y para el valor mapeado es un int, despes en el for se usara auto para que x puede 
recibir cualquier tipo de dato y se usara .first y .second para declarar donde van los strings y donde van los ints
