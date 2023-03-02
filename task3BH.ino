int PIRSens = 2;
const int soilMoisture = 3;
bool curr_State = false;
int LED = 7;

void setup()
{
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(PIRSens, INPUT);
  pinMode(soilMoisture, INPUT);

  attachInterrupt(digitalPinToInterrupt(PIRSens), swap, CHANGE);
  attachInterrupt(digitalPinToInterrupt(soilMoisture), soil_moisture, RISING);
}

void loop()
{
  delay(3000);
}

void swap()
{
  curr_State = !curr_State;
  digitalWrite(LED, curr_State);
  Serial.println("PIR sensor Interrupt");
}

void soil_moisture()
{
  Serial.println("Soil Moisture Interrupt");
}
