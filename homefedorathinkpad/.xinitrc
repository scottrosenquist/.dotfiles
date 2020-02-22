# load .Xresources
xrdb ~/.Xresources

# Allow Android Studio to launch
export _JAVA_AWT_WM_NONREPARENTING=1

# turn off laptop monitor and turn on displayport
# (need a better solution for this)
# xrandr --output LVDS-1 --off --output DP-1 --mode 1920x1080 &

# xmodmap ~/.Xmodmap

eval $(ssh-agent)

# set background colour
xsetroot -solid "#f1f1f1"

# load dunst
dunst &

# load redshift
redshift &

# run bspwm
exec bspwm
