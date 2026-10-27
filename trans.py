import matplotlib.pyplot as plt
import numpy as np

# --- Parámetros Generales ---
Rc = 3000  # Ohms
vce_rango = np.linspace(0, 24, 500)

def curva_transistor(vce, ic_nominal, v_ruptura):
    """Genera la curva característica del transistor con saturación y ruptura."""
    ic_sat_region = ic_nominal * (1 - np.exp(-5 * vce))
    ic_ruptura = 0.005 * np.exp(1.2 * (vce - v_ruptura))
    return ic_sat_region + ic_ruptura

# --- Datos de los Escenarios ---
# Escenario 1: Inicial (Vcc=15V, Vbb=15V)
Vcc1 = 15
Ic_Q1 = 2.48
Vce_Q1 = 7.55
Ic_sat1 = (Vcc1 / Rc) * 1000

# Escenario 2: Cambio en Vcc (Vcc=20V, Vbb=15V)
Vcc2 = 20
Ic_Q2 = 2.48
Vce_Q2 = 12.55
Ic_sat2 = (Vcc2 / Rc) * 1000

# Escenario 3: Cambio en Vbb (Vcc=15V, Vbb=20V)
Vcc3 = 15
Ic_Q3 = 3.35
Vce_Q3 = 4.94
Ic_sat3 = (Vcc3 / Rc) * 1000

# Generación de las curvas del transistor
Curva_Q1_Q2 = curva_transistor(vce_rango, Ic_Q1, v_ruptura=18)
Curva_Q3 = curva_transistor(vce_rango, Ic_Q3, v_ruptura=13)

# ==========================================
# COMPARACIÓN 1: Inicial vs Cambio en VCC
# ==========================================
plt.figure(figsize=(10, 6))

# Curva característica única (misma corriente de base)
plt.plot(vce_rango, Curva_Q1_Q2, color='teal', linewidth=2, label='Curva $I_C$ ($V_{BB}=15V$)')

# Rectas de carga
plt.plot([0, Vcc1], [Ic_sat1, 0], color='blue', linestyle='--', label='Recta de Carga (Vcc=15V)')
plt.plot([0, Vcc2], [Ic_sat2, 0], color='red', linestyle='--', label='Recta de Carga (Vcc=20V)')

# Puntos de Operación
plt.plot(Vce_Q1, Ic_Q1, marker='o', markersize=8, color='blue', label='Punto Q1 (Inicial)')
plt.plot(Vce_Q2, Ic_Q2, marker='s', markersize=8, color='red', label='Punto Q2 (Cambio Vcc)')

# Líneas guía
plt.vlines(x=[Vce_Q1, Vce_Q2], ymin=0, ymax=[Ic_Q1, Ic_Q2], color=['blue', 'red'], linestyle=':', alpha=0.6)
plt.hlines(y=[Ic_Q1, Ic_Q2], xmin=0, xmax=[Vce_Q1, Vce_Q2], color=['blue', 'red'], linestyle=':', alpha=0.6)

plt.title('Comparación 1: Circuito Inicial vs. Cambio en $V_{CC}$ a 20V')
plt.xlabel('Voltaje Colector-Emisor $V_{CE}$ (V)')
plt.ylabel('Corriente de Colector $I_C$ (mA)')
plt.xlim(0, 24)
plt.ylim(0, 8)
plt.grid(True, linestyle=':', linewidth=0.7)
plt.legend()
plt.annotate(f'Q1 ({Vce_Q1}V, {Ic_Q1}mA)', xy=(Vce_Q1, Ic_Q1), xytext=(Vce_Q1 - 3, Ic_Q1 + 0.5))
plt.annotate(f'Q2 ({Vce_Q2}V, {Ic_Q2}mA)', xy=(Vce_Q2, Ic_Q2), xytext=(Vce_Q2 + 0.5, Ic_Q2 + 0.5))

print("Mostrando Comparación 1... (Cierra la ventana para ver la siguiente gráfica)")
plt.show()

# ==========================================
# COMPARACIÓN 2: Inicial vs Cambio en VBB
# ==========================================
plt.figure(figsize=(10, 6))

# Dos curvas características (distinta corriente de base)
plt.plot(vce_rango, Curva_Q1_Q2, color='teal', alpha=0.7, label='Curva $I_C$ ($V_{BB}=15V$)')
plt.plot(vce_rango, Curva_Q3, color='indigo', alpha=0.7, label='Curva $I_C$ ($V_{BB}=20V$)')

# Recta de carga única (mismo Vcc y Rc)
plt.plot([0, Vcc1], [Ic_sat1, 0], color='blue', linestyle='-', linewidth=2, alpha=0.6, label='Recta de Carga Única ($V_{CC}=15V$)')

# Puntos de Operación
plt.plot(Vce_Q1, Ic_Q1, marker='o', markersize=8, color='blue', label='Punto Q1 (Inicial)')
plt.plot(Vce_Q3, Ic_Q3, marker='^', markersize=8, color='purple', label='Punto Q3 (Cambio Vbb)')

# Líneas guía
plt.vlines(x=[Vce_Q1, Vce_Q3], ymin=0, ymax=[Ic_Q1, Ic_Q3], color=['blue', 'purple'], linestyle=':', alpha=0.6)
plt.hlines(y=[Ic_Q1, Ic_Q3], xmin=0, xmax=[Vce_Q1, Vce_Q3], color=['blue', 'purple'], linestyle=':', alpha=0.6)

plt.title('Comparación 2: Circuito Inicial vs. Cambio en $V_{BB}$ a 20V')
plt.xlabel('Voltaje Colector-Emisor $V_{CE}$ (V)')
plt.ylabel('Corriente de Colector $I_C$ (mA)')
plt.xlim(0, 18)
plt.ylim(0, 8)
plt.grid(True, linestyle=':', linewidth=0.7)
plt.legend()
plt.annotate(f'Q1 ({Vce_Q1}V, {Ic_Q1}mA)', xy=(Vce_Q1, Ic_Q1), xytext=(Vce_Q1 + 0.5, Ic_Q1 - 0.5))
plt.annotate(f'Q3 ({Vce_Q3}V, {Ic_Q3}mA)', xy=(Vce_Q3, Ic_Q3), xytext=(Vce_Q3 + 0.5, Ic_Q3 + 0.5))

print("Mostrando Comparación 2... Fin del programa.")
plt.show()