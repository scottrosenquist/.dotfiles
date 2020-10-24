#!/bin/sh
trackballid=$(xinput list | grep -Eo 'Kensington Expert Wireless TB Mouse\s*id\=[0-9]{1,2}' | grep -Eo '[0-9]{1,2}')
xinput set-prop $trackballid "Coordinate Transformation Matrix" 1 0 0 0 1 0 0 0 -1
xinput set-button-map $trackballid 2 3 8 4 5 6 7 1 9
xinput set-prop $trackballid "libinput Scroll Method Enabled" 0, 0, 1
xinput set-prop $trackballid "libinput Button Scrolling Button" 1
