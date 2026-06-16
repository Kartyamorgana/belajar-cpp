# 📚 C++ Learning Curriculum for Robotics & AI

> **Note:** All sub-chapters are studied in order.  
> **Tinkercad** will be used starting from **Module 11**.  
> Each applicable sub-chapter will include a **fun coding mini project** 🎮

---

## Table of Contents
- [Module 1: Introduction to C++ and Working Environment](#module-1-introduction-to-c-and-working-environment)
- [Module 2: Variables and Basic Data Types](#module-2-variables-and-basic-data-types)
- [Module 3: Operators and Expressions](#module-3-operators-and-expressions)
- [Module 4: Decision Making (Control Flow)](#module-4-decision-making-control-flow)
- [Module 5: Loops](#module-5-loops)
- [Module 6: Functions](#module-6-functions)
- [Module 7: Arrays and Advanced Strings](#module-7-arrays-and-advanced-strings)
- [Module 8: Pointers and References](#module-8-pointers-and-references)
- [Module 9: Structs](#module-9-structs)
- [Module 10: Introduction to Object-Oriented Programming (OOP)](#module-10-introduction-to-object-oriented-programming-oop)
- [Module 11: Entering the World of Arduino & Tinkercad](#module-11-entering-the-world-of-arduino--tinkercad)
- [Module 12: Digital I/O on Arduino](#module-12-digital-io-on-arduino)
- [Module 13: Analog I/O and PWM](#module-13-analog-io-and-pwm)
- [Module 14: Basic Sensors and Actuators](#module-14-basic-sensors-and-actuators-in-tinkercad)
- [Module 15: Serial Communication for Debugging and Control](#module-15-serial-communication-for-debugging-and-control)
- [Module 16: Integrating OOP with Arduino](#module-16-integrating-oop-with-arduino)
- [Module 17: Introduction to Robotics Logic & Simple AI](#module-17-introduction-to-robotics-logic--simple-ai)
- [Module 18: Reading and Writing Data to a Computer](#module-18-reading-and-writing-data-to-a-computer)
- [Module 19: Mid-Level Project – Obstacle Avoidance Robot Simulation](#module-19-mid-level-project--obstacle-avoidance-robot-simulation)
- [Module 20: Final Project (Portfolio) – Smart Parking System](#module-20-final-project-portfolio--smart-parking-system)

---

### Module 1: Introduction to C++ and Working Environment
- **1a:** What is C++ and why is it used in robotics? (analogy: C++ is the language that microcontrollers understand)
- **1b:** Installing a compiler (g++) and a text editor / IDE (recommended: Code::Blocks or VS Code + terminal) — very detailed steps
- **1c:** First program: "Hello, World!" — basic C++ program structure (`main`, `#include <iostream>`, `std::cout`)
- **1d:** How to compile and run a program via terminal (without deep diving into linker/preprocessor)
- **1e:** Comments in code and the importance of documentation

### Module 2: Variables and Basic Data Types
- **2a:** Concept of variables as labeled storage boxes
- **2b:** Integer (`int`) and floating-point (`float`, `double`) data types — declaration & initialization
- **2c:** Character (`char`) and boolean (`bool`) data types
- **2d:** String type (`std::string`) from `<string>` — brief comparison with C-strings
- **2e:** Constants (`const`) and variable naming rules
- **2f:** User input with `std::cin`

### Module 3: Operators and Expressions
- **3a:** Arithmetic operators (`+`, `-`, `*`, `/`, `%`) — calculator analogy
- **3b:** Assignment operators (`=`, `+=`, `-=`, etc.)
- **3c:** Relational (comparison) operators (`==`, `!=`, `<`, `>`, `<=`, `>=`)
- **3d:** Logical operators (`&&`, `||`, `!`) for decision making
- **3e:** Increment/decrement operators (`++`, `--`) and postfix vs prefix (concise)
- **3f:** Implicit and explicit type casting
- **3g:** Operator precedence and the use of parentheses

### Module 4: Decision Making (Control Flow)
- **4a:** `if` structure — analogy: “if it rains, bring an umbrella”
- **4b:** `if-else` and nested `if`
- **4c:** `else if` for multiple conditions
- **4d:** Ternary operator (`?:`) as a compact `if-else`
- **4e:** `switch-case` structure (when to use it)

### Module 5: Loops
- **5a:** Looping concept — why a robot needs to repeat actions
- **5b:** `for` loop — syntax, counter variable, example: printing numbers
- **5c:** `while` loop — as long as the condition is true
- **5d:** `do-while` loop — executed at least once
- **5e:** Loop control: `break` and `continue`
- **5f:** Nested loops — example: creating star patterns

### Module 6: Functions
- **6a:** Function concept: a recipe that can be called repeatedly
- **6b:** Function declaration and definition — return type, name, parameters
- **6c:** Void functions (no return value)
- **6d:** Parameters and arguments — pass by value
- **6e:** Variable scope (global vs local)
- **6f:** Function overloading (same name, different parameters) — introduction
- **6g:** Basic recursion — a function calling itself (example: factorial, careful with base case)

### Module 7: Arrays and Advanced Strings
- **7a:** Why arrays? — numbered locker analogy
- **7b:** Declaring and initializing 1D arrays, index starts at 0
- **7c:** Looping through an array with `for`
- **7d:** Multidimensional arrays (2D) — sensor data table
- **7e:** C-style strings (array of char) vs `std::string` — basic operations: length, concatenation, character access
- **7f:** Reversing a string, finding a character, substring (basic `std::string` methods)

### Module 8: Pointers and References
- **8a:** Memory addresses and the `&` operator — what is a variable’s address?
- **8b:** Pointer declaration, dereference operator `*` — house address vs house contents analogy
- **8c:** Pointers and arrays — close relationship
- **8d:** Pass by reference using references (`&`) — avoiding large data copies
- **8e:** Pointers as function parameters (pass by pointer)
- **8f:** Dynamic memory allocation: `new` and `delete` — core idea, focus on “why” for robotics

### Module 9: Structs
- **9a:** Wrapping multiple variables into one struct (analogy: ID card containing name, address, age)
- **9b:** Defining a struct, creating struct variables, accessing members
- **9c:** Array of structs — storing multiple sensor data
- **9d:** Nested structs (struct within a struct) — overview
- **9e:** Passing structs to functions (by value, by reference)

### Module 10: Introduction to Object-Oriented Programming (OOP)
- **10a:** OOP paradigm — analogy: car blueprint vs real car
- **10b:** Class and Object — class definition, creating instances
- **10c:** Access specifiers: `public` and `private` — encapsulation
- **10d:** Constructor — automatic function when an object is born
- **10e:** Methods (member functions) — setters and getters
- **10f:** Destructor — brief cleanup overview
- **10g:** Inheritance — “BaseRobot” class derived into “WalkingRobot”
- **10h:** Basic polymorphism — virtual functions (overview for understanding)

### Module 11: Entering the World of Arduino & Tinkercad
- **11a:** What is a microcontroller? (mini brain of a robot) — analogy with a mini computer
- **11b:** Getting to know Arduino Uno: digital pins, analog pins, power — diagram
- **11c:** Installing Arduino IDE and selecting the board
- **11d:** Creating a Tinkercad account and starting a virtual circuit
- **11e:** Arduino program structure: `setup()` and `loop()`
- **11f:** First Arduino program: blinking the built-in LED (no external components) — Tinkercad simulation

### Module 12: Digital I/O on Arduino
- **12a:** `pinMode`, `digitalWrite`, `digitalRead` — controlling pins
- **12b:** Lighting an external LED with a resistor (simulation)
- **12c:** Reading a push button — pull-up input logic
- **12d:** Mini project: LED lights up only when the button is pressed (simulation)

### Module 13: Analog I/O and PWM
- **13a:** Analog vs digital signals — volume analogy
- **13b:** `analogRead` — reading a potentiometer (simulation)
- **13c:** `analogWrite` and PWM — fading an LED
- **13d:** Mini project: Control LED brightness with a potentiometer

### Module 14: Basic Sensors and Actuators in Tinkercad
- **14a:** HC-SR04 ultrasonic sensor — how it works (simulation)
- **14b:** Reading distance with an ultrasonic sensor and displaying on Serial Monitor
- **14c:** LM35 temperature sensor — converting analog value to temperature
- **14d:** Driving a DC motor with L293D driver (simulation)
- **14e:** Servo motor — angle control with the Servo library
- **14f:** Mini project: Digital thermometer (LM35 + 16x2 LCD) — displaying temperature on a virtual screen

### Module 15: Serial Communication for Debugging and Control
- **15a:** `Serial.begin`, `Serial.print`, `Serial.println` — sending data to a PC
- **15b:** `Serial.read` and data parsing — receiving commands from Serial Monitor
- **15c:** Mini project: Control an LED via text commands (“ON”/”OFF”) from Serial Monitor

### Module 16: Integrating OOP with Arduino
- **16a:** Creating a class for an LED — hiding pin and methods
- **16b:** Creating a class for an Ultrasonic Sensor
- **16c:** Splitting code into header (`.h`) and implementation (`.cpp`) files — overview
- **16d:** Mini project: Build your own library for a DC motor and use it in the main program

### Module 17: Introduction to Robotics Logic & Simple AI
- **17a:** Line follower robot concept — reading line sensors
- **17b:** Sensor-based decision making (nested if-else)
- **17c:** Simple state machine — example: robot with states “forward”, “backward”, “stop”
- **17d:** 2-sensor line follower robot simulation in Tinkercad

### Module 18: Reading and Writing Data to a Computer
- **18a:** Basic `fstream`: `ofstream`, `ifstream` — writing sensor log to a text file
- **18b:** Reading a CSV file (manual parsing) in C++
- **18c:** Offline simulation: a pure C++ program that simulates sensor data reading and saves it to a file

### Module 19: Mid-Level Project – Obstacle Avoidance Robot Simulation
- **19a:** Program architecture: read distance sensor, control motors
- **19b:** Algorithm: if distance < 30 cm, move backward and turn
- **19c:** Step-by-step implementation in Tinkercad, debugging via Serial Monitor
- **19d:** Add a danger indicator LED

### Module 20: Final Project (Portfolio) – Smart Parking System
A major project carried out with guided step-by-step instructions.  
**“Smart Parking System” in Tinkercad** — a mini parking lot simulation featuring:
- Ultrasonic sensors to detect cars
- Displaying available slots on an LCD
- Opening/closing an automatic gate (servo)

All logic is written in **Arduino C++**, applying OOP, arrays, serial debugging, and state machines.  
This project only uses concepts from Modules 1–19.