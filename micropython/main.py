import network
import time
from deepseek_client import DeepSeekClient
from config import WIFI_SSID, WIFI_PASS, API_KEY, MODEL_NAME

def connect_wifi():
    wlan = network.WLAN(network.STA_IF)
    wlan.active(True)
    if not wlan.isconnected():
        print("Connecting to WiFi...")
        wlan.connect(WIFI_SSID, WIFI_PASS)
        for _ in range(20):
            if wlan.isconnected():
                break
            time.sleep(0.5)
    print("Connected, IP:", wlan.ifconfig()[0])

def run():
    connect_wifi()
    client = DeepSeekClient(api_key=API_KEY, model=MODEL_NAME)
    print("Querying DeepSeek...")
    reply = client.query("Telemetry: Motor current spike 14.2A, duration 200ms. Analyze risk.")
    print("DeepSeek Analysis:\n", reply)

if __name__ == "__main__":
    run()
