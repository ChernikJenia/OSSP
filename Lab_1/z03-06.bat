@echo off
chcp 1251>nul

echo -- ������ ����������: %1 %2
echo -- �����: %1
echo -- ��� �����: %2

@REM ����� ������� 
if "%1" == "" if "%2" == "" (
    echo ---+ %0 ����� ����
    echo ---++ ����� = {�������, �������}
    echo ---++ ���� = ��� �����
    goto end
)

if not "%1" == "�������" if not "%1" == "�������" (
    echo ---+ ����� ����� �����������
    goto end
)

if "%1" == "�������" (
    if exist %2 (
        del %2
        echo ---+ ���� %2 �����
    ) else (
        echo ---+ ���� %2 �� ������
    )
    goto end
)

if "%1" == "�������" (
    if not exist %2 (
        type nul > %2
        echo ---+ ���� %2 ������
    ) else (
        echo ---+ ���� %2 ��� ����
    )
)

:end

