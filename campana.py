import numpy as np
import matplotlib.pyplot as plt
import scipy.stats as stats

def graficar_campana(mu, sigma, lie, lse, nominal, titulo):
    # Generar datos del eje x (± 4 desviaciones estándar para capturar la campana completa)
    x = np.linspace(mu - 4*sigma, mu + 4*sigma, 1000)
    y = stats.norm.pdf(x, mu, sigma)

    plt.figure(figsize=(10, 5))
    plt.plot(x, y, color='blue', lw=2)
    
    # Rellenar área bajo la curva
    plt.fill_between(x, y, alpha=0.2, color='blue')

    # Marcar Límite Inferior (LIE) y Superior (LSE)
    plt.axvline(lie, color='red', linestyle='solid', lw=2, label=f'LIE = {lie}')
    plt.axvline(lse, color='red', linestyle='solid', lw=2, label=f'LSE = {lse}')
    
    # Marcar el Nominal vs la Media para mostrar el desfasamiento
    plt.axvline(nominal, color='green', linestyle='dashed', lw=2, label=f'Nominal = {nominal}')
    plt.axvline(mu, color='orange', linestyle='dashed', lw=2, label=f'Media ($\mu$) = {mu}')

    plt.title(titulo, fontsize=14)
    plt.xlabel('Dimensión (mm)', fontsize=12)
    plt.ylabel('Densidad de Probabilidad', fontsize=12)
    plt.legend(loc='upper right')
    plt.grid(True, alpha=0.5)
    plt.show()

# Gráfica del Problema 1 (Ejes)
graficar_campana(mu=24.989, sigma=0.0253, lie=24.95, lse=25.05, nominal=25.00, 
                 titulo="Problema 1: Ejes de Automóviles (Desfasamiento de -0.011 mm)")

# Gráfica del Problema 2 (Tornillos)
graficar_campana(mu=50.2, sigma=0.1, lie=49.5, lse=50.5, nominal=50.0, 
                 titulo="Problema 2: Fabricación de Tornillos (Desfasamiento de +0.2 mm)")

graficar_campana(mu=25.1, sigma=0.05, lie=24.8, lse=25.2, nominal=25.0, 
                  titulo='Problema 3: Campana de Gauss con Desfasamiento (Ejes metálicos)')