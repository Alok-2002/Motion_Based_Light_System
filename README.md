# Motion-Based Smart Lighting System

## 📌 Project Overview
The **Motion-Based Smart Lighting System** is designed to optimize energy usage by turning on lights **only in occupied zones** using ultrasonic sensors. This system is ideal for large spaces like **conference halls, offices, or warehouses**, where lights should be controlled based on movement in different areas.

## 🚀 Features
- **Zone-Based Lighting**: Lights turn on only in the zones where motion is detected.
- **Multiple Ultrasonic Sensors**: Uses multiple **HC-SR04** sensors for motion detection.
- **Energy Efficient**: Automatically turns off lights when no motion is detected.
- **Arduino-Based Control**: Uses an **Arduino Uno/Mega** for processing.
- **Relay-Based Light Switching**: Controls AC/DC lights efficiently.

## 🛠️ Components Required
1. **Arduino Uno/Mega** (depending on the number of sensors)
2. **HC-SR04 Ultrasonic Sensors** (one for each zone)
3. **Relay Module** (one per light/zone)
4. **Jumper Wires**
5. **Power Supply (5V/12V for relays and sensors)**
6. **Shielded Cables (for long-distance sensor connections)**

## 🔧 How It Works
1. Each **ultrasonic sensor** continuously measures distance.
2. If a person is detected within a **10 cm range**, the system identifies which zone is occupied.
3. The system turns **on the light** corresponding to that zone.
4. If no motion is detected for a certain period, the light **turns off** automatically.

## 📑 Code Explanation
- **`ultra_read()`**: Reads distance from the ultrasonic sensor.
- **People Counting Logic**: Uses sensor flags to determine movement direction.
- **Relay Control**: Activates or deactivates lights based on occupancy.

## 🔌 Setup Instructions
1. **Connect the Sensors & Relays**:
   - Echo & Trigger pins to Arduino I/O pins.
   - Relay modules to respective light circuits.
2. **Upload the Code to Arduino**:
   - Use the Arduino IDE and select the correct board & port.
3. **Power Up & Test**:
   - Observe lights turning on/off based on movement.

## 📝 Future Improvements
- 📡 **Wireless Communication** (ESP8266/ESP32 for cloud-based monitoring)
- 🏢 **Integration with Smart Home Systems** (Google Home, Alexa, etc.)
- 🔄 **Adaptive Thresholding** (Dynamic sensitivity adjustment based on room conditions)

## 🤝 Contributing
Feel free to fork this repository, raise issues, or contribute enhancements! 🎉

## 📜 License
This project is open-source under the **MIT License**.

---
⚡ *Developed with a vision for smart and energy-efficient spaces!*

