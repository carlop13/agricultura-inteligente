# 🌱 Gotita de Agua

**IoT-based Smart Irrigation System — UTEQ Winner 🏆**

Gotita de Agua is an automated irrigation system developed as an IoT project at **Universidad Tecnológica de Querétaro (UTEQ)**.

The system monitors soil moisture using a sensor connected to an **ESP32** and automatically controls a water pump through a relay. Sensor readings and irrigation status are synchronized with **Firebase Realtime Database**, while an OLED display provides real-time information directly on the device.

## 🎥 Demo

[![Gotita de Agua — Smart Irrigation System](https://www.youtube.com/watch?v=Qu7RhS2lDTw/maxresdefault.jpg)](https://www.youtube.com/watch?v=Qu7RhS2lDTw)

**Watch the complete demonstration on YouTube.**

## 📚 Documentation

https://drive.google.com/file/d/1c03cZ84FM6ImIAKnkYTmsywKvJhaVCj8/view?usp=sharing

## ⚙️ Technologies

* 🔌 ESP32
* 🤖 Arduino
* 💧 Soil Moisture Sensor
* ⚡ Relay Module
* 📺 OLED SSD1306
* ☁️ Firebase Realtime Database
* 📡 Wi-Fi
* 💻 C++ / Arduino

## 🔧 How It Works

The ESP32 continuously reads the soil moisture level through an analog sensor.

The system then:

1. Reads the soil moisture level.
2. Connects to the local Wi-Fi network.
3. Communicates with Firebase Realtime Database.
4. Retrieves the irrigation status.
5. Activates or deactivates the water pump through a relay.
6. Displays the current status and moisture level on the OLED screen.
7. Stores moisture readings in Firebase.

### 💧 Irrigation Logic

When the soil moisture reaches the configured threshold and irrigation is enabled, the relay activates the water pump.

```text
Soil Moisture Sensor
        │
        ▼
      ESP32
        │
   ┌────┴─────┐
   ▼          ▼
Firebase    OLED Display
   │
   ▼
Irrigation Status
   │
   ▼
  Relay
   │
   ▼
Water Pump
```

## 📚 Required Libraries

The following Arduino libraries are required:

* `ArduinoJson` — version **5.13.1**
* `FirebaseESP32`
* `Adafruit GFX Library`
* `Adafruit SSD1306`

The project also uses the following standard libraries:

* `WiFi`
* `SPI`
* `Wire`

## 🚀 Installation

### 1. Clone the repository

```bash
git clone https://github.com/carlop13/agricultura-inteligente.git
```

### 2. Open the project

Open `GotitaDeAgua.ino` using the **Arduino IDE**.

### 3. Install the required libraries

Install the required dependencies through the Arduino IDE Library Manager.

Make sure to use:

```text
ArduinoJson 5.13.1
```

### 4. Configure your credentials

Before uploading the program to the ESP32, replace the placeholder values in the source code with your own configuration:

```cpp
#define FIREBASE_HOST "YOUR_FIREBASE_HOST"
#define FIREBASE_AUTH "YOUR_FIREBASE_AUTH"
#define WIFI_SSID "YOUR_WIFI_SSID"
#define WIFI_PASSWORD "YOUR_WIFI_PASSWORD"
```

> ⚠️ Never commit real Wi-Fi passwords, Firebase credentials, API keys, or other secrets to a public repository.

### 5. Upload to the ESP32

Select the appropriate ESP32 board and port in Arduino IDE, then upload the program.

## 📟 Hardware

The project uses:

* ESP32
* Soil moisture sensor
* Relay module
* Water pump
* OLED SSD1306 128×32 display
* Appropriate power supply
* Irrigation tubing and water container

## 🏆 Project Recognition

**Gotita de Agua** was developed as an academic IoT project at:

**Universidad Tecnológica de Querétaro (UTEQ)**

🏆 **UTEQ Winner**

The project combines IoT, embedded systems, cloud connectivity, and automated irrigation to create a smart agriculture solution.

## 👨‍💻 Author

**Carlos López**

GitHub: [@carlop13](https://github.com/carlop13)

## 📄 License

This project was developed for educational and academic purposes.
