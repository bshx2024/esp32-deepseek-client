# ESP32 DeepSeek 物联网客户端 (C++ / MicroPython)

[English](./README.md) | **简体中文**

[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](./LICENSE)
[![API: APIVALE](https://img.shields.io/badge/API-APIVALE-emerald.svg)](https://apivale.com/?utm_source=github&utm_medium=readme_zh&utm_campaign=esp32-deepseek-client)

专为 **ESP32 / ESP32-S3** 微控制器打造的低内存占用 AI 客户端，同时提供 **PlatformIO / Arduino C++** 与 **MicroPython** 两套源码，通过 [APIVALE OpenAI 兼容网关](https://apivale.com/?utm_source=github&utm_medium=readme_zh&utm_campaign=esp32-deepseek-client) 直连 **DeepSeek-V4.1 Flash** 与 **GLM-5.3 Flash**。

## 核心特性

- **防内存溢出设计**：控制 JSON 请求体大小与 `max_tokens` 上限，避免 ESP32 SRAM 分配崩溃。
- **极低 IoT 调用成本**：适合智能家居、语音交互与边缘传感器，实时价格见 [APIVALE 模型定价](https://apivale.com/pricing?utm_source=github&utm_medium=readme_zh&utm_campaign=esp32-deepseek-client)。
- **标准 OpenAI 协议**：无需重型第三方 SDK，直接对接 `https://apivale.com/v1`。

## 开源协议

基于 [MIT License](./LICENSE) 开源。
