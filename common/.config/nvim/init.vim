" 2 spaces per tab
set tabstop=2

" 2 spaces per <<, >>, or autoindent
set shiftwidth=2

" Always use spaces and not tabs
set expandtab

" Case insensitive searching
set ignorecase

" Case sensitive searching when a capital is included
set smartcase

" Enable the use of the mouse
set mouse=a

" Treat hyphens as part of words
set iskeyword+=-

" Treat dollarsigns as part of words
set iskeyword+=$

" Auto open quickfix window
autocmd QuickFixCmdPost [^l]* cwindow

" Auto open locationlist window
autocmd QuickFixCmdPost l* lwindow

" Auto resize windows when host is resized
autocmd VimResized * wincmd =

" Use pencil colour theme [https://github.com/reedes/vim-colors-pencil]
let g:pencil_terminal_italics = 1
let g:pencil_neutral_headings = 1
set background=light
colorscheme pencil

" Hide the netrw banner
let g:netrw_banner = 0

" Always show netrw in tree view
let g:netrw_liststyle = 3

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

" Function to source only if file exists
function! SourceIfExists(file)
  if filereadable(expand(a:file))
    exe 'source' a:file
  endif
endfunction

" Source coc.init.vim
call SourceIfExists("~/.config/nvim/coc.init.vim")

" Source mercatus.init.vim
call SourceIfExists("~/.config/nvim/mercatus.init.vim")
