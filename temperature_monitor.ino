// Smart Temperature Monitoring System
const int tempPin = A0; // Temperature sensor connected to A0
const int ledPin = 7;   // LED connected to pin 7

void setup() {
  pinMode(ledPin, OUTPUT); // Set LED pin as output
  Serial.begin(9600);      // Start serial communication
}

void loop() {
  int sensorValue = analogRead(tempPin); // Read sensor value
  float voltage = sensorValue * (5.0 / 1023.0); // Convert to voltage
  float temperature = (voltage - 0.5) * 100.0; // Convert to Celsius

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" C");

  if (temperature > 30) { // Check threshold
    digitalWrite(ledPin, HIGH); // Turn ON LED
  } else {
    digitalWrite(ledPin, LOW); // Turn OFF LED
  }

  delay(1000); // Wait 1 second
}
