#!/bin/bash

# swig -csharp -c++ ../../../ccl.i -outdir ../../../csharp -outfile ../../../cclCSHARP_wrap.cxx

mkdir -p ../../csharp
swig -outdir ../../csharp -csharp -c++ ../../ccl.i
