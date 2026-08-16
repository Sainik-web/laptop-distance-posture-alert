\# Laptop Distance and Posture Alert System



An Arduino-based system that monitors the user's distance from a laptop using an HC-SR04 ultrasonic sensor and provides progressive audio warnings through a passive buzzer.



\## Project Overview



This project is a real-time laptop distance and posture alert system built using an Arduino UNO R4 Minima and an HC-SR04 ultrasonic sensor.



The ultrasonic sensor continuously measures the distance between the user and the laptop. The measured distance is used as an indication of whether the user is sitting at an appropriate distance from the screen.



A passive buzzer provides progressive audio feedback based on the user's distance. As the user moves closer to the laptop, the buzzer's beep rate increases, providing an increasingly urgent warning. When the user moves back to a safe distance, the buzzer automatically stops.



The project was developed as a hands-on application of ultrasonic distance measurement, real-time sensor monitoring, timing control, and human-machine feedback using Arduino.



\## Objectives



\- Continuously measure the user's distance from the laptop using an HC-SR04 ultrasonic sensor.

\- Use distance as an indicator of excessive proximity to the screen.

\- Provide real-time audio feedback using a passive buzzer.

\- Increase the buzzer's beep rate as the user moves closer.

\- Automatically stop the warning when the user moves back to a safe distance.

\- Gain practical experience with ultrasonic sensors, `pulseIn()`, `tone()`, `millis()`, and real-time embedded-system logic.



\## Features



\- Real-time distance measurement

\- Progressive distance-based buzzer warning

\- Constant 3000 Hz buzzer tone

\- Variable beep rate based on distance

\- Non-blocking buzzer timing using `millis()`

\- Ultrasonic sensor timeout handling

\- Automatic warning adjustment as distance changes



\## Components Used



| Component | Quantity | Purpose |

|---|---:|---|

| Arduino UNO R4 Minima | 1 | Main controller |

| HC-SR04 Ultrasonic Sensor | 1 | Distance measurement |

| Passive Buzzer | 1 | Audio warning |

| Jumper Wires | — | Electrical connections |



\## Pin Configuration



| Arduino Pin | Connected To |

|---|---|

| D8 | HC-SR04 TRIG |

| D9 | HC-SR04 ECHO |

| D11 | Passive Buzzer |

| 5V | HC-SR04 VCC |

| GND | HC-SR04 GND and Buzzer GND |



\## Working Principle



The HC-SR04 ultrasonic sensor sends an ultrasonic pulse and measures the time taken for the reflected pulse to return.



The Arduino calculates the distance using the measured echo time:



\*\*Distance = (Echo Time × 0.0343) / 2\*\*



The calculated distance is then compared with predefined thresholds. Based on the measured distance, the Arduino selects an appropriate buzzer interval.



The buzzer operates at a constant tone frequency of 3000 Hz. Only the time between beeps changes.



\### Distance-Based Alert Logic



| Distance | Warning Level | Buzzer Behavior |

|---|---|---|

| > 45 cm | Safe | Silent |

| > 40 to 45 cm | Initial Warning | Slow beep - 1000 ms interval |

| > 36 to 40 cm | Increased Warning | Faster beep - 400 ms interval |

| <= 36 cm | High Warning | Very fast beep - 100 ms interval |



As the user moves closer to the laptop, the time between beeps decreases, creating a progressively stronger warning.



\## Software Design



The program follows this basic sequence:



```text

Measure Distance

&#x20;      ↓

Calculate Distance

&#x20;      ↓

Check Distance Range

&#x20;      ↓

Select Beep Interval

&#x20;      ↓

Control Passive Buzzer

&#x20;      ↓

Measure Again

