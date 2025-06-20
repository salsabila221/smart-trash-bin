# smart-trash-bin: Arduino based smart trash bin that automatically open the lid using ultrasonic sensor and able to sort wet or dry waste inside.

## Description
An Arduino based smart trash bin that opens automatically using ultrasonic sensor and able to sort waste inside using a soil moisture sensor. Designed as a contactless solution, easy waste sorting, and the fun experience to store waste in public areas.

## Features
- Automatic lid opening via ultrasonic proximity detection
- Wet/dry waste sorting using soil moisture sensor
- Contactless and user friendly design

  ### Hardware
  - Trash bin (any size)
  - Two Arduino Uno
  - HC-SR04 ultrasonic sensor
  - Soil moisture sensor
  - Servo motor
  - Jumper wires
  - Breadboard
  - Battery power supply
 
  ## Software
  - Arduino IDE
 
  ## How it works?
  The project uses two Arduino boards to separate tasks for smoother performance:
  1. Arduino A (Lid_Controller): Uses an ultrasonic sensor to detect approaching object or hand. When an object is detected within a specific range, it triggers a servo motor to automatically open the lid
  2. Arduino B (Waste_Sorter): Uses a soil moisture sensor to determine whether the trash is wet or dry. Based on the moisture sensor reading, it can trigger sorting between wet or dry section.
 
  ## Author
  Created by Salsabila Wiryawan
  Computer Science student at Universitas Padjajaran (Class 2025)

