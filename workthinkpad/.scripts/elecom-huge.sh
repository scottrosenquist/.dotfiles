#!/bin/sh
trackballid=$(xinput list | grep -Eom 1 'ELECOM TrackBall Mouse HUGE TrackBall\s*id\=[0-9]{1,2}' | grep -Eo '[0-9]{1,2}')
xinput set-button-map $trackballid 9 8 3 4 5 6 7 2 1 10 11 12
xinput set-prop $trackballid "libinput Scroll Method Enabled" 0, 0, 1
xinput set-prop $trackballid "libinput Button Scrolling Button" 8
xinput set-prop $trackballid "libinput Natural Scrolling Enabled" 1
