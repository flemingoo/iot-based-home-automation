# IoT-based-Home-Automation

In this project, a android application is used to monitor and control the home appliances.

Each room have node and each these nodes are connected to gateway node. The gateway node is created using Raspberrp Pi
and other nodes are implemented using LPC2148 microcontroller.

Each node have a temperature sensor, PIR sensor and LDR to keep track of the room status. The android application
have sensor threshold settings for each room. Depending on the threshold, the appliances are controlled automatically.
