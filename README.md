# Laptop Distance and Posture Alert System

An Arduino-based system that monitors the user's distance from a laptop using an HC-SR04 ultrasonic sensor and provides progressive audio warnings through a passive buzzer.

## Project Overview

This project is a real-time laptop distance and posture alert system built using an Arduino UNO R4 Minima and an HC-SR04 ultrasonic sensor.

The ultrasonic sensor continuously measures the distance between the user and the laptop. The measured distance is used as an indication of whether the user is sitting at an appropriate distance from the screen.

A passive buzzer provides progressive audio feedback based on the user's distance. As the user moves closer to the laptop, the buzzer's beep rate increases, providing an increasingly urgent warning. When the user moves back to a safe distance, the buzzer automatically stops.

The project was developed as a hands-on application of ultrasonic distance measurement, real-time sensor monitoring, timing control, and human-machine feedback using Arduino.

## Objectives

- Continuously measure the user's distance from the laptop using an HC-SR04 ultrasonic sensor.
- Use distance as an indicator of excessive proximity to the screen.
- Provide real-time audio feedback using a passive buzzer.
- Increase the buzzer's beep rate as the user moves closer.
- Automatically stop the warning when the user moves back to a safe distance.
- Gain practical experience with ultrasonic sensors, pulseIn(), tone(), millis(), and real-time embedded-system logic.

## Features

- Real-time distance measurement
- Progressive distance-based buzzer warning
- Constant 3000 Hz buzzer tone
- Variable beep rate based on distance
- Non-blocking buzzer timing using millis()
- Ultrasonic sensor timeout handling
- Automatic warning adjustment as distance changes

## Components Used

| Component | Quantity | Purpose |
|---|---:|---|
| Arduino UNO R4 Minima | 1 | Main controller |
| HC-SR04 Ultrasonic Sensor | 1 | Distance measurement |
| Passive Buzzer | 1 | Audio warning |
| Jumper Wires | — | Electrical connections |

## Pin Configuration

| Arduino Pin | Connected To |
|---|---|
| D8 | HC-SR04 TRIG |
| D9 | HC-SR04 ECHO |
| D11 | Passive Buzzer |
| 5V | HC-SR04 VCC |
| GND | HC-SR04 GND and Buzzer GND |

## Working Principle

The HC-SR04 ultrasonic sensor sends an ultrasonic pulse and measures the time taken for the reflected pulse to return.

The Arduino calculates the distance using the measured echo time.

Distance = (Echo Time × 0.0343) / 2

The calculated distance is then compared with predefined thresholds. Based on the measured distance, the Arduino selects an appropriate buzzer interval.

The buzzer operates at a constant tone frequency of 3000 Hz. Only the time between beeps changes.

### Distance-Based Alert Logic

| Distance | Warning Level | Buzzer Behavior |
|---|---|---|
| > 45 cm | Safe | Silent |
| > 40 to 45 cm | Initial Warning | Slow beep - 1000 ms interval |
| > 36 to 40 cm | Increased Warning | Faster beep - 400 ms interval |
| <= 36 cm | High Warning | Very fast beep - 100 ms interval |

As the user moves closer to the laptop, the time between beeps decreases, creating a progressively stronger warning.

## Software Design

The program follows this sequence:

    Measure Distance
           ↓
    Calculate Distance
           ↓
    Check Distance Range
           ↓
    Select Beep Interval
           ↓
    Control Passive Buzzer
           ↓
    Measure Again

The pulseIn() function is used to measure the ultrasonic echo time.

The tone() and noTone() functions control the passive buzzer.

The millis() function is used to control the beep timing without blocking continuous sensor monitoring.

A 15 ms timeout is used for the ultrasonic echo measurement. If no valid echo is received, the buzzer is turned off.

## Prototype

The ultrasonic sensor was positioned above the laptop screen to measure the distance between the user and the laptop. The Arduino and passive buzzer were connected to the sensor for real-time warning feedback.

Prototype images are available in the "Photos and videos" folder.

## Circuit Diagram

The circuit consists of the HC-SR04 ultrasonic sensor and passive buzzer connected to the Arduino UNO R4 Minima.

The circuit diagram is available in the "Documentation" folder.

## Source Code

The complete Arduino source code is available in the source-code folder.

The program continuously measures the user's distance and dynamically changes the buzzer's beep interval according to the measured distance.

## Documentation

Detailed project documentation is available in the "Documentation" folder.

The documentation includes:

- Project overview
- Objectives
- Components used
- System architecture
- Circuit diagram
- Pin configuration
- Working principle
- Distance-based alert logic
- Software design
- Limitations
- Future improvements
- What I learned
- Complete Arduino source code
- References

## Limitations

- The system uses distance as an indirect indication of posture and does not directly analyze body posture.
- Ultrasonic measurements can fluctuate depending on the user's position, movement, clothing, and surrounding objects.
- The HC-SR04 has a limited sensing range and field of view.
- The system currently provides only audio feedback.
- Warning intensity is controlled by changing the beep rate rather than the actual volume.
- The system cannot distinguish between the user and other objects within the sensor's detection area.

## Future Improvements

- Add an OLED display to show measured distance and warning status.
- Add visual indicators such as LEDs.
- Add a calibration system for different users and desk setups.
- Implement more advanced posture detection using multiple sensors.
- Add data logging to track sitting distance over time.
- Add wireless connectivity for monitoring and notifications.
- Design a compact enclosure and proper mounting mechanism for the sensor.
- Improve distance filtering to reduce ultrasonic measurement fluctuations.

## What I Learned

Through this project, I gained practical experience in:

- Interfacing an HC-SR04 ultrasonic sensor with Arduino
- Measuring distance using ultrasonic echo timing
- Working with pulseIn() and sensor timeouts
- Controlling a passive buzzer using tone() and noTone()
- Using millis() for non-blocking timing
- Designing distance-based alert logic
- Testing and tuning distance thresholds
- Understanding blocking and non-blocking program logic
- Integrating hardware and software into a real-time interactive system

## References

- Arduino documentation
- HC-SR04 ultrasonic sensor documentation/datasheet
- Arduino tone() and noTone() documentation
- Arduino millis() documentation
- Online Arduino tutorials used as initial references

The initial concept and sensor implementation were inspired by online Arduino tutorials. The distance-based warning logic and progressive buzzer behavior were developed and modified for this project.
