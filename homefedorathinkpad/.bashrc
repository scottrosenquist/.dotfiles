# .bashrc

# Source global definitions
if [ -f /etc/bashrc ]; then
	. /etc/bashrc
fi

# User specific environment
if ! [[ "$PATH" =~ "$HOME/.local/bin:$HOME/bin:" ]]
then
    PATH="$HOME/.local/bin:$HOME/bin:$PATH"
fi
export PATH

# Uncomment the following line if you don't like systemctl's auto-paging feature:
# export SYSTEMD_PAGER=

# User specific aliases and functions
alias vi='vimx'
alias vim='vimx'
alias displayportonly='xrandr --output LVDS-1 --off --output DP-1 --mode 1920x1080'
alias laptoponly='xrandr --output DP-1 --off --output LVDS-1 --mode 1600x900'
alias journal='sh ~/journal/.journal'
alias godocker='cd ~/work/wlw-docker/'
alias gosource='cd ~/work/wlw-docker/docker/wlw/source/'
alias gocode='cd ~/work/wlw-docker/docker/wlw/source/sites/all/'

# Add my scripts to my path
export PATH=~/.scripts:$PATH
# Add Android platform-tools to my path
export PATH=~/Android/Sdk/platform-tools:$PATH

export NVM_DIR="$HOME/.nvm"
[ -s "$NVM_DIR/nvm.sh" ] && \. "$NVM_DIR/nvm.sh"  # This loads nvm
[ -s "$NVM_DIR/bash_completion" ] && \. "$NVM_DIR/bash_completion"  # This loads nvm bash_completion
