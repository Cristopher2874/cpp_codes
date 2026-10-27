import matplotlib.pyplot as plt

# Datos de Vce en Volts
Vce = [0.2, 0.4, 0.6, 0.8, 1.0, 1.5, 2.0]

# Datos de Ic en mA para cada Ib
Ic_50uA = [8.06, 8.17, 8.21, 8.26, 8.29, 8.37, 8.51]
Ic_90uA = [14.32, 14.77, 14.87, 15.03, 15.12, 15.33, 15.62]
Ic_130uA = [20.01, 21.10, 21.30, 21.50, 21.70, 22.10, 22.60]
Ic_180uA = [26.60, 28.60, 29.10, 29.70, 30.10, 31.30, 32.60]

# Punto de operación (Q-point)
Vce_q = 1.76
Ic_q = 15.0

# Crear la figura
plt.figure(figsize=(10, 6))

# Graficar las curvas características
plt.plot(Vce, Ic_50uA, marker='o', label=r'$I_B = 50\ \mu A$')
plt.plot(Vce, Ic_90uA, marker='s', label=r'$I_B = 90\ \mu A$')
plt.plot(Vce, Ic_130uA, marker='^', label=r'$I_B = 130\ \mu A$')
plt.plot(Vce, Ic_180uA, marker='d', label=r'$I_B = 180\ \mu A$')

# Marcar el punto de operación
plt.plot(Vce_q, Ic_q, 'ro', markersize=10, label='Punto de operación (1.76 V, 15 mA)')
# Agregar una anotación para resaltar el punto Q
plt.annotate('Punto Q', xy=(Vce_q, Ic_q), xytext=(Vce_q - 0.3, Ic_q + 2),
             arrowprops=dict(facecolor='black', arrowstyle='->'), fontsize=12)

# Configuración de la gráfica
plt.title('Familia de curvas características del transistor 2N2222', fontsize=14)
plt.xlabel(r'Voltaje Colector-Emisor $V_{CE}$ (V)', fontsize=12)
plt.ylabel(r'Corriente de Colector $I_C$ (mA)', fontsize=12)
plt.grid(True, linestyle='--', alpha=0.7)
plt.legend(loc='upper left')

# Ajustar los límites de los ejes para mejor visualización
plt.xlim(0, 2.2)
plt.ylim(0, 35)

# Mostrar la gráfica
plt.tight_layout()
plt.show()