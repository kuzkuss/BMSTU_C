@echo off
python %~dp0app.py < %~dp0pos_%1_in.txt > %~dp0f_out.txt
fc %~dp0f_out.txt %~dp0pos_%1_out.txt
pause
