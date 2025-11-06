# 🔥 ESP32-S3 Gas Leak Detection System

An *Gas leak detection system* built using an *ESP32-S3*, *MQ-2 gas sensor*, *LED indicators*, and a *buzzer*.  
This project monitors gas concentration levels and provides visual and audible alerts based on the gas intensity.

---

## ⚙ Features

- 🕐 *Automatic warm-up delay* for MQ-2 sensor (2 minutes)
- 💡 *Three-stage LED indication*
  - 🟢 Green — Safe
  - 🟡 Yellow + Buzzer — Warning
  - 🔴 Red + Buzzer — Danger
- 🔔 *Audible alerts* using buzzer tones
- 📟 *Serial monitor feedback* for gas level status and sensor countdown
- ⚡ Designed for *ESP32-S3* compatibility

---

## 🧠 How It Works

1. When powered on, the system waits for *120 seconds* to allow the MQ-2 sensor to heat up.  
   During this time, all LEDs remain *ON* to indicate warm-up.

2. After warm-up:
   - If gas level < 630 → 🟢 Safe  
   - If gas level between 630 and 1600 → 🟡 Warning + short buzzer tone  
   - If gas level ≥ 1600 → 🔴 Alert + continuous buzzer tone  

3. Real-time data is printed to the *Serial Monitor*.

---

## 🧰 Components Used

| Component        | Quantity | Description |
|------------------|-----------|-------------|
| ESP32-S3         | 1 | Microcontroller |
| MQ-2 Gas Sensor  | 1 | Detects LPG and methane |
| Buzzer           | 1 | Alarm indicator |
| Green LED        | 1 | Safe status |
| Yellow LED       | 1 | Warning status |
| Red LED          | 1 | Alert status |

---

## 🪜 Circuit Connections

| ESP32-S3 Pin | Component      | Description |
|---------------|----------------|--------------|
| GPIO 19 | Green LED | Safe indicator |
| GPIO 20 | Yellow LED | Warning indicator |
| GPIO 21 | Red LED | Alert indicator |
| GPIO 47 | Buzzer | Sound alarm |
| GPIO 7  | MQ-2 Sensor (A0) | Analog input |

---
