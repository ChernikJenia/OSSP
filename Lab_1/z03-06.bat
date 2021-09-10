@echo off
chcp 1251>nul

echo -- строка параметров: %1 %2
echo -- режим: %1
echo -- имя файла: %2

@REM вывод справки 
if "%1" == "" if "%2" == "" (
    echo ---+ %0 режим файл
    echo ---++ режим = {создать, удалить}
    echo ---++ файл = имя файла
    goto end
)

if not "%1" == "удалить" if not "%1" == "создать" (
    echo ---+ режим задан некорректно
    goto end
)

if "%1" == "удалить" (
    if exist %2 (
        del %2
        echo ---+ файл %2 удалён
    ) else (
        echo ---+ файл %2 не найден
    )
    goto end
)

if "%1" == "создать" (
    if not exist %2 (
        type nul > %2
        echo ---+ файл %2 создан
    ) else (
        echo ---+ файл %2 уже есть
    )
)

:end

