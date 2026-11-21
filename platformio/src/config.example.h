#ifndef CONFIG_EXAMPLE_H
#define CONFIG_EXAMPLE_H

// WiFi Configuration
#define WIFI_SSID "YOUR_WIFI_SSID"
#define WIFI_PASS "YOUR_WIFI_PASSWORD"

// API Gateway Configuration
// APIVALE OpenAI-compatible Gateway for DeepSeek models
#define API_BASE_URL "https://apivale.com/v1/chat/completions"
#define API_KEY "sk-your-apivale-key-here"

// Model selection
#define MODEL_NAME "deepseek-chat" // or "deepseek-reasoner"

// Max response tokens to safeguard ESP32 heap memory
#define MAX_RESPONSE_TOKENS 120

#endif // CONFIG_EXAMPLE_H
