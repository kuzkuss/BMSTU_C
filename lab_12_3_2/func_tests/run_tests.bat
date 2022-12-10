@echo off
cls
for %%i in (01 02 03 04) do call %~dp0test_pos.bat %%i

for %%i in (01 02) do call %~dp0test_neg.bat %%i
