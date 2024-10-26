#importamos librerias a usar
import random
import time

#funcion para crear un numero aleatorio simulando la deteccion de agua
def crear_numero():
    #creamos un numero aleatorio constante
    numero = random.randint(0,3)
    return numero

#bucle que recibira el dato para hacer funcionar el servomotor
while True:
    #almacenamos el numero en una variable
    numero = crear_numero()
    #hacemos un delay
    time.sleep(1)
    #condicional de la deteccion de agua
    if numero != 0:
        print("detecte agua moviendo el servomotor")
        #simulamos que se paso la lluvia
        time.sleep(5)
        numero = 0
        print("devolviendo el servomotor a su estado original")
    #si el numero es 0 osea "ausencia de agua" el servomotor no se movera
    else:
        print("no se detecta agua servomotor quieto")