# gt: Go to top of current git repo
alias gt='cd "$(git rev-parse --show-toplevel)"'

alias ctop='ctop -i'

## alias tm='tmux new-session -A -s main'

export CLICOLOR=1

export JAVA_HOME=/Applications/Android\ Studio.app/Contents/jre/jdk/Contents/Home
export PATH=${JAVA_HOME}/bin:$PATH

export ANDROID_HOME=/Users/$USER/Library/Android/sdk
export PATH=${PATH}:$ANDROID_HOME/tools:$ANDROID_HOME/platform-tools

export PATH=$PATH:/opt/gradle/gradle-4.9/bin

export NVM_DIR="$HOME/.nvm"
[ -s "$NVM_DIR/nvm.sh" ] && \. "$NVM_DIR/nvm.sh"  # This loads nvm
[ -s "$NVM_DIR/bash_completion" ] && \. "$NVM_DIR/bash_completion"  # This loads nvm bash_completion

export PATH=$PATH:/Users/$USER/Library/Python/2.7/bin

export PATH=$HOME/.composer/vendor/bin:$PATH

# if [ -f ~/Library/Python/2.7/lib/python/site-packages/powerline/bindings/bash/powerline.sh ]; then
#     source ~/Library/Python/2.7/lib/python/site-packages/powerline/bindings/bash/powerline.sh
# fi

export PATH=$PATH:~/code/Mobile/mobile-automation

export PATH="$(composer config -g home)/vendor/bin:$PATH"

source ~/.git-completion.bash

source ~/.pureline/pureline/pureline ~/.pureline.conf

if [ -z "$TMUX" ]; then
    # Make sure there is a 'main' session
    tmux has -t main || tmux new -d -s main
    
    # Calculate the number of the next session
    session_name="main-$(tmux ls -F '#S' | grep main | wc -l | sed 's/^[ ]*//')"
    
    # Create the new window
    new="new -d -t main -s $session_name"
    
    # Tell this window to die when we leave
    die="set-option destroy-unattached on"
    
    # Join the new and configured window
    att="attach -t $session_name"
    
    # Run those commands
    tmux $new \; $die \; $att
fi

export PATH="/usr/local/opt/mysql@5.7/bin:$PATH"
