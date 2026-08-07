
<img width="574" height="706" alt="Screenshot 2026-08-05 at 6 15 05 PM" src="https://github.com/user-attachments/assets/a160e00b-039d-4259-b1bd-aba777971560" />

# Smart Ventilation Controller

This is an Arduino-based embedded systems project that simulates a smart ventilation controller. The system compares indoor and outdoor temperatures and determines whether ventilation should be turned on. An LED simulates the ventilation on/off signal, responding to the controller's decision-making logic.

## Features

- Reads indoor temperature using a DHT11 temperature sensor
- Receives outdoor temperature through the Arduino Serial Monitor
- Validates user input before processing
- Detects sensor read failures
- Determines whether ventilation should be enabled
- Uses an LED to simulate the ventilation system
- Organized into separate C++ modules for maintainability

<img width="512" height="518" alt="Screenshot 2026-08-05 at 6 13 05 PM" src="https://github.com/user-attachments/assets/b6d944e6-6181-44dd-8675-ec7e0b1f20bd" />

## Hardware Components

- Arduino Uno
- Breadboard
- Jumper Wires
- 220Ω Resistor
- DHT11 Temperature Sensor
- LED

## Software Components

- Arduino IDE Software
- C++
- DHT Sensor Library

## Project Structure

```text
SmartVentilation/
│
├── SmartVentilation.ino    # Main application
├── Sensor.cpp/.h           # Initializes sensor object and reads indoor temperature
├── Input.cpp/.h            # Handles user input
├── Controller.cpp/.h       # Validates temperatures and controls ventilation
├── Output.cpp/.h           # Controls LED output
```

Each module is responsible for a one or two tasks, making the project easier to maintain and expand.

# How It Works

1. The Arduino reads the indoor temperature from the DHT11 sensor.
2. The user enters the outdoor temperature through the Serial Monitor.
3. The program validates both temperature values.
4. If the outdoor temperature is **lower than the indoor temperature,** ventilation is turned **ON**, so the **LED illuminates.**
5. Otherwise: Ventilation remains **OFF**, and the LED stays off.
6. The system displays the temperatures and ventilation status in the Serial Monitor.

# Example Output


<img width="510" height="565" alt="Screenshot 2026-08-05 at 6 16 15 PM" src="https://github.com/user-attachments/assets/d3af11de-6ed9-455a-9737-6b3e5caa2f17" />

# Design

The project follows a modular software architecture:

- **Sensor Module** – Interfaces with the DHT11 sensor
- **Input Module** – Reads and validates user input
- **Controller Module** – Implements the ventilation decision logic
- **Output Module** – Controls the simulated ventilation output
- **Main** – Coordinates all modules

Separating responsibilities into different modules helps with readability and maintainability.

# Error Handling

The program includes several validation features:

- Rejects invalid hardware pin initialization
- Rejects invalid user input
- Rejects unrealistic outdoor temperatures
- Detects failed sensor readings

## Testing

See TESTING.md for testing information.

## ESP32 / IoT Expansion

The original Arduino Uno project has been successfully moved to an ESP32.

Current work includes:
- ESP32 hardware
- Wi-Fi connectivity
- Serial-based Wi-Fi information input
- Web database development

The IoT portion of the project is currently in progress.

# Skills Demonstrated

- Embedded Systems
- Arduino Development
- C++
- Modular Software Design
- Sensor Interfacing
- Input Validation
- Error Handling

# Author

Hridhay Suswaram
