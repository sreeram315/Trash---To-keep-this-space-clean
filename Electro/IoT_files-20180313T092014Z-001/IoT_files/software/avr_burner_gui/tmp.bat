@echo off
color f0
title AvrDude GUI Command Window
@echo.
@echo. trying to connect to device...
avrdude -p ATMEGA16 -c usbasp -P COM1  -U flash:w:"C:\Users\Sanjana Reddy\Desktop\IoT_files-20180313T092014Z-001\IoT_files\Examples\USART_TEXT\USART_TEXT\Debug\USART_TEXT.hex":i
avrdudeGUI.exe -done
pause