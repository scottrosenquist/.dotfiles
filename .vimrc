set nocompatible

filetype plugin on

set mouse=a

set number relativenumber

set splitright
set splitbelow

set tabstop=4 softtabstop=0 expandtab shiftwidth=2 smarttab

" Specify a directory for plugins
call plug#begin('~/.vim/plugged')

" Make sure you use single quotes
"" Plug 'git://github.com/wikitopian/hardmode.git'
Plug 'git://github.com/takac/vim-hardtime'
Plug 'git://github.com/sjl/vitality.vim.git'

" Initialize plugin system
call plug#end()

"" autocmd VimEnter,BufNewFile,BufReadPost * silent! call HardMode()
"" nnoremap <leader>h <Esc>:call ToggleHardMode()<CR>
let g:hardtime_default_on = 1
"" let g:hardtime_showmsg = 1
let g:hardtime_allow_different_key = 1

set autoread

augroup BgHighlight
  autocmd!
  autocmd VimEnter,WinEnter,BufWinEnter,FocusGained,CmdwinEnter * checktime
  autocmd VimEnter,WinEnter,BufWinEnter,FocusGained,CmdwinEnter * set cul
  autocmd VimEnter,WinEnter,BufWinEnter,FocusGained,CmdwinEnter * let &t_SI="\033[6 q" " start insert mode
  autocmd VimEnter,WinEnter,BufWinEnter,FocusGained,CmdwinEnter * let &t_EI="\033[2 q" " end insert mode
  autocmd WinLeave,FocusLost,CmdwinLeave * set nocul
augroup END

set directory=~/.vim/swap//
set backupdir=~/.vim/backup//
set undodir=~/.vim/undo//

set clipboard=unnamed

set ignorecase
set smartcase

autocmd VimResized * wincmd =

let g:vitality_tmux_can_focus = 1

set laststatus=2

set rtp+=$HOME/Library/Python/2.7/lib/python/site-packages/powerline/bindings/vim/
set noshowmode

set hlsearch

set incsearch

set timeoutlen=1000 ttimeoutlen=0

set scrolloff=5

set colorcolumn=80

map Y y$

set backspace=eol

:nnoremap <BS> <Nop>

set wildmenu
