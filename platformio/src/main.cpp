#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <WiFiClientSecure.h>
#include <ArduinoJson.h>
#include "config.example.h"

void connectWiFi() {
    Serial.printf("Connecting to %s", WIFI_SSID);
    WiFi.begin(WIFI_SSID, WIFI_PASS);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.printf("\nWiFi connected! IP: %s\n", WiFi.localIP().toString().c_str());
}

String queryDeepSeek(const String& userPrompt) {
    if (WiFi.status() != WL_CONNECTED) {
        Serial.println("WiFi not connected!");
        return "";
    }

    WiFiClientSecure client;
    client.setInsecure(); // Skip root CA verification for simplicity
    client.setTimeout(15000); // 15s timeout

    HTTPClient http;
    if (!http.begin(client, API_BASE_URL)) {
        Serial.println("Failed to connect to gateway");
        return "";
    }

    http.addHeader("Content-Type", "application/json");
    http.addHeader("Authorization", String("Bearer ") + API_KEY);
    http.addHeader("Connection", "close");

    // Construct JSON payload using ArduinoJson
    JsonDocument doc;
    doc["model"] = MODEL_NAME;
    doc["max_tokens"] = MAX_RESPONSE_TOKENS;
    doc["temperature"] = 0.3;

    JsonArray messages = doc["messages"].to<JsonArray>();
    
    JsonObject sysMsg = messages.add<JsonObject>();
    sysMsg["role"] = "system";
    sysMsg["content"] = "You are a concise embedded IoT telemetry assistant. Keep response under 2 sentences.";

    JsonObject userMsg = messages.add<JsonObject>();
    userMsg["role"] = "user";
    userMsg["content"] = userPrompt;

    String requestBody;
    serializeJson(doc, requestBody);

    Serial.printf("[DeepSeek] Sending prompt: %s\n", userPrompt.c_str());
    int httpCode = http.POST(requestBody);
    String responseText = "";

    if (httpCode == HTTP_CODE_OK) {
        String payload = http.getString();
        JsonDocument respDoc;
        DeserializationError err = deserializeJson(respDoc, payload);
        if (!err) {
            const char* content = respDoc["choices"][0]["message"]["content"];
            if (content) {
                responseText = String(content);
            }
        } else {
            Serial.printf("JSON parse failed: %s\n", err.c_str());
        }
    } else {
        Serial.printf("HTTP request failed, code: %d, error: %s\n", httpCode, http.errorToString(httpCode).c_str());
    }

    http.end();
    return responseText;
}

void setup() {
    Serial.begin(115200);
    delay(1000);
    Serial.println("\n=== ESP32 DeepSeek Client Initialized ===");

    connectWiFi();

    // Sample diagnostic prompt
    String diagnosis = queryDeepSeek("Sensor reading: Temp=84.2C, Vibration=Normal. Evaluate thermal status.");
    Serial.println("\n--- Gateway Diagnosis Result ---");
    Serial.println(diagnosis);
}

void loop() {
    delay(10000);
}
