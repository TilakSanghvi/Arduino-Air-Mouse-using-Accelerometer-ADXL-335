#define BUTTON_PIN 2
#define LEFT_PIN 5
#define RIGHT_PIN 6
#include <math.h>

const int x_out = A1;
const int y_out = A2;
const int z_out = A3;

void setup()
{
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LEFT_PIN, INPUT_PULLUP);
  pinMode(RIGHT_PIN, INPUT_PULLUP);
}

void loop()
{ 
  int buttonState = digitalRead(BUTTON_PIN);
  int leftState = digitalRead(LEFT_PIN);
  int rightState = digitalRead(RIGHT_PIN);

  int x_adc, y_adc, z_adc;
  double x_g, y_g, z_g;
  double roll, pitch;

  x_adc = analogRead(x_out);
  y_adc = analogRead(y_out);
  z_adc = analogRead(z_out);

  x_g = ((((double)(x_adc * 5) / 1024) - 1.65) / 0.330);
  y_g = ((((double)(y_adc * 5) / 1024) - 1.65) / 0.330);
  z_g = ((((double)(z_adc * 5) / 1024) - 1.65) / 0.330);

  roll = (((atan2(y_g, z_g) * 180) / M_PI) + 180);
  pitch = (((atan2(-x_g, sqrt(sq(y_g) + sq(z_g))) * 180) / M_PI) + 180);

  int x = map(roll, 74.00, 280.0, -80.0, 80.0);
  int y = map(pitch, 100.0, 265.0, -80.0, 80.0);

  if (buttonState == LOW)
  {
    Serial.print(x);
    Serial.print(",");
    Serial.print(y);
    Serial.print(",");
    if (leftState == LOW)
      Serial.print(1);
    else
      Serial.print(0);

    Serial.print(",");
    if (rightState == LOW)
      Serial.println(1);
    else
      Serial.println(0);
  }
  else
  {
    if (leftState == LOW && rightState == LOW)
      Serial.println("0,0,1,1");
    else if (leftState == HIGH && rightState == LOW)
      Serial.println("0,0,0,1");
    else if (leftState == LOW && rightState == HIGH)
      Serial.println("0,0,1,0");
  }
  delay(100);
}
