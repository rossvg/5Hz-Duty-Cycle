
float lowerVoltageBound = 0.7;
float upperVoltageBound = 2.23;
int outputPin = 9;
float period = 200; // period of 200 msecs = 5Hz

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(outputPin, OUTPUT);

}

void loop() {

  int sensorValue = analogRead(A5); // read analog value from incoming Vout signal
  float voltage = sensorValue * (5.0 / 1023.0);   // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  Serial.println(voltage); // print to serial monitor

  float percent = (voltage - lowerVoltageBound) / 1.36 ; // get approximate percentage of total voltage by subtracting voltage bounds
  Serial.println("Percent: ");
  Serial.print(percent);

    digitalWrite(outputPin, HIGH); 
    delay(period * percent); // high duty cycle for percent of voltage. Ex. 80% voltage = 80% HIGH for the total period
    digitalWrite(outputPin, LOW);
    delay(period - (period * percent));// The cycle is set to low for the remainder of the period.
  }




