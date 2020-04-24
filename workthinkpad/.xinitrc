systemctl --user import-environment DISPLAY
autorandr -c
#xrandr --dpi 144
#urxvt &
xrdb ~/.Xresources

#xmodmap ~/.Xmodmap
#map escape to caps lock
#setxkbmap -option caps:escape
setxkbmap -option
#disable trackpad
#xinput --disable 11
~/.scripts/disable-trackpad
#set background colour
xsetroot -solid '#f1f1f1'
# set left pointer cursor on background
xsetroot -cursor_name left_ptr
##hsetroot -solid '#f1f1f1'
eval $(ssh-agent)
##HOME/.config/polybar/polybar.sh &
##redshift &
#dunst &
flameshot &
# compton &
# exec i3
# exec bspwm
# exec urxvt
