

# Sensor Multiplexer Interface for 14 Analog Sensors

The sensors are connected via a 4-bit addressing system, allowing the microcontroller to cycle through each sensor sequentially, read the values, and print the data to the serial monitor.

## Features

- Supports up to 14 analog sensors using REF-MUX for channel addressing.
- Adjustable MUX control pins to adapt to various hardware setups.

## Hardware Requirements

To use the provided code, you need the following hardware: 

- Arduino (any dev board or microcontroller that has Arduino IDE support) 
- 14 analog sensors
- REF-MUX
- Jumper wires and a breadboard for connections

### MUX Pin Configuration

Ensure that the following pins are connected correctly:

(You can use any digital pin for connecting with A, B, C ,D and any analog pin for Analog Input) 

| MUX Control Pin | Arduino Pin |
|-----------------|-------------|
| A               | Pin 5       |
| B               | Pin 4       |
| C               | Pin 3       |
| D               | Pin 2       |
| Analog Input    | A0          |

Note: The sensors must be connected in the correct sequence to match the channel addressing.

## Getting Started

### Prerequisites

- [Arduino IDE](https://www.arduino.cc/en/Main/Software) installed on your computer.
- Basic understanding of how multiplexers work.

### Setup

1. Connect your 14 sensors to the multiplexer and the analog input pin on the Arduino (A0).
2. Wire the MUX control pins (A, B, C, D) to digital pins 5, 4, 3, and 2 on the Arduino.
3. Upload the provided code to your Arduino using the Arduino IDE.

### Code Explanation

- channel_adress_table: Stores the 4-bit addresses for selecting each sensor.
- Mux_Addr: Sets the MUX control pins to select the corresponding sensor channel.
- loop: Continuously cycles through each of the 14 sensors, reads the analog values, and prints them to the serial monitor.

### Serial Output

The data from each sensor is printed to the serial monitor in a tab-separated format, making it easy to visualize and log the data.

Example output:
```
1023    1000    987     950     920     910     904     896     880     860     849     830     813     810
```

Each line corresponds to a full set of sensor readings.

## Usage

1. Connect your Arduino to your computer.
2. Open the Serial Monitor from the Arduino IDE (set the baud rate to `9600`).
3. View the sensor readings in real-time.

## Notes

- Adjust the delay in the `loop()` function to change the rate at which data is read.
- Ensure that the MUX connections and addressing table are configured correctly to avoid incorrect sensor readings.

## License

This project is open-source. Feel free to use, modify, and distribute the code as needed.




