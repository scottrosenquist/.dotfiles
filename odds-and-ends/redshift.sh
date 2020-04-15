#!/bin/sh

REDSHIFT_PID=$(pidof -s redshift)

if [ -n "$REDSHIFT_PID" ]; then
  #if [ "$(pgrep -x redshift)" ]; then
      temp=$(redshift -p 2> /dev/null | grep temp | cut -d ":" -f 2 | tr -dc "[:digit:]")

      if [ -n "$temp" ]; then
          echo $temp
      #else
          #echo "redshift not running"
      fi
  #fi
else
  #default value of a screen
  echo "6500"
fi
