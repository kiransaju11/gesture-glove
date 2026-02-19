# 🖐️ Gesture Glove using ESP32

A wearable gesture recognition system using flex sensors and ESP32.

## 📌 Overview

This project reads analog values from 5 flex sensors attached to a glove and processes the data to detect hand gestures.

The ESP32 samples sensor values over a fixed duration and compares them with predefined thresholds to identify finger movements.

---

## 🛠 Hardware Used

- ESP32
- 5 Flex Sensors
- Resistors (voltage divider setup)
- Glove
- Jumper wires
- Power supply

---

## 🔌 Pin Configuration

| Sensor | ESP32 Pin |
|--------|-----------|
| Finger 1 | 32 |
| Finger 2 | 33 |
| Finger 3 | 34 |
| Finger 4 | 35 |
| Finger 5 | 36 |

---

## ⚙️ How It Works

1. ESP32 initializes analog pins.
2. It captures sensor data for 5 seconds.
3. Samples are averaged.
4. Values are compared with threshold values.
5. Gesture is determined based on finger bend pattern.

---

## 🧠 Future Improvements

- Machine Learning based gesture classification
- Wireless communication (Bluetooth/WiFi)
- IR remote control integration
- Real-time streaming to server

---

## 📷 Applications

- Sign language recognition
- Remote device control
- Robotics hand control
- Smart home control

---

## 👨‍💻 Author

Kiran Saju  
BTech ECE  
