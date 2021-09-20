http://www.scymed.com/es/smnxpn/pnfdd219.htm
# Aplicación de la ecuación de Harris-Benedict para el cálculo de consumo calórico diario individual
El proyecto toma como base el contenido teórico de: 

"Juan Antonio Pascual. (2018, August 11). Con esta fórmula sabrás cuántas calorías debes comer al día para adelgazar. Retrieved September 20, 2021, from ComputerHoy website: https://computerhoy.com/noticias/life/esta-formula-te-dice-cuantas-calorias-debes-comer-dia-adelgazar-286837" 
Asimismo, toma la aplicación práctica ofrecida por:

"Harris Benedict Ecuación :: MediCalculator ::: ScyMed ::: (2021). Retrieved September 20, 2021, from Scymed.com website: http://www.scymed.com/es/smnxpn/pnfdd219.htm"

Esto con la finalidad de crear, por medio del csv anexado y la información brindada por el paciente, un conocimiento de la Tasa Metabólica Basal del individuo la cuál equivale al consumo de la persona en reposo. Por lo tanto, generar un contraste con el ejercicio ejecutado, puede otorgar una visualización del contenido calórico que la persona requiere ingresar a su cuerpo de manera diaria con el objetivo de tener una alimentación correctamente balanceada. La meta de este proyecto es servir como herramienta nutricional para mantener una base de datos moldeable y legible de los diferentes pacientes que deseen conocer este fundamental dato para la salud humana. 

## SICT0302B: Toma decisiones 

### Selecciona y usa una estructura lineal adecuada al problema

Uso una lista doblemente encadenada para regristrar las medicinas porque quiero acceder rápidamente a la registrada más recientemente (head), 
pero también necesito consultar cuál fue la primera que se agrego (tail), cada medicina es un objeto que contiene (...   ) 
los elementos se pueden insertar y eliminar usando la lista como se muestra en el código en las funciones 
agrega medicina, elimina medicina, y obten gramaje, que se encuentran en el archivo medicinas.h en las líneas 55, 80 y 124 respectivamente.


### Selecciona un algoritmo de ordenamiento adecuado al problema

Para este problema utilice un algoritmo de tipo merge sort, para poder organizar las medicinas por orden alfabético ascendente y despues descendente
use merge sort porque es rápido en la mayoría de los casos y porque es poco probable que me encuentre son su peor caso, ya que las lista inicial siempre está desordenada.
Las fuciones donde se puede ver es en ordena medicinas ascendente y ordena medicina descendente en el archivo reportes.h las líneas 50 y 78.

### Usa un árbol adecuado para resolver un problema

Usé un BST para ordenar las medicinas por su gramaje y poder encontrar rápidamente medicinas con gramaje similar.
Usé un BST porque mi lista incial viene desordenada, por lo que es poco probable que el BST se degenere. 

Las funciones donde lo uso es en obten medicina por gramaje  y  medicinas con mismo gramaje que se encuentran en reportes.h en 
las líneas 100 y 130

## SICT0301B: Evalúa los componentes

### Presenta Casos de Prueba correctos y completos para todas las funciones y procedimientos del programa,

los casos de pruebas para todas las funciones se encuentran pruebas.cpp donde se prueban las funciones de: 

la lista doblemente ligada de medicinas

el ordenamiento sobre la lista ligada de medicinas

el acceso al BST por gramaje

### Hace un análisis de complejidad correcto y completo para todo el programa y sus compenetes,

#### lista de medicinas

función de acceso por valor: O(n) por que para llegar a la medicina tengor que recorrer la listay comparar cada valor.

funcion de inserción: O(1) siempre uso insert first.

función de borrado: O(n/2 + b) porque para borrarla tengo que buscar la posición y uso head o tail y ya que la encuentro me toma b pasos constantes borrarla 

#### ordenamiento de medicinas

ordenamiento con merge sort: ...

#### uso de árbol

crear árbol de gramaje: ...

agregar nodo a árbol gramaje: ...

econtrar nodo en árbol gramaje: ...

## SICT0303B: Implementa acciones científicas 

### Implementa mecanismos para consultar información de las estructuras correctos y útiles dentro de un programa.

El programa tiene la opción de buscar medicinas por nombre direcamente en la lista (opción 3 en el menú)
El programa muestra resportes ordenados de medicinas (opción 4 en el menú)
El programa permite obtener medidas de gramaje del árbol (opción 5 en el menú)

### Implementa mecanismos de lectura de archivos correctos y útiles dentro de un programa. Usar de manera
Las medicinas están registradas en el archivo medicinas.csv de donde se leen al iniciar el programa.

### Implementa mecanismos de escritura de archivos correctos y útiles dentro de un programa. Usar de manera
Las medicinas agregadas se guardan al final del archivo medicinas.csv, con la función agrega nueva medicina, para que no tengan que ser recapturadas cada que vez que se corre el programa.

