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

" load .tmpl files as .html
autocmd BufNewFile,BufRead *.tmpl set filetype=html
