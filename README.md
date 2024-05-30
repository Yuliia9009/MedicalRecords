# Medical Records Management System

## Overview

The Medical Records Management System is a C++ application designed to manage patient medical records. It allows users to add new records, search for existing records by surname, and display all stored records. Records are stored in a text file, and the application ensures data validation, particularly for the date of birth format.

## Features

**Add Patient Records:** Capture and store patient details including full name, date of birth, phone number, diseases, and vaccinations.
**Search Patient Records: **Search for patient records by surname.
**Display All Records: **View all stored patient records.
**Data Validation: **Ensure correct date format (DD.MM.YYYY) for date of birth.

## Usage

**Add Patient:** Add a new patient record with details such as full name, date of birth, phone number, diseases, and vaccinations.
**Search by Surname: **Search for a patient record using the patient's surname.
**Show All Patients:** Display all the patient records stored in the system.
**Exit: **Exit the application.

## Example
```
Main Menu:
1. Search for a patient by surname
2. Show all patients
3. Add a patient
4. Exit
Enter your choice: 3
Enter patient's full name: John Doe
Enter patient's date of birth (format: DD.MM.YYYY): 15.04.1990
Enter patient's phone number: 123-456-7890
Enter patient's diseases: None
Enter patient's vaccinations: Influenza

Patient record saved successfully.

Main Menu:
1. Search for a patient by surname
2. Show all patients
3. Add a patient
4. Exit
Enter your choice: 2
All medical records:
Patient's full name: John Doe
Patient's date of birth: 15.04.1990
Patient's phone number: 123-456-7890
Patient's diseases: None
Patient's vaccinations: Influenza
****************************************************
Code Explanation
```

## Class: MedicalRecord
The MedicalRecord class encapsulates patient details including full name, date of birth, phone number, diseases, and vaccinations.

## Functions
- createMedicalRecord(std::ofstream& file): Prompts the user to input patient details and saves the record to the file.
- isValidDateFormat(const std::string& date): Validates the date format (DD.MM.YYYY).
- validateAndSavePatientRecord(std::ofstream& file, const std::string& fullName, const std::string& dateOfBirth, const std::string& phoneNumber, const std::string& diseases, const std::string& vaccinations): Validates and saves the patient record.
- searchMedicalRecord(const std::string& name, const std::string& dateOfBirth, std::ifstream& file): Searches for a patient record by surname.
- showAllMedicalRecords(std::ifstream& file): Displays all patient records.

# 

# Система Управления Медицинскими Записями

## Обзор

Система Управления Медицинскими Записями — это приложение на C++, предназначенное для управления медицинскими записями пациентов. Оно позволяет пользователям добавлять новые записи, искать существующие записи по фамилии и отображать все сохраненные записи. Записи хранятся в текстовом файле, и приложение обеспечивает проверку данных, особенно для формата даты рождения.

## Функциональные возможности

**Добавление записей о пациентах:** Сбор и хранение данных о пациенте, включая полное имя, дату рождения, номер телефона, болезни и прививки.
**Поиск записей о пациентах: **Поиск записей о пациентах по фамилии.
**Отображение всех записей: **Просмотр всех сохраненных записей о пациентах.
**Проверка данных:** Обеспечение правильного формата даты (ДД.ММ.ГГГГ) для даты рождения.

## Использование
- **Добавление пациента: **Добавление новой записи о пациенте с данными, такими как полное имя, дата рождения, номер телефона, болезни и прививки.
- **Поиск по фамилии: **Поиск записи о пациенте по фамилии.
- **Показать всех пациентов:** Отображение всех записей о пациентах, сохраненных в системе.
- **Выход:** Выход из приложения.

## Пример

```
Главное меню:
1. Поиск пациента по фамилии
2. Показать всех пациентов
3. Добавить пациента
4. Выход
Введите ваш выбор: 3
Введите полное имя пациента: Иванов Иван
Введите дату рождения пациента (формат: ДД.ММ.ГГГГ): 15.04.1990
Введите номер телефона пациента: 123-456-7890
Введите болезни пациента: Нет
Введите прививки пациента: Грипп

Запись о пациенте успешно сохранена.

Главное меню:
1. Поиск пациента по фамилии
2. Показать всех пациентов
3. Добавить пациента
4. Выход
Введите ваш выбор: 2
Все медицинские записи:
Полное имя пациента: Иванов Иван
Дата рождения пациента: 15.04.1990
Номер телефона пациента: 123-456-7890
Болезни пациента: Нет
Прививки пациента: Грипп
****************************************************
Объяснение кода
```

## Класс: MedicalRecord
Класс MedicalRecord инкапсулирует данные о пациенте, включая полное имя, дату рождения, номер телефона, болезни и прививки.

## Функции
- createMedicalRecord(std::ofstream& file): Запрашивает у пользователя данные о пациенте и сохраняет запись в файл.
- isValidDateFormat(const std::string& date): Проверяет формат даты (ДД.ММ.ГГГГ).
- validateAndSavePatientRecord(std::ofstream& file, const std::string& fullName, const std::string& dateOfBirth, const std::string& phoneNumber, const std::string& diseases, const std::string& vaccinations): Проверяет и сохраняет запись о пациенте.
- searchMedicalRecord(const std::string& name, const std::string& dateOfBirth, std::ifstream& file): Ищет запись о пациенте по фамилии.
- showAllMedicalRecords(std::ifstream& file): Отображает все записи о пациентах.
