@echo off
cls
del loader0.bin >nul
tasm -gb -b -85 loader0.asm loader0.bin >errors.txt
if errorlevel 1 goto err
type errors.txt
exit
:err
type errors.txt 
pause