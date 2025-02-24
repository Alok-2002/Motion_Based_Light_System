# Motion-Based Smart Lighting System

## 📌 Project Overview

The **Motion-Based Smart Lighting System** is designed to optimize energy usage by turning on lights **only in occupied zones** using ultrasonic sensors. This system is ideal for large spaces like **conference halls, offices, or warehouses**, where lights should be controlled based on movement in different areas. The system also features **bidirectional people counting**, allowing accurate tracking of entry and exit movements to manage lighting accordingly.

## Table of Contents

- [Project Overview](#project-overview)
- [Features](#features)
- [Hardware Requirements](#hardware-requirements)
- [Software Requirements](#software-requirements)
- [Circuit Diagram](#circuit-diagram)
- [Installation and Setup](#installation-and-setup)
- [Usage](#usage)
- [Future Improvements](#future-improvements)
- [Contributing](#contributing)
- [License](#license)
- [Acknowledgments](#acknowledgments)

## 🚀 Features

- **Zone-Based Lighting**: Lights turn on only in the zones where motion is detected.
- **Multiple Ultrasonic Sensors**: Uses multiple **HC-SR04** sensors for precise motion detection.
- **Energy Efficient**: Automatically turns off lights when no motion is detected.
- **Arduino-Based Control**: Uses an **Arduino Uno/Mega** for processing.
- **Relay-Based Light Switching**: Controls AC/DC lights efficiently.
- **Bidirectional People Counting**: Accurately counts the number of people entering and exiting the room.
- **Real-time Monitoring**: Outputs sensor readings and occupancy status to the serial monitor for debugging.

## 🛠️ Hardware Requirements

1. **Arduino Uno/Mega** (depending on the number of sensors)
2. **HC-SR04 Ultrasonic Sensors** (one for each zone)
3. **Relay Module** (one per light/zone)
4. **Jumper Wires**
5. **Power Supply (5V/12V for relays and sensors)**
6. **Shielded Cables** (for long-distance sensor connections)

## 💻 Software Requirements

- Arduino IDE
- [Motion_Based_Light_System Code](https://github.com/Alok-2002/Motion_Based_Light_System/tree/main/Code.ino)

## 🔧 How It Works

1. **Each ultrasonic sensor continuously measures distance.**
2. **Motion Detection**: If a person is detected within a **10 cm range**, the system identifies which zone is occupied.
3. **Light Activation**: The system turns **on the light** corresponding to that zone.
4. **Automatic Deactivation**: If no motion is detected for a certain period, the light **turns off** automatically.
5. **People Counting**: The system uses sensor flags to determine movement direction, increasing or decreasing the occupancy count accordingly.
6. **Relay Control**: Activates or deactivates lights based on occupancy.

## 📑 Circuit Diagram

*Note: Include a detailed circuit diagram here to assist users in assembling the hardware components correctly.*

## 🔌 Installation and Setup

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/Alok-2002/Motion_Based_Light_System.git
   ```
2. **Open the Code**:
   - Launch the Arduino IDE.
   - Navigate to `File` > `Open` and select the `Motion_Based_Light_System.ino` file from the cloned repository.

3. **Connect the Hardware**:
   - Assemble the components as per the circuit diagram.
   - Connect the Arduino to your computer via USB.

4. **Upload the Code**:
   - In the Arduino IDE, select the appropriate board and port from the `Tools` menu.
   - Click the upload button to program the Arduino.

5. **Power Up and Test**:
   - Observe lights turning on/off based on movement.
   - Monitor the serial output for real-time status updates.

## 📝 Future Improvements

- 📡 **Wireless Communication** (ESP8266/ESP32 for cloud-based monitoring)
- 🏢 **Integration with Smart Home Systems** (Google Home, Alexa, etc.)
- 🔄 **Adaptive Thresholding** (Dynamic sensitivity adjustment based on room conditions)

## 🤝 Contributing

Contributions are welcome! To contribute:
1. Fork the repository.
2. Create a new branch: `git checkout -b feature-branch-name`
3. Make your changes and commit them: `git commit -m 'Add new feature'`
4. Push to the branch: `git push origin feature-branch-name`
5. Submit a pull request detailing your changes.

## 📜 License

This project is open-source under the **MIT License**.

## 🙌 Acknowledgments

- Thanks to [Alok-2002](https://github.com/Alok-2002) for the initial project setup and codebase.
- Inspired by various motion-sensing lighting projects and tutorials available in the open-source community.

---
⚡ *Developed with a vision for smart and energy-efficient spaces!*

