/**
 * Project 0 - Hello World: Decision Maker 
 */

// Pins for LED lights 
const int led1 =  11; 
const int led2 = 12; 
const int led3 = 13;
const int led4 = 9;
const int led5 = 8;
const int led6 = 10;

// Pins for buttons
const int button1 = 2; 
const int button2 = 3; 

// Variables to keep track of state of button 
int buttonOneState = 0;
int buttonTwoState = 0;

// Variable to check if button was pressed 
bool buttonOnePressed = false; 
bool buttonTwoPressed = false; 

//Pins for 7 segment LED display 
int A =52;
int B = 44;
int C = 43;
int D = 40;
int E = 47; 
int F = 51; 
int G = 48;

//Variable to keep track of number displayed on LED display 
int segCounter = 2; 

// Array to store pin numbers of LED lights 
int ledPins[] = {11, 12, 13, 9, 8, 10};


/**
 * Function to set up input and output pins for buttons, LED lights, and 7 segment LED display 
 */
void setup() {
  // Initializing the LED light pins to be output pins
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  
  // Initialiaing the button pins to be o=input pins
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);

  //Initializing 7 segment LED display pins to be output pins 
  pinMode(A,OUTPUT);
  pinMode(B,OUTPUT);
  pinMode(C,OUTPUT);
  pinMode(D,OUTPUT);
  pinMode(E,OUTPUT);
  pinMode(F,OUTPUT);
  pinMode(G,OUTPUT);

  // Setting all segments of the LED display to be turned off 
  digitalWrite(A,HIGH);
  digitalWrite(B,HIGH);
  digitalWrite(C,HIGH);
  digitalWrite(D,HIGH);
  digitalWrite(E,HIGH);
  digitalWrite(F,HIGH);
  digitalWrite(G,HIGH);

  // Initializing random number generator 
  randomSeed(analogRead(0));
}

/**
 * Loop function to user input and output display. 
 */
void loop() {

  // Reading state of the button controlling 7 segment LED display (button 2)
  buttonTwoState = digitalRead(button2);
  // Checking if button 2 is pressed by user. If so set button pressed to true and delay for 500ms. 
  if (buttonTwoState == HIGH && buttonTwoPressed == false) {
    buttonTwoPressed = true; 
    delay(500); 
  }

  /**
   * Checking if button 2 has been pressed. If button 2 is pressed, check which number is set by user and display corresponding number on 7 segment LED display. 
   */ 
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

    // Checking if 7 segment LED display counter is set to the value 6. If so, reset counter back to 2. If not, increment the counter by a value of 1. 
    if (segCounter == 6){
      segCounter = 2;
    }
    else {
      segCounter++;
    }
  }

  // Reading state of the button controlling the triggers decision making (button 1) 
  buttonOneState = digitalRead(button1);

  // Checking if button 2 is pressed by user. If so set button pressed to true and delay for 500ms.
  if (buttonOneState == HIGH && buttonOnePressed == false) {
    buttonOnePressed = true;
    delay(500); 
  } 

  /**
   * Checking if button 1 has been pressed. If button 1 is pressed, check which number is set by user on 7 segment LED display and randomly generate a value within that range. 
   */ 
  if (buttonOnePressed == true){
    // Initializing variable to store the value that is randomly generated. 
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

    // Turning on the LED corresponding to the choice associated with the random number that is generated to indicate to the user. 
    digitalWrite(ledPins[choice], HIGH);
    delay(10000);  
    digitalWrite(ledPins[choice], LOW);
    buttonOnePressed = false; 
  }
}


/**
 * Functions to flash corresponding number of lights before a random number is generated and decision is made. 
 */
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


/**
 * Functions to display numbers 2 to 6 on 7 segment LED display. 
 */
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


/**
 * Functions to turn off the segments of numbers 2 to 6 that was previously displayed on 7 segment LED display. 
 */
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
