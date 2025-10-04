# Smart Plant Watering System (SPWS)

## Overview

The **Smart Plant Watering System (SPWS)** is an embedded system project that automates the irrigation process for plants. It is designed for educational and practical IoT applications, providing a complete example of real-world automation with microcontroller programming, sensor reading, actuator control, and user interaction. The system is highly configurable and modular, making it easy to adapt to various hardware platforms.

## Features

- **Automatic and Manual Watering Modes**
  - Automatically waters plants based on soil moisture level thresholds.
  - Allows manual watering via a physical button.
- **Sensor Integration**
  - Reads real-time soil moisture and environmental temperature.
- **Actuator Control**
  - Controls a water pump and status LEDs (RGB or three single-color LEDs).
- **User Interaction**
  - Two physical buttons: one to toggle auto/manual mode, another to trigger manual watering.
- **Status Indication**
  - Status LEDs indicate system state: normal, watering, or error.
- **Event Logging**
  - Prints important events and sensor values to the console or user interface.
- **Configurable Parameters**
  - Soil moisture thresholds, maximum watering duration, sensor read intervals, and more.

## Project Structure

- `main.c`  
  Main control loop, system initialization, and high-level logic.
- `config.h`  
  Project constants, enums, and struct definitions for settings, sensor data, and system state.
- `spws_controller.c/.h`  
  Core logic for auto and manual modes, and mode switching.
- `hal_sensors.c/.h`  
  Hardware Abstraction Layer for reading sensors (soil moisture, temperature).
- `hal_actuators.c/.h`  
  HAL for controlling the pump and LEDs.
- `hal_buttons.c/.h`  
  HAL for reading the status of physical buttons.

## Getting Started

1. **Clone the repository.**
2. **Configure hardware connections** according to your microcontroller and sensors.
3. **Build and upload the firmware** using your favorite IDE or toolchain.
4. **Monitor the system via console output** for status and debugging.

## Simulation & Testing

- The project includes mock HAL functions for desktop simulation.
- You can run the code on your PC for logic testing before deploying to real hardware.
- Adjust sensor values and timing in the simulation to observe system response.

## How It Works

- The system starts in AUTO mode and reads sensor data periodically.
- If soil moisture drops below the minimum threshold, the pump turns on.
- Pump turns off when moisture exceeds the upper threshold or maximum watering time is reached.
- Pressing Button 1 toggles between AUTO and MANUAL modes.
- In MANUAL mode, pressing Button 2 triggers a single watering cycle for a preset duration.
- LEDs reflect the current system state (normal, watering, error).

## Customization

- Change thresholds, timing, and logic in `config.h` to fit your specific application.
- Replace mock HAL functions with real hardware drivers for deployment.

## License

This project is for educational and non-commercial use.

---

**Author:**  
[Your Name or Team]  