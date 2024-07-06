## Tech Stack

The project utilizes the following technologies:
- **Arduino**: Microcontroller platform for building digital devices.
- **Python**: Programming language used for writing the mouse control script.

## Libraries

The following libraries are used in this project:
- **Arduino Libraries**:
  - `Wire.h`: Used for I2C communication.
  - `ADXL335.h`: Library for interfacing with the ADXL335 accelerometer.
- **Python Libraries**:
  - `pyautogui`: Used for controlling the mouse cursor programmatically.
  - `serial`: For serial communication between Arduino and Python.

## Project Modules

The project is divided into the following modules:
1. **Arduino Code (`arduino_code.ino`)**:
   - Initializes the ADXL335 accelerometer.
   - Reads accelerometer data.
   - Sends data via serial communication to the Python script.

2. **Python Script (`mouse_code.py`)**:
   - Reads data from the serial port.
   - Processes the accelerometer data.
   - Uses `pyautogui` to move the mouse cursor based on the processed data.

## Getting Started

To get started with this project, follow these steps:
1. **Set up Arduino**:
   - Connect the ADXL335 accelerometer to the Arduino.
   - Upload the `arduino_code.ino` to the Arduino board.

2. **Set up Python Environment**:
   - Install the required Python libraries: `pyautogui` and `serial`.
   - Run the `mouse_code.py` script to start controlling the mouse.

## Usage

After setting up the hardware and software, you can use the accelerometer to control the mouse cursor by tilting the device in different directions.

## Contribution

Contributions are welcome! Please fork the repository and submit pull requests for any improvements or bug fixes.

## License

This project is licensed under the MIT License.
