#!/bin/bash

# swig -csharp -c++ ../../../example.i -outdir ../../../csharp -outfile ../../../exampleCSHARP_wrap.cxx

mkdir -p ../../csharp
swig -outdir ../../csharp -csharp -c++ ../../example.i
