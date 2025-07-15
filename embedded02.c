[span_6](start_span)// Task 2: Home Automation with Bluetooth[span_6](end_span)
// Control LEDs via Bluetooth (simulating devices)

#include <SoftwareSerial.h> // Include SoftwareSerial library

// Define RX and TX pins for Bluetooth module on Arduino
// Connect HC-05/HC-06 TX to Arduino RX_BT_PIN (e.g., D10)
// Connect HC-05/HC-06 RX to Arduino TX_BT_PIN (e.g., D11) through a voltage divider (important for 5V Arduino to 3.3V BT module)
#define RX_BT_PIN 10 // Arduino D10 connected to Bluetooth module's TX
#define TX_BT_PIN 11 // Arduino D11 connected to Bluetooth module's RX (via voltage divider)

SoftwareSerial bluetooth(RX_BT_PIN, TX_BT_PIN); // RX, TX

// Define pins for devices (LEDs for simulation, replace with relay pins for actual devices)
#define DEVICE1_PIN 2 // Connect LED/Relay to Arduino Digital Pin 2
#define DEVICE2_PIN 3 // Connect LED/Relay to Arduino Digital Pin 3

void setup() {
  Serial.begin(9600);    // Initialize hardware serial for debugging (optional)
  bluetooth.begin(9600); // Initialize software serial for Bluetooth communication at 9600 baud rate (common for HC-05/06)
  Serial.println("Bluetooth Home Automation Ready!");
  Serial.println("Send '1' to turn Device 1 ON, '0' to turn Device 1 OFF");
  Serial.println("Send '3' to turn Device 2 ON, '2' to turn Device 2 OFF");

  pinMode(DEVICE1_PIN, OUTPUT); // Set device pins as output
  pinMode(DEVICE2_PIN, OUTPUT);
  digitalWrite(DEVICE1_PIN, LOW); // Ensure devices are OFF initially
  digitalWrite(DEVICE2_PIN, LOW);
}

void loop() {
  if (bluetooth.available()) { // Check if data is available from Bluetooth module
    char command = bluetooth.read(); // Read the incoming byte
    Serial.print("Received command: ");
    Serial.println(command);

    if (command == '1') {
      digitalWrite(DEVICE1_PIN, HIGH); // Turn Device 1 ON
      bluetooth.println("Device 1 ON");
      Serial.println("Device 1 ON");
    } else if (command == '0') {
      digitalWrite(DEVICE1_PIN, LOW);  // Turn Device 1 OFF
      bluetooth.println("Device 1 OFF");
      Serial.println("Device 1 OFF");
    } else if (command == '3') {
      digitalWrite(DEVICE2_PIN, HIGH); // Turn Device 2 ON
      bluetooth.println("Device 2 ON");
      Serial.println("Device 2 ON");
    } else if (command == '2') {
      digitalWrite(DEVICE2_PIN, LOW);  // Turn Device 2 OFF
      bluetooth.println("Device 2 OFF");
      Serial.println("Device 2 OFF");
    } else {
      bluetooth.println("Invalid Command");
      Serial.println("Invalid Command");
    }
  }
}
