@echo off
color f0
title AvrDude GUI Command Window
@echo.
@echo. trying to connect to device...
avrdude -p ATMEGA8 -c usbasp -P COM1  -U flash:w:"D:\Testing & Inventorty\ATmega8\atmega8allportsopen\default\dep\robomart\default\robomart.hex":i
avrdudeGUI.exe -done
pause