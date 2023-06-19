let SessionLoad = 1
let s:so_save = &g:so | let s:siso_save = &g:siso | setg so=0 siso=0 | setl so=-1 siso=-1
let v:this_session=expand("<sfile>:p")
silent only
silent tabonly
cd ~/Programming/Cpp/Tel-Hai/igor/project_3_cpp
if expand('%') == '' && !&modified && line('$') <= 1 && getline(1) == ''
  let s:wipebuf = bufnr('%')
endif
let s:shortmess_save = &shortmess
if &shortmess =~ 'A'
  set shortmess=aoOA
else
  set shortmess=aoO
endif
badd +0 Agent.h
badd +0 Geometry.h
badd +0 Model.h
badd +17 Sim_object.h
badd +0 Structure.h
badd +0 View.h
badd +5 Knight.h
badd +7 Peasant.h
badd +0 Thug.h
badd +0 Castle.h
badd +1 Sim_object.cpp
badd +0 Farm.h
argglobal
%argdel
$argadd Agent.h
$argadd Geometry.h
$argadd Model.h
$argadd Sim_object.h
$argadd Structure.h
$argadd View.h
set stal=2
tabnew +setlocal\ bufhidden=wipe
tabnew +setlocal\ bufhidden=wipe
tabnew +setlocal\ bufhidden=wipe
tabnew +setlocal\ bufhidden=wipe
tabnew +setlocal\ bufhidden=wipe
tabnew +setlocal\ bufhidden=wipe
tabrewind
edit Agent.h
argglobal
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let &fdl = &fdl
let s:l = 26 - ((25 * winheight(0) + 37) / 75)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 26
normal! 030|
tabnext
edit Thug.h
argglobal
if bufexists(fnamemodify("Thug.h", ":p")) | buffer Thug.h | else | edit Thug.h | endif
if &buftype ==# 'terminal'
  silent file Thug.h
endif
balt Peasant.h
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let &fdl = &fdl
let s:l = 3 - ((2 * winheight(0) + 37) / 75)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 3
normal! 018|
tabnext
edit Knight.h
argglobal
if bufexists(fnamemodify("Knight.h", ":p")) | buffer Knight.h | else | edit Knight.h | endif
if &buftype ==# 'terminal'
  silent file Knight.h
endif
balt Thug.h
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let &fdl = &fdl
let s:l = 3 - ((2 * winheight(0) + 22) / 45)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 3
normal! 0
tabnext
edit Peasant.h
argglobal
if bufexists(fnamemodify("Peasant.h", ":p")) | buffer Peasant.h | else | edit Peasant.h | endif
if &buftype ==# 'terminal'
  silent file Peasant.h
endif
balt Knight.h
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let &fdl = &fdl
let s:l = 4 - ((3 * winheight(0) + 22) / 45)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 4
normal! 0
tabnext
edit Castle.h
argglobal
if bufexists(fnamemodify("Castle.h", ":p")) | buffer Castle.h | else | edit Castle.h | endif
if &buftype ==# 'terminal'
  silent file Castle.h
endif
balt Peasant.h
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let &fdl = &fdl
let s:l = 10 - ((9 * winheight(0) + 22) / 45)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 10
normal! 039|
tabnext
edit Farm.h
argglobal
if bufexists(fnamemodify("Farm.h", ":p")) | buffer Farm.h | else | edit Farm.h | endif
if &buftype ==# 'terminal'
  silent file Farm.h
endif
balt Castle.h
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let &fdl = &fdl
let s:l = 11 - ((10 * winheight(0) + 22) / 45)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 11
normal! 031|
tabnext
edit Sim_object.h
argglobal
if bufexists(fnamemodify("Sim_object.h", ":p")) | buffer Sim_object.h | else | edit Sim_object.h | endif
if &buftype ==# 'terminal'
  silent file Sim_object.h
endif
balt Castle.h
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let &fdl = &fdl
let s:l = 17 - ((16 * winheight(0) + 22) / 45)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 17
normal! 016|
tabnext 6
set stal=1
if exists('s:wipebuf') && len(win_findbuf(s:wipebuf)) == 0 && getbufvar(s:wipebuf, '&buftype') isnot# 'terminal'
  silent exe 'bwipe ' . s:wipebuf
endif
unlet! s:wipebuf
set winheight=1 winwidth=20
let &shortmess = s:shortmess_save
let s:sx = expand("<sfile>:p:r")."x.vim"
if filereadable(s:sx)
  exe "source " . fnameescape(s:sx)
endif
let &g:so = s:so_save | let &g:siso = s:siso_save
set hlsearch
nohlsearch
doautoall SessionLoadPost
unlet SessionLoad
" vim: set ft=vim :
