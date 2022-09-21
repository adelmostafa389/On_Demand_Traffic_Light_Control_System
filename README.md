# On_Demand_Traffic_Light_Control_System
## Description
Traffic lights are signaling devices positioned at road intersections and pedestrian crossings to control the flow of traffic.
Traffic lights consists of three signals transmitting meaningful information through colors to the cars’ drivers and the pedestrians.
The traffic light colors are red, yellow, and green arranged vertically.
Crosswalk button lets the signal controller know that someone wants to cross the street, so the light signals adjusts, giving the pedestrian enough time to get across.
## Hardware Design
Atmega32 microcontroller is used with three LEDs for cars signals connected on Port A (Green to Pin 0, Yellow to Pin 1 and Red to Pin 2), three other LEDs for pedestrian signals connected on Port B (Green to Pin 0, Yellow to Pin 1 and Red to Pin 2) and one push button connected to INT0 Pin (Port D, Pin 2) for pedestrian. And another one connected to (Port D, Pin 7) for indicating that an error occurred when testing a driver API manually.
## System Flow Chart
![Flowcharts (7)](https://user-images.githubusercontent.com/77577059/191566504-328704b6-7bcd-4574-9577-dc2653d2027e.png)
