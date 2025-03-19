@echo Off
del /s /a *.ncb *.so *.o *.d *.db *.dylib *.DS_Store
FOR /R . %%d IN (.) DO rd /s /q "%%d\Debug" 2>nul
FOR /R . %%d IN (.) DO rd /s /q "%%d\Release" 2>nul
FOR /R . %%d IN (.) DO rd /s /q "%%d\x64" 2>nul
FOR /R . %%d IN (.) DO rd /s /q "%%d\ARM64" 2>nul
FOR /R . %%d IN (.) DO rd /s /q "%%d\Debug" 2>nul
FOR /R . %%d IN (.) DO rd /s /q "%%d\ipch" 2>nul
FOR /R . %%d IN (.) DO rd /s /q "%%d\obj" 2>nul
FOR /R . %%d IN (.) DO rd /s /q "%%d\libs" 2>nul

rem If the Properties directory is empty, remove it
FOR /R . %%d in (.) do rd /q "%%d\Properties" 2> nul
