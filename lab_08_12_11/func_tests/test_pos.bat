@echo off
%~dp0app.exe o %~dp0pos_%1_in1.txt %~dp0f_out.txt
fc %~dp0f_out.txt %~dp0pos_%1_out.txt
pause