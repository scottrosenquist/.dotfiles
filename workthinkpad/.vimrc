" Load default vimrc file
unlet! skip_defaults_vim
source $VIMRUNTIME/defaults.vim

" Make sure swap, backup, and undo files don't clutter up my directories
set directory=~/.vim/swap//
set backupdir=~/.vim/backup//
set undodir=~/.vim/undo//

" 2 spaces per tab
set tabstop=2

" 2 spaces per <<, >>, or autoindent
set shiftwidth=2

" Always use spaces and not tabs
set expandtab

" Always show status line
set laststatus=2

" Case insensitive searching
set ignorecase

" Case sensitive searching when a capital is included
set smartcase

" Enable the use of the mouse
if has('mouse')
  set mouse=a
endif

" Fix mouse support for urxvt
set ttymouse=urxvt

" Treat hyphens as part of words
set iskeyword+=-

" Treat dollarsigns as part of words
set iskeyword+=$

" Highlight all previous and current search patterns
if has('extra_search')
  set hlsearch
endif

" Auto open quickfix window
autocmd QuickFixCmdPost [^l]* cwindow

" Auto resize windows when host is resized
autocmd VimResized * wincmd =

" Use pencil colour theme [https://github.com/reedes/vim-colors-pencil]
let g:pencil_terminal_italics = 1
let g:pencil_neutral_headings = 1
colorscheme pencil

" Hide the netrw banner
let g:netrw_banner = 0

" Always show netrw in tree view
let g:netrw_liststyle = 3

" Show zero lines of context around the cursor.
set scrolloff=0

" Break lines on words
set linebreak

" Indent wrapped lines
set breakindent

" Show ↳ in broken lines
set showbreak=↳\ 

" Make buffer selection case insensitive
set fileignorecase

" Make wildignore case insensitive
set wildignorecase

" Reset wildignore
set wildignore&

" Exclude folders from VimGrep (and possibly other places)
set wildignore+=*/bower_components/*
set wildignore+=*/automation_framework/*
set wildignore+=*/frontend-assets/*
set wildignore+=*/spyc/*
set wildignore+=*/specs/*
set wildignore+=*/contrib/*
set wildignore+=*/build/*
set wildignore+=*/node_modules/*
set wildignore+=*/.tmp/*
set wildignore+=*/misc/*

" Exclude project root folders from VimGrep (and possibly other places)
set wildignore+=includes/*
set wildignore+=misc/*
" set wildignore+=modules/*
set wildignore+=profiles/*
set wildignore+=scripts/*
" set wildignore+=sites/*
" set wildignore+=themes/*

" Exclude file extensions from VimGrep (and possibly other places)
set wildignore+=*.inc
set wildignore+=*.svg
set wildignore+=*.png
set wildignore+=*.otf
set wildignore+=*.jpg
set wildignore+=*.ttf

" Exclude the tags file from VimGrep (and possibly other places)
set wildignore+=tags
