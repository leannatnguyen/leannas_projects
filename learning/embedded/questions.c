/*
Certainly! Embedded software development often involves dealing with hardware interfaces, real-time constraints, and low-level programming. Here are some practice coding questions that are relevant to embedded systems:

### Question 1: Implement a Circular Buffer (Ring Buffer)

**Description:**
Implement a circular buffer for storing integers. Your buffer should support the following operations:
- `init(buffer_size)`: Initializes the buffer with a given size.
- `enqueue(value)`: Adds a value to the buffer. Returns `false` if the buffer is full, otherwise returns `true`.
- `dequeue()`: Removes and returns the oldest value from the buffer. Returns `-1` if the buffer is empty.
- `is_full()`: Checks if the buffer is full.
- `is_empty()`: Checks if the buffer is empty.

**Example:**
```c
CircularBuffer buffer;
init(&buffer, 5);
enqueue(&buffer, 1);
enqueue(&buffer, 2);
enqueue(&buffer, 3);
dequeue(&buffer); // returns 1
enqueue(&buffer, 4);
enqueue(&buffer, 5);
enqueue(&buffer, 6); // returns false, buffer is full
```

### Question 2: Debouncing a Button

**Description:**
Write a function to debounce a button connected to a microcontroller pin. The function should read the button state multiple times (e.g., 10 times) and return `true` if the button is consistently pressed, and `false` otherwise.

**Example:**
```c
#define BUTTON_PIN 3

bool debounce_button(int pin) {
    int pressed_count = 0;
    for (int i = 0; i < 10; i++) {
        if (read_pin(pin) == HIGH) { // Assume read_pin() is a function that reads the pin state
            pressed_count++;
        }
        delay(10); // Assume delay() is a function that waits for a given number of milliseconds
    }
    return pressed_count > 7;
}
```

### Question 3: Implementing a State Machine

**Description:**
Implement a state machine for a simple traffic light controller. The traffic light has three states: `RED`, `GREEN`, and `YELLOW`. The light transitions between states as follows:
- `RED` -> `GREEN` after 10 seconds.
- `GREEN` -> `YELLOW` after 15 seconds.
- `YELLOW` -> `RED` after 3 seconds.

**Example:**
```c
typedef enum { RED, GREEN, YELLOW } TrafficLightState;

void traffic_light_controller() {
    TrafficLightState state = RED;
    while (1) {
        switch (state) {
            case RED:
                set_light(RED); // Assume set_light() sets the light color
                delay(10000);
                state = GREEN;
                break;
            case GREEN:
                set_light(GREEN);
                delay(15000);
                state = YELLOW;
                break;
            case YELLOW:
                set_light(YELLOW);
                delay(3000);
                state = RED;
                break;
        }
    }
}
```

### Question 4: ADC Data Processing

**Description:**
You are given an array of ADC (Analog-to-Digital Converter) readings from a sensor. Implement a function to calculate the average reading, ignoring the highest and lowest 5% of the readings to remove outliers.

**Example:**
```c
#include <stdlib.h>

double average_adc_readings(int* readings, int size) {
    qsort(readings, size, sizeof(int), compare); // Assume compare() is a comparison function for qsort
    int ignore_count = size * 0.05;
    int sum = 0;
    for (int i = ignore_count; i < size - ignore_count; i++) {
        sum += readings[i];
    }
    return (double)sum / (size - 2 * ignore_count);
}
```

### Question 5: I2C Communication

**Description:**
Implement functions to read and write data to a device over the I2C bus. Assume the following functions are provided by the platform:
- `i2c_start()`: Starts an I2C transaction.
- `i2c_stop()`: Stops an I2C transaction.
- `i2c_write_byte(byte)`: Writes a byte over I2C.
- `i2c_read_byte()`: Reads a byte from I2C.

**Example:**
```c
void i2c_write_data(uint8_t device_address, uint8_t register_address, uint8_t data) {
    i2c_start();
    i2c_write_byte(device_address);
    i2c_write_byte(register_address);
    i2c_write_byte(data);
    i2c_stop();
}

uint8_t i2c_read_data(uint8_t device_address, uint8_t register_address) {
    uint8_t data;
    i2c_start();
    i2c_write_byte(device_address);
    i2c_write_byte(register_address);
    i2c_start(); // Repeated start for reading
    i2c_write_byte(device_address | 0x01); // Set the read bit
    data = i2c_read_byte();
    i2c_stop();
    return data;
}
```

These questions cover a variety of fundamental topics in embedded systems, such as memory management, real-time programming, interfacing with peripherals, and handling hardware constraints.
*/