import serial
import pyautogui
import time

# Establish serial connection (adjust COM port and baud rate as necessary)
ser = serial.Serial('COM3', 9600)
time.sleep(2)  # Wait for the serial connection to initialize

def move_mouse(x, y):
    # Get the current mouse position
    current_x, current_y = pyautogui.position()
    # Move the mouse relative to the current position
    pyautogui.moveTo(current_x + x, current_y - y)

while True:
    if ser.in_waiting > 0:
        data = ser.readline().decode('utf-8').strip()
        parts = data.split(',')
        if len(parts) >= 4:
            try:
                x = int(parts[0])
                y = int(parts[1])
                left = int(parts[2])
                right = int(parts[3])

                move_mouse(x, y)

                # Implement mouse click based on button states
                if left == 1 and right == 1:
                    pyautogui.click(button='left')
                    pyautogui.click(button='right')
                elif left == 1:
                    pyautogui.click(button='left')
                elif right == 1:
                    pyautogui.click(button='right')

            except ValueError:
                pass  # Handle the case where the conversion to int fails

        time.sleep(0.1)
