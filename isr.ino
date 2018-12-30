const byte ledPin = 13;
const byte PA =9; // PA=1 portõa totalmente aberto;
const byte PF =8; // PF=1 portão totalmente fechado;
const byte isrPin = 0;  //define o pino da interrupção 0 -pin 2 1-pin 3
volatile byte dirRot = LOW; //define para que lado o motor roda (0 esquerda, 1 direita)

const byte pwmMotor=10; // define o pino pwm para controlar a velocidade do motor


void rotacao()    // função que coloca o motor a trabalhar
{
	
	dirRot = !dirRot;
}

void setup() {
	pinMode(ledPin, OUTPUT);
	pinMode(PA, INPUT);
	pinMode(PF, INPUT);
	pinMode(isrPin, INPUT_PULLUP); 
	attachInterrupt(isrPin, rotacao, RISING);
     
}

void loop() {
	int Pa_=digitalRead(PA);
	int Pf_=digitalRead(PF);		
		
	if ((Pa_!=true)&&(Pf_!=true))
	{
		digitalWrite(ledPin, dirRot);
		analogWrite(pwmMotor, 128); // pwm varia de [0..254]--> [0,5]V
	}
}