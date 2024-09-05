/* animal.i file */
%module AnimalModule
%include <std_string.i>
%include <typemaps.i>

%{
    #include "animal.h"
%}

%include "animal.h"
