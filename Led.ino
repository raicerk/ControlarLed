/********************************/
/*  Ordenar Parpadeos de un Led */
/********************************/

/*** Fernando Martinez Mendoza ***/

//** Definiciones **//

int parpadeos;
int led = 2;

//** Programa **//

void setup(){
  Serial.begin(9600);     // Inicia la comunicación serial
  pinMode(led, OUTPUT);
}
 
void loop(){
  if (Serial.available()>0){               // Comprueba si el serial está disponible
    parpadeos =  Serial.read()-48;         // leemos el número de parpadeos
    if (parpadeos >= 1 && parpadeos <= 9)  // Si el valor introducido está entre 1 y 9
    {
      Serial.print("Se van a dar ");
      Serial.print(parpadeos);
      Serial.println(" parpadeos");
      delay(1500);
      for(int i=0;i<parpadeos;i++){        // Realiza los parpadeos
         digitalWrite(led, HIGH);
         delay(100);
         digitalWrite(led, LOW);
         delay(200);
      }
    }
    else {                                 // Si introducimos un valor erroneo
      Serial.println("El dato introducido es incorrecto");
    }
  }
}
