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

Smart Ventilation Controller

Outside Temperature: 18.0 C
Inside Temperature: 24.3 C
Ventilation: ON

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

# Future Improvements

- Wi-Fi connectivity using an ESP32
- Push notifications when ventilation state changes
- Relay-controlled fan instead of LED simulation
- Data logging for expanded temperature analysis

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
