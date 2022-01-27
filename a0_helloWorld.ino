//Pins for LED lights 
const int led1 =  11; 
const int led2 = 12; 
const int led3 = 13;
const int led4 = 9;
const int led5 = 8;
const int led6 = 10;

//Pin for button
const int button1 = 2; 
const int button2 = 3; 
int buttonOneState = 0;
int buttonTwoState = 0;

//Pins for 7 segment LED display 
int A =52;
int B = 44;
int C = 43;
int D = 40;
int E = 47; 
int F = 51; 
int G = 48;

int segCounter = 2; 

int ledPins[] = {11, 12, 13, 9, 8, 10};

bool buttonOnePressed = false; 
bool buttonTwoPressed = false; 


void setup() {
  // initialize the LED pin as an output:
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);

  //initialize the 7 segment LED light as OUTPUT 
  pinMode(A,OUTPUT);
  pinMode(B,OUTPUT);
  pinMode(C,OUTPUT);
  pinMode(D,OUTPUT);
  pinMode(E,OUTPUT);
  pinMode(F,OUTPUT);
  pinMode(G,OUTPUT);

  digitalWrite(A,HIGH);
  digitalWrite(B,HIGH);
  digitalWrite(C,HIGH);
  digitalWrite(D,HIGH);
  digitalWrite(E,HIGH);
  digitalWrite(F,HIGH);
  digitalWrite(G,HIGH);
  
  Serial.begin(9600); 
  randomSeed(analogRead(0));
}

void loop() {

  buttonOneState = digitalRead(button2);
  //Serial.println(buttonTwoState);
  //Serial.println(segCounter);
  if (buttonOneState == HIGH && buttonOnePressed == false) {
    buttonTwoPressed = true; 
    delay(500); 
  }

  if (buttonTwoPressed == true){
    if (segCounter == 2){
      eraseNumberSix(); 
      displayNumberTwo(); 
    }
    else if (segCounter == 3){
      eraseNumberTwo(); 
      displayNumberThree(); 
    }
    else if (segCounter == 4){
      eraseNumberThree(); 
      displayNumberFour(); 
    }
    else if (segCounter == 5){
      eraseNumberFour(); 
      displayNumberFive(); 
    }
    else if (segCounter == 6){
      eraseNumberFive(); 
      displayNumberSix();  
    }
    buttonTwoPressed = false; 
    if (segCounter == 6){
      segCounter = 2;
    }
    else {
      segCounter++;
    }
    Serial.println(segCounter);
  }
  
  buttonOneState = digitalRead(button1);
  //Serial.println(buttonState);
  if (buttonOneState == HIGH && buttonOnePressed == false) {
    buttonOnePressed = true;
    delay(500); 
    //Serial.println("ON");
  } 

  if (buttonOnePressed == true){
    int choice; 
    if ((segCounter-1) == 2){
      choice = random(2); 
      beginTwoLights(); 
      beginTwoLights();
      beginTwoLights(); 
      beginTwoLights();
      beginTwoLights();
      beginTwoLights();
    }
    else if ((segCounter-1) == 3){
      choice = random(3); 
      beginThreeLights(); 
      beginThreeLights();
      beginThreeLights();
      beginThreeLights();
    }
    else if ((segCounter-1) == 4){
      choice = random(4); 
      beginFourLights(); 
      beginFourLights();
      beginFourLights();
      beginFourLights();
    }
    else if ((segCounter-1) == 5){
      choice = random(5); 
      beginFiveLights(); 
      beginFiveLights();
      beginFiveLights();
      beginFiveLights();
    }
    else if ((segCounter+4) == 6){
      choice = random(6); 
      beginSixLights(); 
      beginSixLights();
      beginSixLights();
      beginSixLights();
    }
    /**digitalWrite(ledPins[choice], HIGH);
    delay(10000);  
    digitalWrite(ledPins[choice], LOW);
    buttonOnePressed = false; */ 
    digitalWrite(led5, HIGH);
    delay(10000);  
    digitalWrite(led5, LOW);
    buttonOnePressed = false;
  }
}


void beginTwoLights(){
  digitalWrite(led1, HIGH);   
  delay(100); 
  digitalWrite(led1, LOW); 
  
  digitalWrite(led2, HIGH);   
  delay(100);  
  digitalWrite(led2, LOW); 
}

void beginThreeLights(){
  digitalWrite(led1, HIGH);   
  delay(100); 
  digitalWrite(led1, LOW); 
  
  digitalWrite(led2, HIGH);   
  delay(100);  
  digitalWrite(led2, LOW); 

  digitalWrite(led3, HIGH);
  delay(100);  
  digitalWrite(led3, LOW);
}

void beginFourLights(){
  digitalWrite(led1, HIGH);   
  delay(100); 
  digitalWrite(led1, LOW); 
  
  digitalWrite(led2, HIGH);   
  delay(100);  
  digitalWrite(led2, LOW); 

  digitalWrite(led3, HIGH);
  delay(100);  
  digitalWrite(led3, LOW);

  digitalWrite(led4, HIGH);
  delay(100);  
  digitalWrite(led4, LOW);
}

void beginFiveLights(){
  digitalWrite(led1, HIGH);   
  delay(100); 
  digitalWrite(led1, LOW); 
  
  digitalWrite(led2, HIGH);   
  delay(100);  
  digitalWrite(led2, LOW); 

  digitalWrite(led3, HIGH);
  delay(100);  
  digitalWrite(led3, LOW);

  digitalWrite(led4, HIGH);
  delay(100);  
  digitalWrite(led4, LOW);

  digitalWrite(led5, HIGH);
  delay(100);  
  digitalWrite(led5, LOW);
}

void beginSixLights(){
  digitalWrite(led1, HIGH);   
  delay(100); 
  digitalWrite(led1, LOW); 
  
  digitalWrite(led2, HIGH);   
  delay(100);  
  digitalWrite(led2, LOW); 

  digitalWrite(led3, HIGH);
  delay(100);  
  digitalWrite(led3, LOW);

  digitalWrite(led4, HIGH);
  delay(100);  
  digitalWrite(led4, LOW);

  digitalWrite(led5, HIGH);
  delay(100);  
  digitalWrite(led5, LOW);

  digitalWrite(led6, HIGH);
  delay(100);  
  digitalWrite(led6, LOW);

}



// Segments A, B, G, E, D 
void displayNumberTwo(){
  digitalWrite(A,LOW);
  digitalWrite(B,LOW);
  digitalWrite(G,LOW);
  digitalWrite(E,LOW);
  digitalWrite(D,LOW);
}

// Segments A, B, G, C, D
void displayNumberThree(){
  digitalWrite(A,LOW);
  digitalWrite(B,LOW);
  digitalWrite(G,LOW);
  digitalWrite(C,LOW);
  digitalWrite(D,LOW);
}

// Segments F, G, B, C
void displayNumberFour(){
  digitalWrite(F,LOW);
  digitalWrite(G,LOW);
  digitalWrite(B,LOW);
  digitalWrite(C,LOW);
}

// Segments A, F, G, C, D
void displayNumberFive() {
  digitalWrite(A,LOW);
  digitalWrite(F,LOW);
  digitalWrite(G,LOW);
  digitalWrite(C,LOW);
  digitalWrite(D,LOW);
}

// Segments A, F, G, E, C, D
void displayNumberSix(){
  digitalWrite(A,LOW);
  digitalWrite(F,LOW);
  digitalWrite(G,LOW);
  digitalWrite(E,LOW);
  digitalWrite(C,LOW);
  digitalWrite(D,LOW);
}

void eraseNumberTwo(){
  digitalWrite(A,HIGH);
  digitalWrite(B,HIGH);
  digitalWrite(G,HIGH);
  digitalWrite(E,HIGH);
  digitalWrite(D,HIGH);
}

// Segments A, B, G, C, D
void eraseNumberThree(){
  digitalWrite(A,HIGH);
  digitalWrite(B,HIGH);
  digitalWrite(G,HIGH);
  digitalWrite(C,HIGH);
  digitalWrite(D,HIGH);
}

// Segments F, G, B, C
void eraseNumberFour(){
  digitalWrite(F,HIGH);
  digitalWrite(G,HIGH);
  digitalWrite(B,HIGH);
  digitalWrite(C,HIGH);
}

// Segments A, F, G, C, D
void eraseNumberFive() {
  digitalWrite(A,HIGH);
  digitalWrite(F,HIGH);
  digitalWrite(G,HIGH);
  digitalWrite(C,HIGH);
  digitalWrite(D,HIGH);
}

// Segments A, F, G, E, C, D
void eraseNumberSix(){
  digitalWrite(A,HIGH);
  digitalWrite(F,HIGH);
  digitalWrite(G,HIGH);
  digitalWrite(E,HIGH);
  digitalWrite(C,HIGH);
  digitalWrite(D,HIGH);
}
