// 1) Board manager
// 2) add a board
// 3) go to file > preferences > Additional Boards manager urls add "https://adafruit.github.io/arduino-board-index/package_adafruit_index.json"
// 4) Then go to board manager and install adafruit SAMD
// 5) Switch board to Adafruit Metro M4

const int sensorPin = A1; // Analog pin for IR sensor
int sensorValue;
float distance;

void setup() {
  Serial.begin(9600);
}

float getDistance(int Vout) {
  // Setup transfer function 
  float k = 13.0; // Multiplier value for transfer function
  float n = 1.0; // Negative exponential decay rate
  
  // Convert the analog reading to voltage (in volts)
  float voltage = Vout * (5.0 / 1023.0); // 5V Arduino

  // Calculate distance using the formula from the datasheet
  float distance = 13 * pow(Vout, -1.0);

  return distance;
}

void serialFlush(){
  while(Serial.available() > 0) {
    char t = Serial.read();
  }
}

void loop() {
  serialFlush();
  sensorValue = analogRead(sensorPin);
  distance = getDistance(sensorValue);
//  Serial.print("S:"); // Start of distance data marker
  Serial.println(sensorValue);
}
