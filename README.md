# C++ OOP Transport Management System

## Overview

This project demonstrates the use of **object-oriented programming in C++** with a focus on:

* inheritance and polymorphism,
* dynamic memory management using `std::unique_ptr`,
* input validation,
* modular project structure.

The application implements a console-based **transport management system** that allows creating, storing, displaying, and validating different types of vehicles.

---

## Key Features

* Abstract base class with virtual methods
* Inheritance hierarchy for transport types
* Runtime polymorphism via base-class pointers
* Safe memory management (`std::unique_ptr`)
* Strong input validation and error handling
* File input/output support
* Simple test execution for core functionality

---

## Architecture

### Base Class

`Transport` is an abstract base class defining common properties:

* weight
* engine power
* maximum speed

It enforces a common interface via pure virtual methods.

### Derived Classes

* `Car` — standard passenger vehicle
* `SportsCar` — high-performance vehicle
* `Truck` — cargo transport vehicle

Each derived class:

* extends base attributes,
* applies its own validation rules,
* overrides virtual methods.

---

## Technologies & Skills Demonstrated

* **C++ (C++17)**
* Object-Oriented Programming (OOP)
* Inheritance and polymorphism
* RAII and smart pointers
* STL containers
* Modular code organization
* Console-based UI
* File I/O

---

## Build & Run

### Compile

```bash
g++ src/*.cpp -std=c++17 -O2 -o transport_system
```

### Run

```bash
./transport_system
```

---

## Example Functionality

* Create vehicles manually via console input
* Load vehicle data from file
* Display stored vehicles
* Clear and recreate transport list
* Run validation and system tests

---

## Why This Project

This project was created as a learning exercise to practice **core C++ concepts** used in real-world development:

* clean class hierarchies,
* safe memory management,
* extensible architecture.

It reflects an understanding of modern C++ principles rather than framework-specific solutions.

---

## Author

**Artem Sokolov**

