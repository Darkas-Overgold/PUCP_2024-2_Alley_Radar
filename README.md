# PUCP 2024-2 Alley Radar

## Overview

The *Alley Radar* project is a final assignment for the Digital Systems course. It leverages *C programming* and *embedded systems concepts* to control a radar-like system using ultrasonic sensors and servomotors. The radar scans an area to detect objects and measure distances, displaying the results through a console or external interface.

This project demonstrates integration between hardware components and software, focusing on sensor control, real-time data processing, and motor actuation.

---

## Features

- *Ultrasonic Distance Measurement*: Uses an ultrasonic sensor to detect object distances in centimeters.
- *Servo Motor Control*: Rotates the servo to predefined angles for scanning the area.
- *Real-Time Scanning*: Continuously collects and displays data during operation.
- *Console Output*: Displays distance readings and servo angles in a user-friendly format.
- *Modular Functions*:
  - setupServo(): Configures PWM for the servo motor.
  - setupUltrasonicSensor(): Prepares the GPIO pins for the ultrasonic sensor.
  - moveServo(angle): Adjusts the servo to a specified angle.
  - readUltrasonicDistance(): Reads the distance to the nearest object using the sensor.

---

## File Structure

PUCP_2024-2_Alley_Radar/ ├── radar.c          # Main program logic in C ├── index.html       # Optional front-end interface for displaying data ├── styles.css       # Styling for the front-end (if applicable) └── images/          # Images for documentation or visualization

---

## Requirements

- *Hardware*:
  - Ultrasonic sensor (e.g., HC-SR04)
  - Servo motor (e.g., SG90)
  - Microcontroller (e.g., TM4C123 series)
- *Software*:
  - GCC Compiler for C
  - UART interface or other debugging tools

---

## Setup and Installation

### Hardware Connections:
1. Connect the ultrasonic sensor's TRIGGER and ECHO pins to GPIO pins on the microcontroller (e.g., PE1 and PE2).
2. Connect the servo motor to a PWM-capable GPIO pin (e.g., PB6).
3. Ensure the microcontroller is powered and properly grounded with the sensors and actuators.

### Software Setup:
1. Clone the repository:
   ```bash
   git clone https://github.com/Darkas-Overgold/PUCP_2024-2_Alley_Radar.git
   cd PUCP_2024-2_Alley_Radar

2. Compile the program:

gcc radar.c -o radar


3. Flash the compiled binary onto the microcontroller (e.g., using a JTAG programmer).




---

Usage

1. Power on the microcontroller with the radar hardware connected.


2. The servo will start rotating in 10° increments, covering a range of 0° to 180°.


3. At each step, the ultrasonic sensor will measure the distance to the nearest object and display the results in the console.


4. Example output:

Angle: 0°  Distance: 50 cm
Angle: 10° Distance: 47 cm
...




---

Future Improvements

Integration with a web-based interface for real-time visualization.

Enhanced resolution by increasing the number of servo steps.

Support for multiple ultrasonic sensors to expand the scanning range.



---

Contributions

Contributions are welcome! Please fork the repository and submit a pull request with your enhancements or fixes.


---

License

This project is open-source and available under the MIT License. See the LICENSE file for more details.

This README.md provides a detailed explanation of the repository's functionality and setup process. If there are specific features or additional files not included here, feel free to share more details, and I can refine the content.
