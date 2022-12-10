@echo off
cls
for %%i in (01 02 03 04 05 06) do call %~dp0test_pos_as.bat %%i

for %%i in (07 08 09 10 11 12) do call %~dp0test_pos_des.bat %%i

for %%i in (01 02 03 04 05 06 07 08) do call %~dp0test_neg.bat %%i