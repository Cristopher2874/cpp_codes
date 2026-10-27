Aquí tienes una propuesta técnica de arquitectura y diseño orientada a objetos para el simulador de frenado de vehículo, enfocándote exclusivamente en la física, las matemáticas, el manejo de datos e interfaces textuales de la aplicación.

---

## 1. Módulo Físico y Matemático: `PhysicsEngine`

Esta clase encapsulated toda la lógica de modelos físicos, conversión de unidades y evaluación de la trayectoria de frenado.

### **Ecuaciones Físicas Fundamentales**

1. **Conversión de Unidades de Velocidad:**
La velocidad inicial ingresada en $\text{km/h}$ debe convertirse a $\text{m/s}$:

$$v_0 = \frac{V_{\text{km/h}}}{3.6}$$


2. **Cálculo de la Desaceleración ($a$):**
A partir de la segunda ley de Newton ($F = ma$) y la fuerza de fricción dinámica ($F = \mu N = \mu m g$):



$$ma = -\mu mg \implies a = -\mu g$$



(Tomando $g = 9.81\text{ m/s}^2$).


3. **Distancia Total de Frenado ($s$):**
Despejando $s$ del modelo donde la velocidad final es $0\text{ m/s}$:



$$s = \frac{v_0^2}{2 \mu g}$$


4. **Velocidad a una Distancia Recorrida $x$ ($v_x$):**
Evaluación puntual de la velocidad a lo largo del tramo de derrape:



$$v_x = \sqrt{v_0^2 - 2 \mu g x}$$



Para convertir el resultado $v_x$ de vuelta a $\text{km/h}$:



$$V_{x, \text{km/h}} = v_x \cdot 3.6$$



---

### **Diseño de Clase: `PhysicsEngine**`

* **Atributos:**
* `double mu`: Coeficiente dinámico de fricción.


* `double v0_ms`: Velocidad inicial en $\text{m/s}$.
* `double g`: Aceleración gravitacional ($\approx 9.81\text{ m/s}^2$).




* **Métodos:**
* `double calcularDesaceleracion()`: Retorna $-\mu g$.


* `double calcularDistanciaFrenado()`: Retorna $s = \frac{v_0^2}{2\mu g}$.


* `double calcularVelocidadEnX(double x)`: Retorna $v_x$ en $\text{km/h}$ evaluada en la distancia $x$.


* `void generarTrayectoria(std::vector<double>& distancias, std::vector<double>& velocidades, double paso = 10.0)`: Recorre la trayectoria en incrementos (por ejemplo, cada $10\text{ m}$) e inserta valores en los vectores hasta alcanzar la distancia total de frenado $s$.





---

## 2. Módulo de Dominio y Composición: `Vehiculo` y `Neumatico`

Para cumplir con los **requisitos de POO y composición**, estructuramos el modelo conceptual donde una clase `Vehiculo` **posee instanciada internamente** una clase `Neumatico` (relación "posee un / *has-a*").

```
+------------------+         +------------------+
|     Vehiculo     |1       1|    Neumatico     |
+------------------+-------->+------------------+
| - masa: double   | (comp)  | - mu: double     |
| - neumatico      |         | - estado: string |
+------------------+         +------------------+

```

### **Diseño de Clases**

* **Clase `Neumatico`:**
* **Atributos:** `mu` (coeficiente de fricción con la superficie), `tipoSuperficie` (ej. seco, mojado, hielo).


* **Métodos:** Getters/Setters para el coeficiente $\mu$.


* **Clase `Vehiculo` (Composición):**
* **Atributos:**
* `Neumatico llanta`: Objeto embebido como miembro directo de la clase (relación de composición).


* `double v0_kmh`: Velocidad inicial.


* `PhysicsEngine motorFisico`: Instancia interna encargada de ejecutar los cálculos.


* `std::vector<double> vectorDistancias`: Almacena los puntos evaluados ($10\text{m}$, $20\text{m}$, ...).


* `std::vector<double> vectorVelocidades`: Almacena las velocidades asociadas a cada punto.




* **Métodos:**
* `void configurarSimulacion(double v_kmh, double mu)`: Inicializa el neumático y el motor de física.


* `void ejecutarCalculos()`: Invoca al `PhysicsEngine` para calcular $a$, $s$ y llenar los vectores de velocidad por tramos.


* Getters para obtener resultados calculados y vectores de datos.







---

## 3. Módulo de Flujo y Menú: `MenuEngine`

Encargado de la interacción textual en la consola (I/O). Aísla la lógica de captura de datos de la lógica física y de datos del vehículo.

### **Diseño de Clase: `MenuEngine**`

* **Atributos:**
* `Vehiculo vehiculo`: Instancia del vehículo a simular.




* **Métodos:**
* `void mostrarEncabezado()`: Presentación inicial de la consola.
* `void capturarDatosEntrada()`:
* Solicita $\mu$ (por ejemplo, validando que sea $> 0$).


* Solicita $v_0$ en $\text{km/h}$ (validando $v_0 > 0$).




* `void mostrarResultadosSimulacion()`:
* Imprime los datos iniciales.


* Muestra la desaceleración $a$ y la distancia total $s$.


* Recorre los `std::vector` en paralelo e imprime la tabla formateada con las distancias $X(\text{m})$ y sus respectivas velocidades $V(\text{km/h})$.




* `void iniciar()`: Método principal que coordina la captura de datos, invoca los cálculos del vehículo y despliega los resultados.



---

## 4. Estructura e Interacción de Artefactos de Software

```
+-----------------------------------------------------------------------+
|                              MenuEngine                               |
| - Captura datos desde consola (v0, mu)                                |
| - Llama al proceso de cálculo del Vehiculo                            |
| - Despliega resultados y tablas desde los vectores                    |
+-----------------------------------------------------------------------+
                                   |
                                   v
+-----------------------------------------------------------------------+
|                               Vehiculo                                |
| - Almacena v0, vectores de resultados (distancias, velocidades)       |
| - Contiene (Composición): Neumatico, PhysicsEngine                    |
+-----------------------------------------------------------------------+
                |                                      |
                v (Composición)                        v (Composición)
+-------------------------------+      +--------------------------------+
|           Neumatico           |      |         PhysicsEngine          |
| - Guarda 'mu' de contacto     |      | - Ecuaciones: a, s, v_x        |
+-------------------------------+      | - Genera recorrido en vectores |
                                       +--------------------------------+

```

---

## 5. Algoritmo de Generación de Vectores (Paso a Paso)

Para poblar los vectores requeridos en las especificaciones ($X_i$, $V_i$):

1. **Obtener $s$ (distancia total):** Calcular $s = \frac{v_0^2}{2 \mu g}$.


2. **Definir paso:** Establecer `paso = 10.0` metros.


3. **Bucle de simulación:**
* Inicializar `x = 10.0`.


* Mientras `x <= s`:
1. Calcular $v_x = \sqrt{v_0^2 - 2 \mu g x}$ en $\text{m/s}$.


2. Convertir $v_x$ a $\text{km/h}$ ($v_x \cdot 3.6$).


3. Insertar `x` en `vectorDistancias`.


4. Insertar $v_x$ en `vectorVelocidades`.


5. Incrementar `x += paso`.






4. **Verificación del caso de prueba dado:**
Con $v_0 = 130\text{ km/h}$ y $\mu = 0.5$:


* $a = -0.5 \times 9.81 = -4.905\text{ m/s}^2$


* $s = \frac{(36.1111)^2}{2 \times 0.5 \times 9.81} \approx 132.93\text{ m}$


* La iteración generará de $10\text{ m}$ a $130\text{ m}$ antes de detenerse, coincidiendo con los valores de validación especificados.