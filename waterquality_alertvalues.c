//PrintJustOneLine
bool PrintOneLine(void);
//ProgramsForTresholdActions
void pHHighAlert();
void tempHighAlert();
void TDSHighAlert();
void pHLowAlert();
void tempLowAlert();
void TDSLowAlert();
void Alerts();

//StopValueForSerialRead
boolean StopAfterLine = false;
//ReturningAlertValues
int AlertValue1;
int AlertValue2;
int AlertValue3;
int AlertValue4;
int AlertValue5;
int AlertValue6;



//RunOnce
void setup(){
  pinMode(LED_BUILTIN, OUTPUT);
  //RunOnce
  Serial.begin(9600);
  //SerialPrintTest
}


//LOOP
void loop(){
  
//ValuesWithDUMMY
float pHMax = 5; //MaxThresholdValue
float pHMin = 0; //MinThresholdValue
float tempMax = 5; //MaxThresholdValue
float tempMin = 0; //MinThresholdValue
float TDSMax = 5; //MaxThresholdValue
float TDSMin = 0; //MinThresholdValue
float pH = 6; //Sensor <-----------------------------------//ManualTestingValues!!! Replace with value counted from sensor voltage!!
float temp = 1; //Sensor <---------------------------------//ManualTestingValues!!! Replace with value counted from sensor voltage!!
float TDS = 1; //Sensor //ManualTestingValues<-------------//ManualTestingValues!!! Replace with value counted from sensor voltage!!
  

  

//CHECK IF ALERTS HAVE RETURNED VALUES WHEN TRIGGERED
//pHHigh
while(pHMax < pH) {  
  if(AlertValue1 == 0){
  pHHighAlert();
  PrintOneLine();
  delay(1000);
  }
  if(AlertValue1 == 1){digitalWrite(3, HIGH);}
  Serial.println(AlertValue1);//Testing
  }


//tempHigh
while(tempMax < temp) {  
  if(AlertValue2 == 0){
  tempHighAlert();
  PrintOneLine();
  delay(1000);
  }
  if(AlertValue2 == 1){digitalWrite(4, HIGH);}
  Serial.println(AlertValue2);//Testing
  }


//TDSpHigh
while(TDSMax < TDS) {  
  if(AlertValue3 == 0){
  TDSHighAlert();
  PrintOneLine();
  delay(1000);
  }
  if(AlertValue3 == 1){digitalWrite(5, HIGH);}
  Serial.println(AlertValue3);//Testing
  }


//pHLow
while(pHMin > pH) {  
  if(AlertValue4 == 0){
  pHLowAlert();
  PrintOneLine();
  delay(1000);
  }
  if(AlertValue4 == 1){digitalWrite(6, HIGH);}
  Serial.println(AlertValue4);//Testing
  }


//tempLow
while(tempMin > temp) {  
  if(AlertValue5 == 0){
  tempLowAlert();
  PrintOneLine();
  delay(1000);
  }
  if(AlertValue5 == 1){digitalWrite(7, HIGH);}
  Serial.println(AlertValue5);//Testing
  }


//TDSLow
while(TDSMin > TDS) {  
  if(AlertValue6 == 0){
  TDSLowAlert();
  PrintOneLine();
  delay(1000);
  }
  if(AlertValue6 == 1){digitalWrite(8, HIGH);}
  Serial.println(AlertValue6);//Testing
  }
}//END LOOP



//ALERT PROGRAMS
//phHigh
void pHHighAlert(){
if(StopAfterLine == false){
Serial.println("pHHigh!!");
AlertValue1 = true;
//lcd.print("pHHigh!!");
int ButtonValue = analogRead(A0);//CHANGE BUTTON
if(ButtonValue > 0){
Alerts();
 }
}
  PrintOneLine(); 
}

//tempHigh
void tempHighAlert(){
if(StopAfterLine == false){
Serial.println("tempHigh!!");
AlertValue2 = true;
//lcd.print("tempHigh!!");
int ButtonValue = analogRead(A1);//CHANGE BUTTON
if(ButtonValue > 0){
Alerts();
 }
}
  PrintOneLine(); 
}

//TDSHigh
void TDSHighAlert(){
if(StopAfterLine == false){
Serial.println("TDSHigh!!");
AlertValue3 = true;
//lcd.print("TDSHigh!!");
int ButtonValue = analogRead(A2);//CHANGE BUTTON
if(ButtonValue > 0){
Alerts();
 }
}
  PrintOneLine(); 
}

//pHLow
void pHLowAlert(){
if(StopAfterLine == false){
Serial.println("pHLow!!");
AlertValue4 = true;
//lcd.print("pHLow");
int ButtonValue = analogRead(A3);//CHANGE BUTTON
if(ButtonValue > 0){
Alerts();
 }
}
  PrintOneLine(); 
}

//tempLow
void tempLowAlert(){
if(StopAfterLine == false){
Serial.println("tempLow!!");
AlertValue5 = true;
//lcd.print("tempLow");
int ButtonValue = analogRead(A4);//CHANGE BUTTON
if(ButtonValue > 0){
Alerts();
 }
}
  PrintOneLine(); 
}

//TDSLow
void TDSLowAlert(){
if(StopAfterLine == false){
Serial.println("TDSLow!!");
AlertValue6 = true;
//lcd.print("TDSLow");
int ButtonValue = analogRead(A5);//CHANGE BUTTON
if(ButtonValue > 0){
Alerts();
 }
}
  PrintOneLine(); 
}


//IfNeededToPrompt
void Alerts(){
if(StopAfterLine == false){
Serial.println("Alerts");
//lcd.print("Alerts");
}
PrintOneLine();
}


//StoppingSerialPrintToOneLine
bool PrintOneLine(void){
if(StopAfterLine == false){}
StopAfterLine = true;
return StopAfterLine;
}