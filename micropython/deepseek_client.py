import gc
import ujson as json
import urequests as requests

class DeepSeekClient:
    def __init__(self, api_key, base_url="https://apivale.com/v1/chat/completions", model="deepseek-chat"):
        self.api_key = api_key
        self.base_url = base_url
        self.model = model

    def query(self, prompt, system_prompt="Concise IoT assistant. Reply in <= 2 sentences.", max_tokens=120):
        # Force garbage collection to reclaim heap before TLS allocation
        gc.collect()

        headers = {
            "Content-Type": "application/json",
            "Authorization": "Bearer " + self.api_key
        }

        payload = {
            "model": self.model,
            "messages": [
                {"role": "system", "content": system_prompt},
                {"role": "user", "content": prompt}
            ],
            "max_tokens": max_tokens,
            "temperature": 0.3
        }

        response = None
        try:
            response = requests.post(self.base_url, headers=headers, data=json.dumps(payload))
            if response.status_code == 200:
                result = response.json()
                return result["choices"][0]["message"]["content"]
            else:
                print("HTTP Error:", response.status_code, response.text)
                return None
        except Exception as e:
            print("Request exception:", e)
            return None
        finally:
            if response:
                response.close()
            gc.collect()
