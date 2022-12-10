@echo off
%~dp0app.exe a %~dp0neg_%1_in1.txt %~dp0neg_%1_in2.txt %~dp0f_out.txt > %~dp0f_out.txt
fc %~dp0f_out.txt %~dp0neg_%1_out.txt
pause