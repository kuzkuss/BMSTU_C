@echo off
set /p choice="pos - 1 neg - 0: "

if %choice% EQU 1 (goto :pos) else (goto :neg)

:neg
set /p count="input count of negative tests: "

for /L %%i in (1, 1, %count%) DO (
if %%i LSS 10 (echo >> neg_0%%i_args.txt) ELSE (echo >> neg_%%i_args.txt)
)
echo Tests was created
pause
goto :end

:pos
set /p count="input count of positive tests: "
for /L %%i in (1, 1, %count%) DO (
if %%i LSS 10 (echo >> pos_0%%i_args.txt) ELSE (echo >> pos_%%i_args.txt)
)
echo Tests was created
pause
end: