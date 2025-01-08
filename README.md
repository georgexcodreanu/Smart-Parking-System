# Smart-Parking-System

# Introduction
This project is an automated parking management system based on Arduino that monitors and displays available parking slots, allows vehicle entry using sensors, and controls an automatic barrier.

The purpose of the project is to simplify the parking management process in small or medium-sized areas by providing an accessible and efficient technological solution.

The idea came from wanting a better way to keep track of free parking spaces and make it easier for drivers to find one quickly.

# Hardware design
The current hardware implementation is part of a smart parking system designed to:
 - Detect vehicle presence using PIR sensors.
 - Control a servo motor to operate the parking gate.
 - Display parking status.

The system is built using an Arduino UNO, which processes input signals from sensors and controls outputs for motor movement and status display.

# Block Diagram
![diagrama](https://github.com/user-attachments/assets/cdc37846-08fc-4e10-81f9-614a07b0baa7)

## BOM (Bill Of Materials)

| No.  | Component              | Specifications                         | Link/Datasheet                         |
|------|------------------------|---------------------------------------|---------------------------------------|
| 1    | **Arduino UNO**        | ATmega328P Microcontroller            | [Arduino UNO](https://www.alldatasheet.com/datasheet-pdf/view/241077/ATMEL/ATMEGA328P.html) |
| 2    | **PIR Sensor (x2)**    | HC-SR501 Motion Sensor                | [HC-SR501 Datasheet](https://www.alldatasheet.com/html-pdf/1131987/ETC2/HC-SR501/112/1/HC-SR501.html) |
| 3    | **Servo Motor**        | SG90, 9g Micro Servo                  | [SG90 Servo Motor](https://www.alldatasheet.com/datasheet-pdf/pdf/1572383/ETC/SG90.html)  |
| 4    | **LCD Display 16x2**   | Alphanumeric Display (16x2)           | [LCD 16x2 Datasheet](https://components101.com/sites/default/files/component_datasheet/16x2%20LCD%20Datasheet.pdf) |
| 5    | **Potentiometer**      | 10kΩ (for LCD Contrast Adjustment)    | [10kΩ Potentiometer](https://components101.com/sites/default/files/component_datasheet/potentiometer%20datasheet.pdf) |
| 6    | **Breadboard & Wires** | Breadboard and jumper wires           | -                                     |
| 7    | **Power Supply**       | USB or 5V Power Source                | -                                     |



# Detailed Hardware Description
1. Arduino UNO
   - Role: Acts as the central processor for input/output operations.
   - Digital Pins:
     - Reads input signals from the PIR sensors.
     - Controls the LCD display and the servo motor.
   - PWM Pin: Controls the servo motor to open/close the gate.
   - Analog Pin: Adjusts the contrast of the LCD using a potentiometer.
  
     
2. PIR Sensors
   - Specifications:
     - Power: 5V
     -  Output Signal: HIGH/LOW when motion is detected.
   - Role: Detects vehicle presence near the parking gate.
   - Connections:
     - VCC → 5V
     - GND → GND
     - OUT → Arduino Digital Pins
    
       
3. Servo Motor
   - Specifications:
     - Type: SG90
     - Power: 5V
     - Control: PWM signal.
   - Role: Operates the parking gate by rotating to open/close positions.
   - Connections:
     - VCC → 5V
     - GND → GND
     - Signal → PWM pin (e.g., D9).
    
       
  4. LCD Display (16x2)
     - Specifications:
       - Power: 5V
       - Interface: 4-bit parallel mode using digital pins.
     - Role: Displays parking status messages:
     - Connections:
       - VCC → 5V
       - GND → GND
       - Data and control pins → Arduino Digital Pins.

      
  5. Potentiometer
     - Role: Adjusts the LCD display contrast.
     - Connections:
       - Middle Pin → LCD contrast pin
       - Outer Pins → VCC and GND
      
  # Circuit:
  ![circuit2](https://github.com/user-attachments/assets/2055fbf0-3f5b-4264-88a5-06d4c0e81ecc)
  ![smartparking1](https://github.com/user-attachments/assets/0e360d2f-987c-45c9-b8f5-9964da4d5201)
  ![smartparking2](https://github.com/user-attachments/assets/b3795b1d-cf74-4b49-bbac-3d157962018c)







# Software design
 - Development Environment: PlatformIO in Visual Studio Code.
 - Libraries and Third-Party Sources:
    - Servo: For controlling the servo motor (available as Servo in the PlatformIO library registry).
    - LiquidCrystal_I2C: For controlling the LCD (available as LiquidCrystal_I2C in the PlatformIO library registry).

Software Flow:
 - Initialization:
   The serial communication is initialized to monitor the system's status in real-time.
   The LCD screen is initialized and displays a welcoming message for 2 seconds.
   The IR sensors are configured as input to detect vehicles, while the servo motor is attached and set to the initial position (closed gate).

 - Main Logic:
   The program checks the state of the IR sensors (IR1 and IR2) using interrupts. When a vehicle is detected:
   IR1 triggers the vehicle entry action, where the parking slot count decreases and the barrier opens.
   IR2 triggers the vehicle exit action, where the parking slot count increases and the barrier opens.
   Debouncing is implemented to avoid multiple triggers from a single sensor activation.
   The system keeps updating the LCD screen to display the number of available parking spots in real-time.

 - Interrupts:
   AttachInterrupt() is used to capture the IR sensor events with a delay to avoid false triggers.
   The use of interrupts makes the system responsive without constantly polling sensor states, improving efficiency and minimizing the time taken to detect vehicle movements.

 - Servo Control:
   The servo motor is controlled using PWM signals to open and close the parking gate.
   The servo is set to 0 degrees to open the gate and 80 degrees to close it.

 - LCD Display:
   The 16x2 LCD is updated to show real-time data about the number of parking slots left in the system.

# Labs used
- Lab 0 : The project uses GPIO pins for the PIR Sensors, the servo motor and the LCD.
- Lab 1 : USART and Debugging : The code initializes serial communication with Serial.begin(9600), which allows the Arduino to communicate with the computer through the USB port for debugging.
- Lab 3 : The project uses PWM for controlling the servo motor's position.

# Video demo
https://www.youtube.com/shorts/RFlBYcXbam8

# Conclusions
- This Smart Parking System successfully achieves its goal of automating parking space management using Arduino. The system allows for easy tracking of available parking spaces, automates vehicle entry and exit, and provides an intuitive user interface via the LCD display.

# Project Journal
- [04.12.2024]: Started the documentation.
- [20.12.2024]: Hardware section update.
- [08.01.2025]: Final updates.

# Bibliography
- https://www.mpja.com/download/31227sc.pdf
- https://lastminuteengineers.com/pir-sensor-arduino-tutorial/
