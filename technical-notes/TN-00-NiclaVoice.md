# Technical Note – Read Nicla Voice Board Documentation

**Reference:** Issue #2 
**Date:** 2025-05-08  
**Status:** Completed  
**Author:** Lise R.

## Objective

Understand the capabilities, components, and I/O features of the Arduino Nicla Voice board in order to assess its suitability for audio-based bird species recognition using TinyML.

---

## Summary

Key features extracted from the datasheet:
- Neural Decision Processor: Syntiant® NDP120, supports always-on inference for audio.
- Main MCU: nRF52832 (64 MHz Cortex-M4F, 512 KB Flash).
- Microphone: IM69D130 (high-quality PDM MEMS mic).
- Sensors: 6-axis IMU (BMI270) + 3-axis magnetometer (BMM150).
- Interfaces: SPI, I2C, ADC, UART, GPIO, USB.
- Power: Ultra-low power, with integrated battery charger for 3.7V LiPo.
- Compatible with Arduino IDE and Edge Impulse.
- External mic connector (J6), ESLOV connector (J5) for easy peripheral expansion.

---

## Analysis

- The onboard NDP120 is a major advantage for deploying quantized audio models like BirdNET or custom CNNs without overloading the main MCU.
- Power-efficient design makes the board suitable for field deployment in nature reserves.
- The PDM interface matches BirdNET’s audio input requirements.
- Multiple interfaces and I/O allow expansion with other sensors (e.g., temperature, light) for future multimodal monitoring.

---

## Open Questions

- Is the onboard microphone sufficient for detecting distant bird calls in open environments?
- What is the maximum supported model size for the NDP120?
- How to upload a model from Edge Impulse or convert it manually for the NDP SDK?

---

## Next Steps

- Document the NDP120 model deployment pipeline (from TFLite to Syntiant format).
- Test basic audio acquisition on Nicla Voice with Arduino IDE or Edge Impulse.
- Cross-reference with BirdNET's input format to align pipeline specs.

---

## References

- Arduino Nicla Voice Datasheet – [Arduino Pro Docs](https://docs.arduino.cc/hardware/nicla-voice)
- Syntiant NDP120 SDK Overview – [Syntiant](https://www.syntiant.com/ndp120)
- IM69D130 Microphone Datasheet – [Infineon](https://www.infineon.com/cms/en/product/sensor/mems-microphones/im69d130/)
