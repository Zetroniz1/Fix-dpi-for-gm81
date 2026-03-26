For using this dll in your GM81 game, you need to:

Download or compilate dll
Create object for dpi fix (Any name)

Create event "Game start"

Toggle object as "Persistent"

GML Code for game start:

global.func_fix_dpi = external_define(

    "fix_dpi.dll", 
    "fix_dpi_scaling", 
    dll_cdecl, 
    ty_real, 
    0
);
if (global.func_fix_dpi != -1) {
    external_call(global.func_fix_dpi);
} else {
    show_message("DLL File not found, check your directory! (fix_dpi.dll)");
}

GML Code for game end:

external_free("fix_dpi.dll");
