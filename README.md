# Aplicación de la ecuación de Harris-Benedict para el cálculo del consumo calórico diario individual
El proyecto toma como base el contenido teórico de: 

"Juan Antonio Pascual. (2018, August 11). Con esta fórmula sabrás cuántas calorías debes comer al día para adelgazar. Retrieved September 20, 2021, from ComputerHoy website: https://computerhoy.com/noticias/life/esta-formula-te-dice-cuantas-calorias-debes-comer-dia-adelgazar-286837" 

Asimismo, toma la aplicación práctica ofrecida por:

"Harris Benedict Ecuación :: MediCalculator ::: ScyMed ::: (2021). Retrieved September 20, 2021, from Scymed.com website: http://www.scymed.com/es/smnxpn/pnfdd219.htm"

Esto con la finalidad de crear, por medio del csv anexado y la información brindada por el paciente, un conocimiento de la Tasa Metabólica Basal del individuo la cuál equivale al consumo de la persona en reposo. Por lo tanto, generar un contraste con el ejercicio ejecutado, puede otorgar una visualización del contenido calórico que la persona requiere ingresar a su cuerpo de manera diaria con el objetivo de tener una alimentación correctamente balanceada. La meta de este proyecto es servir como herramienta nutricional para mantener una base de datos moldeable y legible de los diferentes pacientes que deseen conocer este fundamental dato para la salud humana. 

## SICT0302B: Toma decisiones 

### Selecciona y usa una estructura lineal adecuada al problema
Se seleccionó la lista doblemente enlazada ya que el manejo de eliminación, modificación y adición de citas manejando archivos txt resulta muy práctico cuando se manejan los valores numéricos por medio de nodos accesibles en todas ambas direcciones, cada nodo representando una cita distinta. Asimismo, que esté doblemente enlazada va a facilitar futuros ordenamientos y posibles adiciones al proyecto que permitan al nutricionista posicionar sus citas a la medida y mantener un control de su posterior trabajo. Para finalizar, la complejidad que va de O(1) a O(n) de los métodos anexados en la estructura lineal evita complicaciones a la hora de realizar operaciones y mantiene al programa simplificado a la hora de tomar memoria del equipo.

### Selecciona un algoritmo de ordenamiento adecuado al problema
Se utilizó Selection Sort en los ejemplos solicitados ya que, tomado de la referencia "When to use each Sorting Algorithm - GeeksforGeeks. (2020, May 20). Retrieved September 20, 2021, from GeeksforGeeks website: https://www.geeksforgeeks.org/when-to-use-each-sorting-algorithms/", Selection Sort es muy propio para listas cortas con digitos sencillos, su complejidad espacial es O(1) y su complejidad de tiempo es O(n*n), haciéndolo excelente para una lista simple con un par de nombres y números, su utilidad es muy entendible y propia para comprender y futuramente progresar en los algoritmnos de "sorting" y perfecto para trabajar con uso de memoria limitada gracias a su habilidad para minimizar los intercambios.

### Usa un árbol adecuado para resolver un problema

Implementación de un heap que permita guardar valores de cobro de las citas para calcular las ganancias semanales del trabajador. Este se basa en una complejidad de O(n) gracias a su dependencia de los pacientes esperados.

## SICT0301B: Evalúa los componentes

### Presenta Casos de Prueba correctos y completos para todas las funciones y procedimientos del programa,

Se presentan casos de prueba en el archivo "Tabla_Harris-Benedict.csv" y y los archivos de días y horas en .txt. Estos pueden ser modificados al gusto del usuario para poder laborar de la manera en la que este lo desee. Se encuentran ligadas al funcionamiento de todas las estructuras de datos del programa.

### Hace un análisis de complejidad correcto y completo para todo el programa y sus componentes

El análisis de complejidad se encuentra escrito en cada una de las explicaciones de los algoritmos descritos anteriormente.
Los demás detalles del programa, como los menús (principal y de citas) están basados en O(n) por su uso de recursión basado en el clic de un número que define la cantidad inespecífica de veces en las que un usuario requiera de su utilización.

## SICT0303B: Implementa acciones científicas 

### Implementa mecanismos para consultar información de las estructuras correctos y útiles dentro de un programa.

Este programa está completamente basado en la consulta y modificación de información. Un nutriólogo puede perfectamente acceder a los datos, imprimirlos gracias a su ordenamiento y disponer de ellos a su antojo. Asimismo, este posee menús que facilitan el acceso y modificación de los datos que van desde la creación de citas hasta modificación de los datos del paciente.

### Implementa mecanismos de lectura de archivos correctos y útiles dentro de un programa. Usar de manera

La lectura de los archivos tanto txt como el csv son perfectamente funcionales y útiles en el programa.

### Implementa mecanismos de escritura de archivos correctos y útiles dentro de un programa. Usar de manera

Se pueden escribir perfectamente las citas en los archivos txt, esto incluyendo sus datos en dos diferentes archivos con su posterior lectura correcta.

## Actualización final
-Se corrigieron los errores de funcionamiento del heap
-Se actualizó el README para contener más documentación.
