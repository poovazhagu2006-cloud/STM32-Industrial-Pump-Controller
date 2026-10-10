# STM32-Industrial-Pump-Controller
STM32-based industrial pump controller with tank level,pressure monitoring,currrent monitoring and fault protection

1. Project Overview

The STM32-Based Industrial Pump Controller is designed to monitor tank level, pressure, and pump current. It controls pump operation based on the input conditions and provides fault indication during abnormal conditions.

2. Objectives

- To monitor tank level, pressure, and current inputs.
- To control pump operation based on the configured conditions.
- To provide fault indication during abnormal conditions.
- To demonstrate emergency-stop functionality.

3. Components Used

- STM32 Nucleo board
- Potentiometers for simulated sensor inputs
- LEDs for status and fault indication
- Relay control
- Wokwi online simulator

4. Software and Tools

- Wokwi Simulator
- Arduino-style programming environment, if applicable to the project configuration
- GitHub for source code storage and project documentation

5. Working Principle

The potentiometers simulate tank-level, pressure, and current sensor inputs. The STM32 controller reads these inputs and determines the pump status according to the programmed conditions. LEDs indicate the system status and fault conditions. The emergency-stop input is used to demonstrate emergency control.

6. Implementation

The project was developed and tested in the Wokwi simulation environment. The circuit connections and program code were configured to demonstrate pump control, status indication, and fault protection.

7. Project Files

- "sketch.ino" – Program source code
- "diagram.json" – Circuit diagram and component configuration
- "wokwi-project.txt" – Wokwi project information

8. Applications

- Industrial pump monitoring
- Tank-level control systems
- Pressure monitoring systems
- Basic equipment fault protection demonstrations

9. Conclusion

This project demonstrates the use of an STM32 controller for monitoring simulated industrial parameters, controlling pump operation, and indicating fault conditions.

10. Simulation

The project was developed using the Wokwi online simulator.

Wokwi Project Link: https://wokwi.com/projects/474934191596063745
