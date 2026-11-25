# ESP32 DeepSeek & Qwen IoT Client

**English** | [简体中文](./README.zh-CN.md)

[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](./LICENSE)
[![Hardware: ESP32](https://img.shields.io/badge/Hardware-ESP32%20%7C%20ESP32--S3-blue.svg)](./platformio)
[![API: APIVALE](https://img.shields.io/badge/API-APIVALE%20OpenAI%20Compatible-emerald.svg)](https://apivale.com/?utm_source=github&utm_medium=readme&utm_campaign=esp32-deepseek-client)

A lightweight, SRAM-safe **C++ (PlatformIO / Arduino)** and **MicroPython** client for connecting ESP32 microcontrollers to **DeepSeek-V4.1 Flash**, **Qwen 3.8 Max**, and **GLM-5.3 Flash** via the [APIVALE OpenAI-Compatible Gateway](https://apivale.com/?utm_source=github&utm_medium=readme&utm_campaign=esp32-deepseek-client).

## Key Features

- **Heap Memory Protection**: Enforces compact JSON payloads (`< 1 KB`) and `max_tokens` throttling to prevent ESP32 SRAM allocation panics.
- **Dual Runtime Support**: Ready-to-flash code for both **PlatformIO / Arduino** (`WiFiClientSecure` + `ArduinoJson 7`) and **MicroPython** (`urequests` + explicit `gc.collect()`).
- **Low-Cost Flash Model Routing**: Ideal for voice assistants, smart home sensors, and edge IoT triggers — view token costs on the [APIVALE Pricing Page](https://apivale.com/pricing?utm_source=github&utm_medium=readme&utm_campaign=esp32-deepseek-client).

## Directory Structure

```text
├── arduino/
│   └── esp32_deepseek_basic/
│       ├── esp32_deepseek_basic.ino
│       └── config.example.h
├── platformio/
│   ├── platformio.ini
│   └── src/
│       ├── config.example.h
│       └── main.cpp
├── micropython/
│   ├── config.example.py
│   ├── deepseek_client.py
│   └── main.py
├── LICENSE
├── README.md
└── README.zh-CN.md
```

## Quick Start (PlatformIO)

1. Clone this repository:
   ```bash
   git clone https://github.com/bshx2024/esp32-deepseek-client.git
   cd esp32-deepseek-client/platformio
   ```
2. Copy `src/config.example.h` to `src/config.h` and set your Wi-Fi credentials plus your API key from [APIVALE](https://apivale.com/?utm_source=github&utm_medium=readme&utm_campaign=esp32-deepseek-client):
   ```cpp
   #define WIFI_SSID "Your_SSID"
   #define WIFI_PASS "Your_Password"
   #define API_KEY   "sk-your-apivale-key"
   ```
3. Build & flash:
   ```bash
   pio run -t upload && pio device monitor
   ```

## Quick Start (MicroPython)

1. Flash MicroPython onto your ESP32 board and open Thonny IDE.
2. Rename `micropython/config.example.py` to `config.py`, insert your `https://apivale.com/v1` key, and upload `deepseek_client.py`, `config.py`, and `main.py`.

See the [APIVALE Technical Blog](https://apivale.com/blog/?utm_source=github&utm_medium=readme&utm_campaign=esp32-deepseek-client) for low-latency Flash model selection guides.

## License

Released under the [MIT License](./LICENSE).
