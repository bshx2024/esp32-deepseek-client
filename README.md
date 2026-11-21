# ESP32 DeepSeek Client

A lightweight, memory-efficient C++ (PlatformIO / Arduino) and MicroPython client for connecting ESP32 microcontrollers to DeepSeek models via APIVALE.

## Key Features

- **Heap Memory Protection**: Employs `max_tokens` throttling to keep HTTP payload buffers compact (< 1 KB), preventing ESP32 SRAM allocation panics.
- **MicroPython & C++ Support**: Includes both native MicroPython (`urequests` + manual `gc.collect()`) and Arduino/PlatformIO (`WiFiClientSecure` + `ArduinoJson 7`).
- **OpenAI-Compatible Gateway**: Direct drop-in configuration for `apivale.com/v1`, eliminating the need for complex custom SDKs.

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
└── micropython/
    ├── config.example.py
    ├── deepseek_client.py
    └── main.py
```

## Quick Start (PlatformIO)

1. Clone this repository or use it as a template:
   ```bash
   git clone https://github.com/bshx2024/esp32-deepseek-client.git
   cd esp32-deepseek-client/platformio
   ```
2. Copy `src/config.example.h` to `src/config.h` and update your WiFi and API credentials:
   ```cpp
   #define WIFI_SSID "Your_SSID"
   #define WIFI_PASS "Your_Password"
   #define API_KEY   "sk-your-apivale-key"
   ```
3. Build and upload to your ESP32 board:
   ```bash
   pio run -t upload && pio devicemonitor
   ```

## Quick Start (MicroPython)

1. Connect your ESP32 via USB and open Thonny IDE.
2. Upload `deepseek_client.py`, `config.example.py` (renamed to `config.py`), and `main.py` to the ESP32 root directory.
3. Run `main.py` to verify prompt inference.

## Community & Referral Setup

If you are sharing this project in developer communities or forums:
- You can fork this repository to your own GitHub account.
- In your fork's `config.example.h`, you may include your community invite code or referral link in the comments so other builders receive bonus trial tokens upon registration.

## License

MIT License.
